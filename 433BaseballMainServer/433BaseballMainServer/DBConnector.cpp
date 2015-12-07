#include "stdafx.h"

CDBConnector::CDBConnector()
{
}

CDBConnector::~CDBConnector()
{
}

bool CDBConnector::EventProc(CAct *act, DWORD receivedBytes)
{

	return true;
}

bool CDBConnector::ErrorProc(CAct *act, DWORD error)
{

	return true;
}

bool CDBConnector::Initializer(CProactor *proactor)
{

	return true;
}