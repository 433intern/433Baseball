#include "stdafx.h"

CClientManager::CClientManager()
:iocp(NULL), proactor()
{
}


CClientManager::~CClientManager()
{
}

bool CClientManager::Initializer(const int &threadNum, const int &socketPoolsizeParam, const WORD &port)
{
	socketPoolSize = socketPoolsizeParam;

	if (!listenSocket.Init(port, 100))
	{
		MYPRINTF("Error on Init of ListenSocket in Initializer of CClientManager : %d\n", WSAGetLastError());
		return false;
	}

	connector.Initializer(&proactor);
	disconnector.Initializer(&proactor);
	receiver.Initializer(&proactor);
	sender.Initializer(&proactor);
	acceptor.Initializer(listenSocket, &proactor);

	if (!proactor.Initializer(threadNum))
	{
		MYPRINTF("Error on Initializer functino of proactor in CClientManager : %d\n", WSAGetLastError());
		return false;
	}

	if (!proactor.Register((HANDLE)listenSocket.sock))
	{
		MYPRINTF("Error on Register functino of proactor in CClientManager : %d\n", WSAGetLastError());
		return false;
	}

	listenSocket.Listen();

	socketPoolSize = 1;

	sockets.resize(socketPoolSize);

	for (int k = 0; k < socketPoolSize; ++k)
	{
		CClientSocket *socket = new CClientSocket();

		if (!SocketCreate(*socket))
		{
			MYPRINTF("Error on SocketCreate functino of CClientManager : %d\n", WSAGetLastError());
			return false;
		}

		socket->InitBuf();

		socket->Initializer(&proactor, &connector, &disconnector, &receiver, &sender, &acceptor);
		
		acceptor.Register(*socket, 0);
		
		//sockets.push_back(socket);
	}

	return true;
}

bool CClientManager::SocketCreate(CClientSocket &socket)
{
	int result;

	//if (!reuse)
	{
		socket.sock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
		//socket.sock = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		if (INVALID_SOCKET == socket.sock)
		{
			MYPRINTF("Error on WSASocket in Bind function of CClientManager : %d\n", WSAGetLastError());
			return false;
		}
	}

	return true;
}