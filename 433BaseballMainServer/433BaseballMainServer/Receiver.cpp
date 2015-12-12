#include "stdafx.h"

CReceiver::CReceiver()
{
}

CReceiver::~CReceiver()
{
}

bool CReceiver::EventProc(CAct *act, DWORD receivedBytes)
{
	return true;
}

bool CReceiver::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CReceiver::Initializer()
{
	return true;
}