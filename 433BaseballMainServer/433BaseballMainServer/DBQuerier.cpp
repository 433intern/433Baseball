#include "stdafx.h"

CDBQuerier::CDBQuerier()
{
}

CDBQuerier::~CDBQuerier()
{
}

bool CDBQuerier::EventProc(CAct *act, DWORD receivedBytes)
{
	CGlobalManager &globalManager = CGlobalManager::GetInstance();

	CDBAct *dbAct = (CDBAct*)act;

	CDBManager &dbManager = *globalManager.dbManager;

	CDBHandle *dbHandle = dbAct->dbHandle;

	MYSQL *realDBHandle = dbHandle->dbConnection;

	//--------------------------------------

	if (NULL == realDBHandle)
	{
		MYPRINTF("Error on Query of CDBManager : Not connected to DB.\n");
		return false;
	}

	if (mysql_query(realDBHandle, dbHandle->queryStr.c_str()))
	{
		MYPRINTF("DB Query \"%s\"error : %s\n", str, mysql_error());
		return false;
	}

	//--------------------------------------

	dbManager.HarvestEx(dbHandle);

	dbHandle->stateMachine.ChangeState(CDBWaitResult::Instance());

	return true;
}

bool CDBQuerier::ErrorProc(CAct *act, DWORD error)
{
	MYPRINTF("Error on QueryEx of CDBManager!\n");

	return true;
}

bool CDBQuerier::Initializer(CProactor *proactor)
{

	return true;
}