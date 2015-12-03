#include "stdafx.h"

CClientManager::CClientManager()
:iocp(NULL), proactor()
{
}


CClientManager::~CClientManager()
{
}

bool CClientManager::Initializer(const int &threadNum, const int &socketPoolsize, const WORD &port)
{
	connector.Initializer(&proactor);
	disconnector.Initializer(&proactor);
	receiver.Initializer(&proactor);
	sender.Initializer(&proactor);
	acceptor.Initializer(&proactor);

	if (!listenSocket.Init(port))
	{
		MYPRINTF("Error on Init of ListenSocket in Initializer of CClientManager : %d\n", WSAGetLastError());
		return false;
	}

	if (!proactor.Initializer(threadNum))
	{
		MYPRINTF("Error on Initializer functino of proactor in CClientManager : %d\n", WSAGetLastError());
		return false;
	}

	if (!proactor.Register((HANDLE)listenSocket.socket))
	{
		MYPRINTF("Error on Register functino of proactor in CClientManager : %d\n", WSAGetLastError());
		return false;
	}

	listenSocket.Listen();

	CClientSocket *socket;

	sockets.resize(socketPoolSize);

	for (int k = 0; k < socketPoolSize; ++k)
	{
		socket = new CClientSocket();

		socket->Initializer(&proactor, &connector, &disconnector, &receiver, &sender, &acceptor);

		if (!CreateAndBind(*socket, false))
		{
			MYPRINTF("Error on CreateAndBind functino of CClientManager : %d\n", WSAGetLastError());
			return false;
		} 
		
		acceptor.Register(*socket, 0);
		
		sockets.push_back(socket);
	}

	return true;
}

bool CClientManager::CreateAndBind(CClientSocket &socket, bool reuse)
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