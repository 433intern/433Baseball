#include "stdafx.h"

CDBManager::CDBManager()
:dbHost("127.0.0.1"), dbUser("root"), dbPasswd("570104"), dbSchema("player_statics")
{
}

CDBManager::~CDBManager()
{
	// DB Closing
	mysql_close(dbConnection);
}

bool CDBManager::Initializer(const int &threadNum)
{
	HANDLE dbHandle = NULL;
	MYSQL_ROW sqlRow;
	int queryStat;

	dbConnection = NULL;

	// DB initializing
	mysql_init(&connTmp);

	// DB connecting
	dbConnection = mysql_real_connect(&connTmp, dbHost.c_str(), dbUser.c_str()
		, dbPasswd.c_str(), dbSchema.c_str(), 3306, (char *)NULL, 0);
	if (NULL == dbConnection)
	{
		MYPRINTF("error on mysql_real_connect in CDBManager Constructor : %d\n", GetLastError());
		return false;
	}

	// For using Korean
	mysql_query(dbConnection, "set session character_set_connection=euckr;");
	mysql_query(dbConnection, "set session character_set_results=euckr;");
	mysql_query(dbConnection, "set session character_set_client=euckr;");

	// Quering !!
	//char *query = "CREATE TABLE test(id INT, label CHAR(1))";
	//queryStat = mysql_query(dbConnection, query);

	// Printing the result
	/*sqlResult = mysql_store_result(connection);
	while ((sqlRow = mysql_fetch_row(sqlResult)) != NULL)
	{
	printf("%2s %2s %s\n", sqlRow[0], sqlRow[1], sqlRow[2]);
	}
	mysql_free_result(sqlResult);*/

	if (!proactor.Initializer(dbHandle, threadNum))
		return false;

	return true;
}
