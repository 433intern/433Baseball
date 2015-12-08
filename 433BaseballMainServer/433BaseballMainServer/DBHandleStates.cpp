#include "stdafx.h"

CDBClosed* CDBClosed::Instance()
{
	static CDBClosed instance;

	return &instance;
}

void CDBClosed::Enter(CDBHandle *dbHandle)
{
	if (NULL == dbHandle)
	{
		MYPRINTF("Error : CDBHandle pointer parameter is NULL in Enter of CDBClosed !\n");
	}

	dbHandle->dbConnection = NULL;

	dbHandle->dbHost = "";
	dbHandle->dbPasswd = "";
	dbHandle->dbQuery = "";
	dbHandle->dbSchema = "";
}

void CDBClosed::Exit(CDBHandle *dbHandle)
{
}

void CDBClosed::Execute(CDBHandle *dbHandle)
{
}

//------------------------------------------

CDBIdle* CDBIdle::Instance()
{
	static CDBIdle instance;

	return &instance;
}

void CDBIdle::Enter(CDBHandle *dbHandle)
{
}

void CDBIdle::Exit(CDBHandle *dbHandle)
{
}

void CDBIdle::Execute(CDBHandle *dbHandle)
{
}

//------------------------------------------

CDBWaitResult* CDBWaitResult::Instance()
{
	static CDBWaitResult instance;

	return &instance;
}

void CDBWaitResult::Enter(CDBHandle *dbHandle)
{
}

void CDBWaitResult::Exit(CDBHandle *dbHandle)
{
	CDBManager &dbManager = *CGlobalManager::GetInstance().dbManager;

	if (NULL == dbHandle)
	{
		MYPRINTF("Error : CDBHandle pointer parameter is NULL in Exit of CDBWaitResult !\n");
	}

	dbHandle->queryStr = "";
	
	dbManager.ReleaseHandle(dbHandle);
}

void CDBWaitResult::Execute(CDBHandle *dbHandle)
{
}
