#include "stdafx.h"

CClientManager::~CClientManager()
{
	CloseHandle(iocp);
	for (CClientSocket *tmpSock : sockets)
	{
		closesocket(tmpSock->sock);
		delete tmpSock;
	}
	DeleteCriticalSection(&playersLock);
}

CClientManager &CClientManager::GetInstance()
{
	static CClientManager clientManager;
	return clientManager;
}

bool CClientManager::FirstInitializer()
{
	InitializeCriticalSectionAndSpinCount(&playersLock, 4000);
	
	iocp = NULL;

	return true;
}

bool CClientManager::SecondInitializer(const int &threadNum, const int &socketPoolsizeParam, const WORD &port)
{
	socketPoolSize = socketPoolsizeParam;

	if (!proactor.Initializer(threadNum))
	{
		MYERRORPRINTF("Initializer of proactor");
		return false;
	}

	if (!listenSocket.Init(port, 100))
	{
		MYERRORPRINTF("Init of listenSocket");
		return false;
	}

	if (!connector.Initializer())
	{
		MYERRORPRINTF("Initializer of connector");
		return false;
	}
	if (!disconnector.Initializer())
	{
		MYERRORPRINTF("Initializer of disconnector");
		return false;
	}
	if (!receiver.Initializer())
	{
		MYERRORPRINTF("Initializer of receiver");
		return false;
	}
	if (!sender.Initializer())
	{
		MYERRORPRINTF("Initializer of sender");
		return false;
	}
	if (!acceptor.Initializer(listenSocket))
	{
		MYERRORPRINTF("Initializer of acceptor");
		return false;
	}
	
	if (!listenSocket.Listen(proactor))
	{
		MYERRORPRINTF("listen of listensocket");
		return false;
	}

	if (!MakeSocketPool(threadNum))
	{
		MYERRORPRINTF("MakeSocketPool");
		return false;
	}

	roomManager = new CRoomManager();


	return true;
}

bool CClientManager::SocketCreate(CClientSocket &socket)
{
	socket.sock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

	if (INVALID_SOCKET == socket.sock)
	{
		MYERRORPRINTF("WSASocket");
		return false;
	}

	return true;
}

bool CClientManager::MakeSocketPool(const int &sockPoolSizeParam)
{
	socketPoolSize = sockPoolSizeParam;

	sockets.reserve(socketPoolSize);

	for (int k = 0; k < socketPoolSize; ++k)
	{
		CClientSocket *socket = new CClientSocket();

		if (!SocketCreate(*socket))
		{
			MYERRORPRINTF("SocketCreate");
			return false;
		}

		socket->InitBuf();

		socket->Initializer(&proactor, &connector, &disconnector, &receiver, &sender, &acceptor);

		acceptor.Register(*socket, 0);

		sockets.push_back(socket);
	}

	return true;
}

void CClientManager::AddUser(CClientSocket* pPlayer)
{
	EnterCriticalSection(&playersLock);

	players.push_back(pPlayer);

	LeaveCriticalSection(&playersLock);
}

void CClientManager::DeleteUser(CClientSocket* pPlayer)
{
	EnterCriticalSection(&playersLock);

	players.remove(pPlayer);

	LeaveCriticalSection(&playersLock);
}

void CClientManager::TotalUserInfoPrint()
{
	if (!players.empty())
	{
		printf("[Client Manager] Players In Server : %d players\n", players.size());

		for (auto player : players)
		{
			printf("[Player Info]\n");
			printf("ID : %s\n", player->nickName.c_str());
			printf("Curr Room Number : %d room\n", player->currRoomNum);
			printf("Curr Player State : %d\n", player->currState);
			printf("\n");
		}
	}
}