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

	globalManager.dbManager->HarvestEx(&dbAct->dbHandle->acts[CDBHandle::DB_ACK_TYPE::HARVEST]);

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