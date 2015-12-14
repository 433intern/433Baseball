#include "stdafx.h"

WSAOVERLAPPED olOverlap;

CAcceptor::CAcceptor()
{
}

CAcceptor::~CAcceptor()
{
}

bool CAcceptor::EventProc(CAct *act, DWORD receivedBytes)
{
	CLoginAct &tmpAct = *(CLoginAct*)act;

	CLoginSocket &tmpSocket = *tmpAct.loginSocket;

	CLoginManager &loginManager = CLoginManager::GetInstance();

	loginManager.proactor.Register((HANDLE)tmpSocket.sock);
	
	// You must change the state before receive the header !!!
	tmpSocket.stateMachine.ChangeState(CWaitHeader::Instance());
	tmpSocket.Recv(tmpSocket.recvBuf, HEADER_SIZE);

	MYPRINTF("ACCEPTED");

	return true;
}

bool CAcceptor::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CAcceptor::Initializer(CListenSocket &listenSockParam)
{
	listenSocket = &listenSockParam;

	return true;
}

bool CAcceptor::Register(CLoginSocket &loginSocket, int size)
{
	if (CDisconnected::Instance() != loginSocket.stateMachine.CurrentState())
	{
		MYERRORPRINTF("loginSocket's state is not CDisconnected !!!");
		return false;
	}

	DWORD byteTransferred;

	BOOL result = AcceptEx(
		listenSocket->sock,
		loginSocket.sock,
		loginSocket.acceptBuf, size,
		sizeof(SOCKADDR_IN)+16,
		sizeof(SOCKADDR_IN)+16,
		&byteTransferred,
		static_cast<OVERLAPPED*>(&loginSocket.acts[CLoginSocket::ACT_TYPE::ACCEPT])
		);

	int error = WSAGetLastError();

	if (!result)
	{
		if (WSA_IO_PENDING != error)
		{
			MYERRORPRINTF("AcceptEx");
			return false;
		}
	}
	return true;
}