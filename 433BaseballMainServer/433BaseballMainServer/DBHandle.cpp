#include "stdafx.h"

CDBHandle::CDBHandle()
:stateMachine(this)
{
	dbConnection = NULL;

	proactor = NULL;

	connector = NULL;
	disconnector = NULL;
	querier = NULL;
	harvester = NULL;

	sqlResult = NULL;

	dbQuery = "";

	stateMachine.SetCurrentState(CDBClosed::Instance());
}

CDBHandle::~CDBHandle()
{
	// DB Closing
	mysql_close(dbConnection);
}

bool CDBHandle::Initializer(const std::string &dbHostParam, const std::string &dbUserParam,
	const std::string &dbPasswdParam, const std::string &dbSchemaParam)
{
	dbHost = dbHostParam;
	dbUser = dbUserParam;
	dbPasswd = dbPasswdParam;
	dbSchema = dbSchemaParam;

	CDBManager &dbManager = *CGlobalManager::GetInstance().dbManager;

	if (!dbManager.ConnectEx(this))
	{
		MYPRINTF("Error on ConnectEx in Initializer of CDBHandle");
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