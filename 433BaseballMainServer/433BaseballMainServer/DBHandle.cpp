#include "stdafx.h"

CDBHandle::CDBHandle()
:isAvailable(true)
{
	dbConnection = NULL;

	proactor = NULL;

	connector = NULL;
	disconnector = NULL;
	querier = NULL;
	harvester = NULL;

	sqlResult = NULL;

	dbQuery = "";
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

bool CDBHandle::InitActs(CProactor *proactorParam, CDBConnector *connectorParam, CDBDisconnector *disconnectorParam,
	CDBQuerier *querierParam, CDBHarvester *harvesterParam)
{
	proactor = proactorParam;
	
	connector = connectorParam;
	disconnector = disconnectorParam;
	querier = querierParam;
	harvester = harvesterParam;

	if (!acts[CONNECT].Initializer(connector, this))
	{
		MYPRINTF("Error on Initializer of CDBAct in InitActs of CDBHandle : acts[CONNECT]\n");
		return false;
	}

	if (!acts[DISCONNECT].Initializer(disconnector, this))
	{
		MYPRINTF("Error on Initializer of CDBAct in InitActs of CDBHandle : acts[DISCONNECT]\n");
		return false;
	}

	if (!acts[QUERY].Initializer(querier, this))
	{
		MYPRINTF("Error on Initializer of CDBAct in InitActs of CDBHandle : acts[QUERY]\n");
		return false;
	}

	if (!acts[HARVEST].Initializer(harvester, this))
	{
		MYPRINTF("Error on Initializer of CDBAct in InitActs of CDBHandle : acts[HARVEST]\n");
		return false;
	}

	return true;
}

MYSQL_RES *CDBHandle::Harvest()
{
	MYSQL_RES *tmpResult = NULL;

	return tmpResult;
}