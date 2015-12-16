#include "stdafx.h"

CDisconnector::CDisconnector()
{
}

CDisconnector::~CDisconnector()
{
}

bool CDisconnector::EventProc(CAct *act, DWORD receivedBytes)
{
	CClientAct *clientAct = (CClientAct*)act;

	CClientManager &clientManager = CClientManager::GetInstance();

	CClientSocket &clientSock = *clientAct->clientSocket;

	clientManager.acceptor.Register(clientSock, 0);

	return true;
}

bool CDisconnector::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CDisconnector::Initializer()
{
	return true;
}