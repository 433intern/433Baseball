#include "stdafx.h"

CLoginManager::~CLoginManager()
{
	CloseHandle(iocp);
	CloseHandle(sockPoolSema);
	for (int k = 0; k < sockets.size(); ++k)
	{
		CLoginSocket *tmpSock = sockets.front();
		closesocket(tmpSock->sock);
		sockets.pop();
		delete tmpSock;
	}
}

CLoginManager &CLoginManager::GetInstance()
{
	static CLoginManager loginManager;
	return loginManager;
}

bool CLoginManager::FirstInitializer()
{
	iocp = NULL;

	return true;
}

bool CLoginManager::SecondInitializer(const int &threadNum, const int &socketPoolsizeParam, const WORD &port)
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

	if (!MakeSocketPool(socketPoolsizeParam))
	{
		MYERRORPRINTF("MakeSocketPool");
		return false;
	}

	return true;
}

bool CLoginManager::SocketCreate(CLoginSocket &socket)
{
	socket.sock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

	if (INVALID_SOCKET == socket.sock)
	{
		MYERRORPRINTF("WSASocket");
		return false;
	}

	return true;
}

bool CLoginManager::MakeSocketPool(const int &sockPoolSizeParam)
{
	socketPoolSize = sockPoolSizeParam;

	CLoginSocket *socket;

	sockPoolSema = CreateSemaphore(NULL, socketPoolSize, socketPoolSize, L"433_DB_Login_Sema");
	if (NULL == sockPoolSema)
	{
		MYERRORPRINTF("CreateSemaphore");
		return false;
	}

	for (int k = 0; k < socketPoolSize; ++k)
	{
		CLoginSocket *socket = new CLoginSocket();

		if (!SocketCreate(*socket))
		{
			MYERRORPRINTF("SocketCreate");
			return false;
		}

		socket->InitBuf();

		socket->Initializer(&proactor, &connector, &disconnector, &receiver, &sender, &acceptor);

		acceptor.Register(*socket, 0);

		sockets.push(socket);
	}

	return true;
}

CLoginSocket *CLoginManager::GetAvailableSocket()
{
	CLoginSocket *tmpSocket = NULL;

	DWORD result = WaitForSingleObject(sockPoolSema, WAIT_AVAILABLE_SOCKET_TIME);

	if (WAIT_FAILED == result)
	{
		MYERRORPRINTF("WaitForSingleObject");
		return false;
	}
	else if (WAIT_TIMEOUT == result)
	{
		MYPRINTF("There is no available DB handle !\n");
		return NULL;
	}
	else if (WAIT_OBJECT_0 == result)
	{
		tmpSocket = sockets.front();
		sockets.pop();

		if (NULL == tmpSocket)
		{
			MYPRINTF("The Sockets' queue is empty !\n");
			return NULL;
		}

		if (CDisconnected::Instance() == tmpSocket->stateMachine.CurrentState())
		{
			return tmpSocket;
		}

		MYERRORPRINTF("The available socket's state is not the ");
	}

	return tmpSocket;
}

bool CLoginManager::ReleaseSocket(CLoginSocket *param)
{
	if (NULL == param)
	{
		MYPRINTF("Error : The parameter of ReleaseSocket is NULL !\n");
		return false;
	}
	
	if (CDisconnected::Instance() == param->stateMachine.CurrentState())
	{
		MYPRINTF("Error : The Socket is already disconnected.\n");
		return false;
	}

	param->stateMachine.ChangeState(CDisconnected::Instance());

	if (!ReleaseSemaphore(sockPoolSema, 1, NULL))
	{
		MYERRORPRINTF("RelaseSemaphore");
		return false;
	}

	sockets.push(param);

	return true;
}