#include "stdafx.h"

CDBHarvester::CDBHarvester()
{
}

CDBHarvester::~CDBHarvester()
{
}

bool CDBHarvester::EventProc(CAct *act, DWORD receivedBytes)
{
	CGlobalManager &globalManager = CGlobalManager::GetInstance();

	CDBAct *dbAct = (CDBAct*)act;

	CDBManager &dbManager = CDBManager::GetInstance();

	CDBHandle *dbHandle = dbAct->dbHandle;

	//--------------------------------------


	//--------------------------------------

	dbHandle->stateMachine.ChangeState(CDBIdle::Instance());

	return true;
}

bool CDBHarvester::ErrorProc(CAct *act, DWORD error)
{

	return true;
}

bool CDBHarvester::Initializer()
{
	return true;
}