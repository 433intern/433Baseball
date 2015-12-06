#include "stdafx.h"

CDBHandle::CDBHandle(HANDLE *dbSemaParam)
:isAvailable(true)
{
	dbSema = dbSemaParam;
	dbConnection = NULL;
}

CDBHandle::~CDBHandle()
{
	// DB Closing
	mysql_close(dbConnection);
}

bool CDBHandle::Query(const char *str)
{
	if (NULL == dbConnection)
	{
		MYPRINTF("Error on Query of CDBManager : Not connected to DB.\n");
		return false;
	}
	if (mysql_query(dbConnection, str))
	{
		MYPRINTF("DB Query \"%s\"error : %s\n", str, mysql_error());
		return false;
	}
	return true;
}

bool CDBHandle::Initializer(MYSQL &connTmp, const std::string &dbHost, const std::string &dbUser,
	const std::string &dbPasswd, const std::string &dbSchema)
{
	// DB connecting
	dbConnection = mysql_real_connect(&connTmp, dbHost.c_str(), dbUser.c_str()
		, dbPasswd.c_str(), dbSchema.c_str(), DB_PORT, (char *)NULL, 0);

	if (NULL == dbConnection)
	{
		MYPRINTF("error on mysql_real_connect in CDBManager Constructor : %s\n", mysql_error());
		return false;
	}

	return true;
}