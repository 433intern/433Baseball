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

	CDBManager &dbManager = CDBManager::GetInstance();

	if (!dbManager.ConnectEx(this))
	{
		MYERRORPRINTF("ConnectEx");
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
		MYERRORPRINTF("Initializer of acts[CONNECT]");
		return false;
	}

	if (!acts[DISCONNECT].Initializer(disconnector, this))
	{
		MYERRORPRINTF("Initializer of acts[DISCONNECT]");
		return false;
	}

	if (!acts[QUERY].Initializer(querier, this))
	{
		MYERRORPRINTF("Initializer of acts[QUERY]");
		return false;
	}

	if (!acts[HARVEST].Initializer(harvester, this))
	{
		MYERRORPRINTF("Initializer of acts[HARVEST]");
		return false;
	}

	return true;
}