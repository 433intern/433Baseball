#include "stdafx.h"

CDBManager::CDBManager(const std::string &hostAddress, const std::string &userName, 
	const std::string &userPassword, const std::string &schemaName)
:dbHost(hostAddress), dbUser(userName), dbPasswd(userPassword), dbSchema(schemaName)
{
	
	sqlResult = NULL;

	threadPoolSize = 0;
	handlePoolSize = 0;

	dbHandleSemaphore = NULL;
}

CDBManager::~CDBManager()
{
	dbHandles.clear();

	mysql_library_end();
}

bool CDBManager::Initializer(const int &threadNumParam, const int &handleNumParam)
{
	MYSQL_ROW sqlRow;
	int queryStat;

	threadPoolSize = threadNumParam;
	handlePoolSize = handleNumParam;

	//----------------------------------------------------------

	if (!proactor.Initializer(threadPoolSize))
	{
		MYPRINTF("Error on Initializer functino of proactor in Initializer of CDBManager : %d\n", WSAGetLastError());
		return false;
	}

	//----------------------------------------------------------

	if (mysql_library_init(0, NULL, NULL))
	{
		MYPRINTF("Error on mysql_library_init in Initializer of CDBManager : %s\n", mysql_error());
		return false;
	}

	// DB initializing
	mysql_init(&connTmp);

	dbHandleSemaphore = CreateSemaphore(NULL, handleNumParam, handleNumParam, L"433Baseball_DBSemaphore");
	if (NULL == dbHandleSemaphore)
	{
		MYPRINTF("error on CreateSemaphore in initializer of DBManager : %d", GetLastError());
		return false;
	}

	CDBHandle *tmpDbHandle;
	dbHandles.reserve(handleNumParam);
	for (int k = 0; k < handleNumParam; ++k)
	{
		tmpDbHandle = new CDBHandle(&dbHandleSemaphore);

		if (!tmpDbHandle->Initializer(connTmp, dbHost, dbUser, dbPasswd, dbSchema))
		{
			MYPRINTF("%dth DB Handle Initializing has been canceled by an error : %s\n", mysql_error());
			return false;
		}

		dbHandles.push_back(tmpDbHandle);
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

