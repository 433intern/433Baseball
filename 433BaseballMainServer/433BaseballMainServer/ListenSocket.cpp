#include "stdafx.h"

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}

bool CListenSocket::Listen()
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(SERVERPORT);

	int result = bind(socket, (SOCKADDR*)&addr, sizeof(addr));

	if (SOCKET_ERROR == result)
	{
		MYPRINTF("Error on bind in Listen function of CListenSocket : %d\n", WSAGetLastError());
		return false;
	}

	result = listen(socket, backlogSize);
	
	if (SOCKET_ERROR == result)
	{
		MYPRINTF("Error on listen in Listen function of CListenSocket : %d\n", WSAGetLastError());
		return false;
	}

	return true;
}

bool CListenSocket::Init(WORD port, int backlogSizeParam)
{
	this->backlogSize = backlogSizeParam;
	socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (INVALID_SOCKET == socket)
	{
		MYPRINTF("Error on WSASocket in Init function of CListenSocket : %d\n", WSAGetLastError());
		return false;
	}

	return true;
}