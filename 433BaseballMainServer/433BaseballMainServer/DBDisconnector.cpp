#include "stdafx.h"

CDBDisconnector::CDBDisconnector()
{
}

CDBDisconnector::~CDBDisconnector()
{
}

bool CDBDisconnector::EventProc(CAct *act, DWORD receivedBytes)
{
	CGlobalManager &globalManager = CGlobalManager::GetInstance();

	CDBAct *dbAct = (CDBAct*)act;

	CDBManager &dbManager = CDBManager::GetInstance();

	CDBHandle *dbHandle = dbAct->dbHandle;

	//--------------------------------------

	//--------------------------------------

	dbHandle->stateMachine.ChangeState(CDBClosed::Instance());

	return true;
}

bool CDBDisconnector::ErrorProc(CAct *act, DWORD error)
{

	return true;
}

bool CDBDisconnector::Initializer()
{

	return true;
}