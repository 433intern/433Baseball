#include "stdafx.h"

CConnector::CConnector()
{
}

CConnector::~CConnector()
{
}

bool CConnector::EventProc(CAct *act, DWORD receivedBytes)
{
	return true;
}

bool CConnector::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CConnector::Initializer(CProactor *proactorParam)
{
	proactor = proactorParam;
	return true;
}