#include "stdafx.h"

CAcceptor::CAcceptor()
{
}

CAcceptor::~CAcceptor()
{
}

bool CAcceptor::EventProc(CAct *act, DWORD receivedBytes)
{
	CClientAct &tmpAct = *(CClientAct*)act;

	CClientSocket &tmpSocket = *tmpAct.clientSocket;

	proactor->Register((HANDLE)tmpSocket.socket);

	tmpSocket.Recv(tmpSocket.recvBuf, HEADER_SIZE);

	return true;
}

bool CAcceptor::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CAcceptor::Initializer(CProactor *proactorParam)
{
	proactor = proactorParam;
	return true;
}

bool CAcceptor::Register(CClientSocket &clientSocket, int size)
{
	DWORD byteTransferred;

	BOOL result = AcceptEx(
		listenSocket.socket,
		clientSocket.socket,
		clientSocket.acceptBuf, size,
		sizeof(SOCKADDR_IN)+16,
		sizeof(SOCKADDR_IN)+16,
		&byteTransferred,
		static_cast<OVERLAPPED*>(&clientSocket.acts[CClientSocket::ACT_TYPE::ACCEPT])
		);

	int error = WSAGetLastError();

	if (!result)
	{
		if (WSA_IO_PENDING != error)
		{
			MYPRINTF("Error on AcceptEx in Register of Acceptor : %d\n", error);
			return false;
		}
	}
	return true;
}