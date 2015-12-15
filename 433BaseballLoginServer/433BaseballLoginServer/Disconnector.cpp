#include "stdafx.h"

CDisconnector::CDisconnector()
{
}

CDisconnector::~CDisconnector()
{
}

bool CDisconnector::EventProc(CAct *act, DWORD receivedBytes)
{
	CLoginManager &loginManager = CLoginManager::GetInstance();

	CLoginAct *loginAct = (CLoginAct*)act;

	CLoginSocket &loginSock = *loginAct->loginSocket;

	loginSock.stateMachine.ChangeState(CDisconnected::Instance());

	closesocket(loginSock.sock);

	if (!loginManager.SocketCreate(loginSock))
	{
		MYERRORPRINTF("SocketCreate");
		return false;
	}

	loginManager.acceptor.Register(loginSock, 0);

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