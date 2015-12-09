#include "stdafx.h"

CDBConnector::CDBConnector()
{
}

CDBConnector::~CDBConnector()
{
}

bool CDBConnector::EventProc(CAct *act, DWORD receivedBytes)
{
	CDBAct *dbAct = (CDBAct*)act;

	CDBHandle &dbHandle = *(CDBHandle*)dbAct->dbHandle;

	CDBManager &dbManager = *CGlobalManager::GetInstance().dbManager;

	//--------------------------------------

	// DB initializing
	mysql_init(&dbHandle.connTmp);
	
	// DB connecting
	dbHandle.dbConnection = mysql_real_connect(&dbHandle.connTmp, dbHandle.dbHost.c_str(), dbHandle.dbUser.c_str()
		, dbHandle.dbPasswd.c_str(), dbHandle.dbSchema.c_str(), DB_PORT, (char *)NULL, 0);

	if (NULL == dbHandle.dbConnection)
	{
		MYPRINTF("error on mysql_real_connect in CDBManager Constructor : %s\n", mysql_error());
		return false;
	}

	//--------------------------------------

	dbHandle.stateMachine.ChangeState(CDBIdle::Instance());

	return true;
}

bool CDBConnector::ErrorProc(CAct *act, DWORD error)
{

	return true;
}

bool CDBConnector::Initializer(CProactor *proactor)
{

	return true;
}