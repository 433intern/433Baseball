#include "stdafx.h"

CDBDisconnector::CDBDisconnector()
{
}

CDBDisconnector::~CDBDisconnector()
{
}

bool CDBDisconnector::EventProc(CAct *act, DWORD receivedBytes)
{

	return true;
}

bool CDBDisconnector::ErrorProc(CAct *act, DWORD error)
{

	return true;
}

bool CDBDisconnector::Initializer(CProactor *proactor)
{

	return true;
}