#include "stdafx.h"

CDBManager::CDBManager(const std::string &hostAddress, const std::string &userName, 
	const std::string &userPassword, const std::string &schemaName)
:dbHost(hostAddress), dbUser(userName), dbPasswd(userPassword), dbSchema(schemaName)
{
	threadPoolSize = 0;
	handlePoolSize = 0;

	availableDBHandles = 0;
}

CDBManager::~CDBManager()
{
	while(dbHandles.size() > 0)
		dbHandles.pop();

	mysql_library_end();
}

bool CDBManager::Initializer(const int &threadNumParam, const int &handleNumParam)
{
	MYSQL_ROW sqlRow;
	int queryStat;

	threadPoolSize = threadNumParam;
	availableDBHandles = handlePoolSize = handleNumParam;

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

	for (int k = 0; k < handleNumParam; ++k)
	{
		tmpDbHandle = new CDBHandle();

		if (!tmpDbHandle->Initializer(connTmp, dbHost, dbUser, dbPasswd, dbSchema))
		{
			MYPRINTF("%dth DB Handle Initializing has been canceled by an error : %s\n", mysql_error());
			return false;
		}

		if (!tmpDbHandle->InitActs(&proactor, &connector, &disconnector, &querier, &harvester))
		{
			MYPRINTF("Error on InitActs of CDBHandle in Initializer of CDBManager : %s\n", mysql_error());
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

	if (0 < availableDBHandles)
	{
		if (NULL != choosedDBHandle)
		{
			choosedDBHandle = dbHandles.front();
			dbHandles.pop();

			if (choosedDBHandle->isAvailable)
			{
				--availableDBHandles;

				if (0 > availableDBHandles)
				{
					MYPRINTF("Error on GetAvailableHandle : availableDBHandles is smaller than zero !\n");
					return NULL;
				}

				choosedDBHandle->isAvailable = false;
				return choosedDBHandle;
			}

			MYPRINTF("Between the number of availableHandles and the front handle's isAvailable are not matching !\n");
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

	if (param->isAvailable)
	{
		MYPRINTF("Error : The DB Handle is already available !\n");
		return false;
	}

	param->isAvailable = true;

	++availableDBHandles;

	dbHandles.push(param);

	if (availableDBHandles != dbHandles.size())
	{
		MYPRINTF("Error on ReleaseHandle : availableDBHandles is not equal to the size of dbHandles.\n");
		return false;
	}
	
	if (availableDBHandles > handlePoolSize)
	{
		MYPRINTF("Error : The number of available DB Handles are exceeded over the DB handle pool size.\n");
		availableDBHandles = handlePoolSize;
		return false;
	}

	return true;
}

bool CDBManager::QueryEx(const char *str, CDBAct *act)
{
	if (NULL == str)
	{
		MYPRINTF("The string pointer of parameter in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	if (NULL == act)
	{
		MYPRINTF("The act of parameter in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	if (typeid(act) != typeid(CDBQuerier))
	{
		MYPRINTF("The act is not CDBQuerier's act !\n");
		return false;
	}
	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(act));
}

bool CDBManager::HarvestEx(CDBAct *act)
{
	if (NULL == act)
	{
		MYPRINTF("The act of parameter in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	if (typeid(act) != typeid(CDBQuerier))
	{
		MYPRINTF("The act is not CDBHarvester's act !\n");
		return false;
	}
	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(act));
}

bool CDBManager::ConnectEx(CDBHandle *handle, CDBAct *act)
{
	if (NULL == handle)
	{
		MYPRINTF("The DBHandle of parameter in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	if (NULL == act)
	{
		MYPRINTF("The act of parameter in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	if (typeid(act) != typeid(CDBQuerier))
	{
		MYPRINTF("The act is not CDBConnector's act !\n");
		return false;
	}
	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(act));
}

bool CDBManager::DisconnectEx(CDBHandle *handle, CDBAct *act)
{
	if (NULL == handle)
	{
		MYPRINTF("The DBHandle of parameter in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	if (NULL == act)
	{
		MYPRINTF("The act of parameter in QueryEx of CDBManager is NULL!\n");
		return false;
	}

	if (typeid(act) != typeid(CDBQuerier))
	{
		MYPRINTF("The act is not CDisconnector's act !\n");
		return false;
	}
	PostQueuedCompletionStatus(proactor.iocp, NULL, NULL, static_cast<OVERLAPPED*>(act));
}