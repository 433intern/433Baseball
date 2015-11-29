#include "stdafx.h"

CDBManager::CDBManager(HANDLE deviceHandle)
:deviceHandle(deviceHandle)
{
}


CDBManager::~CDBManager()
{
}

bool CDBManager::Initializer(const HANDLE &deviceHandle, const int &threadNum)
{
	if (proactor.Initializer(deviceHandle, threadNum))
		return true;
	return false;
}
