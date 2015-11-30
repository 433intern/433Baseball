#include "stdafx.h"

CClientManager::CClientManager()
:iocp(NULL), proactor()
{
}


CClientManager::~CClientManager()
{
}

bool CClientManager::Initializer(const int &threadNum)
{
	connector.Initializer();
	disconnector.Initializer();
	receiver.Initializer();
	sender.Initializer();
	acceptor.Initializer();

	socket.Initializer(&proactor, &connector, &disconnector, &receiver, &sender, &acceptor);

	if (!Bind(false))
	{
		MYPRINTF("Error on Bind functino of CClientManager : %d\n", WSAGetLastError());
		return false;
	}

	if (!proactor.Initializer((HANDLE)socket.socket, threadNum))
	{
		MYPRINTF("Error on Initializer functino of proactor in CClientManager : %d\n", WSAGetLastError());
		return false;
	}
	return true;

	socket.Connect();
}

bool CClientManager::Bind(bool reuse)
{
	int result;

	if (!reuse)
	{
		socket.socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
		if (INVALID_SOCKET == socket.socket)
		{
			MYPRINTF("Error on WSASocket in Bind function of CClientManager : %d\n", WSAGetLastError());
			return false;
		}
	}
	
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(SERVERPORT);

	result = bind(socket.socket, (SOCKADDR*)&addr, sizeof(addr));
	if (SOCKET_ERROR == result)
	{
		MYPRINTF("Error on bind in Bind function of CClientManager : %d\n", WSAGetLastError());
		return false;
	}

	return true;
}