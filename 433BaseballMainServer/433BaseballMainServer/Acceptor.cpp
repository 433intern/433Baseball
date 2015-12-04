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

	proactor->Register((HANDLE)tmpSocket.sock);

	tmpSocket.Recv(tmpSocket.recvBuf, HEADER_SIZE);

	return true;
}

bool CAcceptor::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CAcceptor::Initializer(CListenSocket &listenSockParam, CProactor *proactorParam)
{
	listenSocket = &listenSockParam;
	proactor = proactorParam;

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

	/*int error_code;
	int error_code_size = sizeof(error_code);
	getsockopt(clientSocket.socket, SOL_SOCKET, SO_CONNECT_TIME, (char*)&error_code, &error_code_size);

	int error = WSAGetLastError();

	int addrSize = sizeof(listenSocket->addr);*/

	//SOCKET socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

	/*BOOL result = AcceptEx(
		listenSocket->socket,
		clientSocket.socket,
		clientSocket.acceptBuf,
		size,
		sizeof(SOCKADDR_IN)+16,
		sizeof(SOCKADDR_IN)+16,
		&byteTransferred,
		static_cast<OVERLAPPED*>(&clientSocket.acts[CClientSocket::ACT_TYPE::ACCEPT])
		);*/

	BOOL result = lpfnAcceptEx(listenSocket->sock, clientSocket.sock, clientSocket.acceptBuf,
		BUFSIZE - ((sizeof (sockaddr_in)+16) << 1),
		sizeof (sockaddr_in)+16, sizeof (sockaddr_in)+16,
		&byteTransferred, static_cast<OVERLAPPED*>(&clientSocket.acts[CClientSocket::ACT_TYPE::ACCEPT]));

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