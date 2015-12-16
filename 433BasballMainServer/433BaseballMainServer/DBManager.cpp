#include "stdafx.h"

CDBManager &CDBManager::GetInstance()
{
	static CDBManager dbManager;
	return dbManager;
}

CDBManager::~CDBManager()
{
	while (dbHandles.size() > 0)
	{
		CDBHandle *tmpHandle = dbHandles.front();
		mysql_close(tmpHandle->dbConnection);
		dbHandles.pop();
		delete tmpHandle;
	}

	mysql_library_end();

	CloseHandle(dbHandleSema);
}

bool CDBManager::FirstInitializer(const std::string &hostAddress, const std::string &userName,
	const std::string &userPassword, const std::string &schemaName)
{
	dbHost = hostAddress;
	dbUser = userName;
	dbPasswd = userPassword;
	dbSchema = schemaName;

	threadPoolSize = 0;
	handlePoolSize = 0;

	dbHandleSema = NULL;

	return true;
}

bool CDBManager::SecondInitializer(const int &threadNumParam, const int &handleNumParam)
{
	threadPoolSize = threadNumParam;

	//----------------------------------------------------------

	if (!proactor.Initializer(threadPoolSize))
	{
		MYERRORPRINTF("Error on Initializer functino of proactor in Initializer of CDBManager : %d\n", WSAGetLastError());
		return false;
	}

	connector.Initializer();
	disconnector.Initializer();
	querier.Initializer();
	harvester.Initializer();

	//----------------------------------------------------------

	if (mysql_library_init(0, NULL, NULL))
	{
		MYERRORPRINTF("Error on mysql_library_init in Initializer of CDBManager : %s\n", mysql_error());
		return false;
	}

	if (!CreateDBHandlePool(handleNumParam))
	{
		MYERRORPRINTF("CreateDBHandlePool");
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

bool CDBManager::CreateDBHandlePool(const int &handleNumParam)
{
	CDBHandle *tmpDbHandle;

	dbHandleSema = CreateSemaphore(NULL, handleNumParam, handleNumParam, L"433_DB_Sema");
	if (NULL == dbHandleSema)
	{
		MYERRORPRINTF("CreateSemaphore");
		return false;
	}

	for (int k = 0; k < handleNumParam; ++k)
	{
		tmpDbHandle = new CDBHandle();

		if (!tmpDbHandle->InitActs(&proactor, &connector, &disconnector, &querier, &harvester))
		{
			MYERRORPRINTF("InitActs");
			return false;
		}

		if (!tmpDbHandle->Initializer(dbHost, dbUser, dbPasswd, dbSchema))
		{
			MYERRORPRINTF("The Initializer of %d th DB Handle", k);
			return false;
		}

		dbHandles.push(tmpDbHandle);
	}
	return true;
}

// You must call the ReleaseHandle function after you have used the handle off !
CDBHandle *CDBManager::GetAvailableHandle()
{
	CDBHandle *choosedDBHandle = NULL;

	DWORD result = WaitForSingleObject(dbHandleSema, WAIT_AVAILABLE_HANDLE_TIME);

	if (WAIT_FAILED == result)
	{
		MYERRORPRINTF("WaitForSingleObject");
		return false;
	}
	else if (WAIT_TIMEOUT == result)
	{
		MYPRINTF("There is no available DB handle !\n");
		return NULL;
	}
	else if (WAIT_OBJECT_0 == result)
	{
		choosedDBHandle = dbHandles.front();
		dbHandles.pop();

		if (NULL == choosedDBHandle)
		{
			MYPRINTF("The DB handles' queue is empty !\n");
			return NULL;
		}

		if (CDBIdle::Instance() == choosedDBHandle->stateMachine.CurrentState())
		{
			return choosedDBHandle;
		}

		MYERRORPRINTF("The available handle's state is not the idle state !\n");
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
		MYERRORPRINTF("ReleaseSemaphore");
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

	dbHandle->queryStr = str;
	CDBAct *tmpAct = &dbHandle->acts[CDBHandle::DB_ACK_TYPE::QUERY];
	tmpAct->dbHandle = dbHandle;

	if (NULL == tmpAct)
	{
		MYPRINTF("The act of handle in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(tmpAct));

	return true;
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
	tmpAct->dbHandle = param;

	if (NULL == tmpAct)
	{
		MYPRINTF("The act of parameter in HarvestEx of CDBManager is NULL!\n");
		return false;
	}

	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(tmpAct));

	return true;
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
	tmpAct->dbHandle = param;

	if (NULL == tmpAct)
	{
		MYPRINTF("The act of parameter in ConnectEx of CDBManager is NULL!\n");
		return false;
	}

	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(tmpAct));

	return true;
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
	tmpAct->dbHandle = param;

	if (NULL == tmpAct)
	{
		MYPRINTF("The act of parameter in DisconnectEx of CDBManager is NULL!\n");
		return false;
	}

	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(tmpAct));

	return true;
}