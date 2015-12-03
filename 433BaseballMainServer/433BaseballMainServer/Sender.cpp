#include "stdafx.h"

CSender::CSender()
{
}

CSender::~CSender()
{
}

bool CSender::EventProc(CAct *act, DWORD receivedBytes)
{
	return true;
}

bool CSender::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CSender::Initializer(CProactor *proactorParam)
{
	proactor = proactorParam;
	return true;
} 