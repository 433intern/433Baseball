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

	CDBManager &dbManager = CDBManager::GetInstance();

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
		MYERRORPRINTF("mysql_query");
		return false;
	}

	//--------------------------------------

	dbHandle->stateMachine.ChangeState(CDBIdle::Instance());

	//dbManager.HarvestEx(dbHandle);

	return true;
}

bool CDBQuerier::ErrorProc(CAct *act, DWORD error)
{
	MYERRORPRINTF("ErrorPorc");

	return true;
}

bool CDBQuerier::Initializer()
{
	return true;
}