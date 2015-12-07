#include "stdafx.h"

CDBHarvester::CDBHarvester()
{
}

CDBHarvester::~CDBHarvester()
{
}

bool CDBHarvester::EventProc(CAct *act, DWORD receivedBytes)
{

	return true;
}

bool CDBHarvester::ErrorProc(CAct *act, DWORD error)
{

	return true;
}

bool CDBHarvester::Initializer(CProactor *proactor)
{

	return true;
}