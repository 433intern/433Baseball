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
	CClientAct &tmpAct = *(CClientAct*)act;

	CClientSocket &tmpSocket = *tmpAct.clientSocket;

	CClientManager &clientManager = CClientManager::GetInstance();

	clientManager.proactor.Register((HANDLE)tmpSocket.sock);

	MYPRINTF("ACCEPTED !!");

	tmpSocket.Recv(tmpSocket.recvBuf, HEADER_SIZE);

	return true;
}

bool CAcceptor::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CAcceptor::Initializer(CListenSocket &listenSockParam)
{
	listenSocket = &listenSockParam;

	lpfnAcceptEx = NULL;
	GUID GuidAcceptEx = WSAID_ACCEPTEX;

	DWORD dwBytes;

	int iResult = WSAIoctl(listenSockParam.sock, SIO_GET_EXTENSION_FUNCTION_POINTER,
		&GuidAcceptEx, sizeof (GuidAcceptEx),
		&lpfnAcceptEx, sizeof (lpfnAcceptEx),
		&dwBytes, NULL, NULL);

	if (SOCKET_ERROR == iResult)
	{
		wprintf(L"WSAIoctl failed with error: %u\n", WSAGetLastError());
		closesocket(listenSockParam.sock);
		WSACleanup();
		return false;
	}

	return true;
}

bool CAcceptor::Register(CClientSocket &clientSocket, int size)
{
	DWORD byteTransferred;

	memset(&olOverlap, 0, sizeof (olOverlap));

	BOOL result = lpfnAcceptEx(listenSocket->sock, clientSocket.sock, clientSocket.acceptBuf,
		BUFSIZE - ((sizeof (sockaddr_in)+16) << 1),
		sizeof (sockaddr_in)+16, sizeof (sockaddr_in)+16,
		&byteTransferred, static_cast<OVERLAPPED*>(&clientSocket.acts[CClientSocket::ACT_TYPE::ACCEPT]));

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