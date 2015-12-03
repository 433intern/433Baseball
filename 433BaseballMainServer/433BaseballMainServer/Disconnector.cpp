#include "stdafx.h"

CDisconnector::CDisconnector()
{
}

CDisconnector::~CDisconnector()
{
}

bool CDisconnector::EventProc(CAct *act, DWORD receivedBytes)
{
	return true;
}

bool CDisconnector::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CDisconnector::Initializer(CProactor *proactorParam)
{
	proactor = proactorParam;
	return true;
}