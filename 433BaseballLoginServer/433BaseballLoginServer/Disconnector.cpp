#include "stdafx.h"

CDisconnector::CDisconnector()
{
}

CDisconnector::~CDisconnector()
{
}

bool CDisconnector::EventProc(CAct *act, DWORD receivedBytes)
{
	CLoginAct *loginAct = (CLoginAct*)act;

	CLoginManager &loginManager = CLoginManager::GetInstance();

	CLoginSocket &loginSock = *loginAct->loginSocket;

	loginSock.stateMachine.ChangeState(CDisconnected::Instance());

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