#include "stdafx.h"

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}

bool CListenSocket::Listen(CProactor& proactor)
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(SERVERPORT);

	if (!proactor.Register((HANDLE)sock))
	{
		MYERRORPRINTF("proactor.Register");
		return false;
	}

	int result = bind(sock, (SOCKADDR*)&addr, sizeof(addr));

	if (SOCKET_ERROR == result)
	{
		MYERRORPRINTF("bind");
		return false;
	}

	result = listen(sock, backlogSize);
	
	if (SOCKET_ERROR == result)
	{
		MYERRORPRINTF("listen");
		return false;
	}

	return true;
}

bool CListenSocket::Init(WORD port, int backlogSizeParam)
{
	this->backlogSize = backlogSizeParam;
	sock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

	if (INVALID_SOCKET == sock)
	{
		MYERRORPRINTF("WSASocket");
		return false;
	}

	return true;
}