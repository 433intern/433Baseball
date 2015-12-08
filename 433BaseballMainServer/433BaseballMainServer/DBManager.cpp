#include "stdafx.h"

CDBManager::CDBManager(const std::string &hostAddress, const std::string &userName, 
	const std::string &userPassword, const std::string &schemaName)
:dbHost(hostAddress), dbUser(userName), dbPasswd(userPassword), dbSchema(schemaName)
{
	threadPoolSize = 0;
	handlePoolSize = 0;

	dbHandleSema = NULL;
}

CDBManager::~CDBManager()
{
	while(dbHandles.size() > 0)
		dbHandles.pop();

	mysql_library_end();

	CloseHandle(dbHandleSema);
}

bool CDBManager::Initializer(const int &threadNumParam, const int &handleNumParam)
{
	MYSQL_ROW sqlRow;
	int queryStat;

	threadPoolSize = threadNumParam;

	//----------------------------------------------------------

	if (!proactor.Initializer(threadPoolSize))
	{
		MYPRINTF("Error on Initializer functino of proactor in Initializer of CDBManager : %d\n", WSAGetLastError());
		return false;
	}

	connector.Initializer(&proactor);
	disconnector.Initializer(&proactor);
	querier.Initializer(&proactor);
	harvester.Initializer(&proactor);

	//----------------------------------------------------------

	if (mysql_library_init(0, NULL, NULL))
	{
		MYPRINTF("Error on mysql_library_init in Initializer of CDBManager : %s\n", mysql_error());
		return false;
	}

	// DB initializing
	mysql_init(&connTmp);

	CDBHandle *tmpDbHandle;

	dbHandleSema = CreateSemaphore(NULL, handleNumParam, handleNumParam, L"433_DB_Sema");
	if (NULL == dbHandleSema)
	{
		MYPRINTF("Error on CreateSemaphore in Initializer of CDBManager : %u\n", GetLastError());
		return false;
	}

	for (int k = 0; k < handleNumParam; ++k)
	{
		tmpDbHandle = new CDBHandle();

		if (!tmpDbHandle->InitActs(&proactor, &connector, &disconnector, &querier, &harvester))
		{
			MYPRINTF("Error on InitActs of CDBHandle in Initializer of CDBManager : %s\n", mysql_error());
			return false;
		}

		if (!tmpDbHandle->Initializer(connTmp, dbHost, dbUser, dbPasswd, dbSchema))
		{
			MYPRINTF("%dth DB Handle Initializing has been canceled by an error : %s\n", mysql_error());
			return false;
		}

		dbHandles.push(tmpDbHandle);
	}

	// For using Korean
	/*Query("set session character_set_connection=euckr;");
	Query("set session character_set_results=euckr;");
	Query("set session character_set_client=euckr;");*/

	// Printing the result
	/*sqlResult = mysql_store_result(connection);
	while ((sqlRow = mysql_fetch_row(sqlResult)) != NULL)
	{
	printf("%2s %2s %s\n", sqlRow[0], sqlRow[1], sqlRow[2]);
	}
	mysql_free_result(sqlResult);*/

	return true;
}

// You must call the ReleaseHandle function after you have used the handle off !
CDBHandle *CDBManager::GetAvailableHandle()
{
	CDBHandle *choosedDBHandle = NULL;

	DWORD result = WaitForSingleObject(dbHandleSema, WAIT_AVAILABLE_HANDLE_TIME);

	if (WAIT_FAILED == result)
	{
		MYPRINTF("Error on WaitForSingleObject in GetAvailableHandle of CDBManager : %u\n", GetLastError());
		return false;
	}
	else if (WAIT_TIMEOUT == result)
	{
		MYPRINTF("There is no available DB handle !\n");
		return NULL;
	}
	else if (WAIT_OBJECT_0 == result)
	{
		if (NULL != choosedDBHandle)
		{
			choosedDBHandle = dbHandles.front();
			dbHandles.pop();

			if (CDBIdle::Instance() == choosedDBHandle->stateMachine.CurrentState())
			{
				return choosedDBHandle;
			}

			MYPRINTF("The available handle's state is not the idle state !\n");
			return NULL;
		}
		MYPRINTF("Temporary pointer is not NULL in GetAvailableHandle !\n");
		return NULL;
	}

	MYPRINTF("There isn't any DBHandle !\n");
	return NULL;
}

bool CDBManager::ReleaseHandle(CDBHandle *param)
{
	if (NULL == param)
	{
		MYPRINTF("Error : The parameter of ReleaseHandle is NULL !\n");
		return false;
	}

	if (CDBIdle::Instance() == param->stateMachine.CurrentState())
	{
		MYPRINTF("Error : The DB Handle is already available !\n");
		return false;
	}
	else if (CDBClosed::Instance() == param->stateMachine.CurrentState())
	{
		MYPRINTF("Error : The DB Handle has been closed !\n");
		return false;
	}

	param->stateMachine.ChangeState(CDBIdle::Instance());

	if (!ReleaseSemaphore(dbHandleSema, 1, NULL))
	{
		MYPRINTF("Error on ReleaseSemaphore in Enter function of CDBIdle : %u\n", GetLastError());
		return false;
	}

	dbHandles.push(param);

	return true;
}

bool CDBManager::QueryEx(const char *str)
{
	if (NULL == str)
	{
		MYPRINTF("The string pointer of parameter in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	CDBHandle *dbHandle = GetAvailableHandle();

	if (NULL == dbHandle)
	{
		MYPRINTF("There isn't even a handle which can deal with your query !!!\n");
		return false;
	}

	CDBAct *tmpAct = &dbHandle->acts[CDBHandle::DB_ACK_TYPE::QUERY];

	if (NULL == tmpAct)
	{
		MYPRINTF("The act of handle in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	if (typeid(*tmpAct) != typeid(CDBQuerier))
	{
		MYPRINTF("The act is not CDBQuerier's act !\n");
		return false;
	}

	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(tmpAct));
}

bool CDBManager::HarvestEx(CDBHandle *param)
{
	if (NULL == param)
	{
		MYPRINTF("The DBHandle of parameter in HarvestEx of CDBManager is NULL!\n");
		return false;
	}

	if (CDBWaitResult::Instance() != param->stateMachine.CurrentState())
	{
		MYPRINTF("If you wish to use this HarvestEx function, this DB handle must be in the WaitResult state\n");
		return false;
	}

	CDBAct *tmpAct = &param->acts[CDBHandle::DB_ACK_TYPE::HARVEST];

	if (NULL == tmpAct)
	{
		MYPRINTF("The act of parameter in HarvestEx of CDBManager is NULL!\n");
		return false;
	}

	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(tmpAct));
}

bool CDBManager::ConnectEx(CDBHandle *param)
{
	if (NULL == param)
	{
		MYPRINTF("The DBHandle of parameter in ConnectEx of CDBManager is NULL!\n");
		return false;
	}

	if (CDBClosed::Instance() != param->stateMachine.CurrentState())
	{
		MYPRINTF("If you wish to use this ConnectEx function, this DB handle must be in the closed state\n");
		return false;
	}

	CDBAct *tmpAct = &param->acts[CDBHandle::DB_ACK_TYPE::CONNECT];

	if (NULL == tmpAct)
	{
		MYPRINTF("The act of parameter in ConnectEx of CDBManager is NULL!\n");
		return false;
	}

	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(tmpAct));
}

bool CDBManager::DisconnectEx(CDBHandle *param)
{
	if (NULL == param)
	{
		MYPRINTF("The DBHandle of parameter in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	if (CDBIdle::Instance() != param->stateMachine.CurrentState())
	{
		MYPRINTF("If you wish to use this DisconnectEx function, this DB handle must be in the idle state\n");
		return false;
	}

	CDBAct *tmpAct = &param->acts[CDBHandle::DB_ACK_TYPE::DISCONNECT];

	if (NULL == tmpAct)
	{
		MYPRINTF("The act of parameter in DisconnectEx of CDBManager is NULL!\n");
		return false;
	}

	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(tmpAct));
}