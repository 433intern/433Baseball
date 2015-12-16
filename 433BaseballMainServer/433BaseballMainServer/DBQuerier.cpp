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
		MYDBERRORPRINTF(dbHandle->connTmp,"mysql_query");
		return false;
	}
	else
	{
		MYSQL_RES *tmpRes;
		unsigned int numFields;
		unsigned int numRows;

		tmpRes = mysql_store_result(realDBHandle);
		if (tmpRes)
		{

		}
		else
		{
			if (mysql_field_count(realDBHandle))
			{
				MYDBERRORPRINTF(dbHandle->connTmp, "mysql_query");
				return false;
			}
		}
	}
	dbHandle->stateMachine.ChangeState(CDBIdle::Instance());
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