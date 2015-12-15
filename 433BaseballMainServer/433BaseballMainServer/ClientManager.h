#pragma once

class CClientManager
{
	HANDLE							iocp;
	std::vector<HANDLE>				threads;

	CListenSocket					listenSocket;

	CConnector						connector;
	CDisconnector					disconnector;
	CReceiver						receiver;
	CSender							sender;
	CAcceptor						acceptor;

	HANDLE							sockPoolSema;
	int								socketPoolSize;
	std::queue<CClientSocket*>		sockets;
public:
	CProactor						proactor;

	//--------------------------------------------

	~CClientManager();

	bool FirstInitializer();
	bool SecondInitializer(const int &threadNum, const int& socketPoolSize, const WORD &port);

	bool MakeSocketPool(const int &sockPoolSizeParam);
	bool SocketCreate(CClientSocket &socket);

	CClientSocket					*GetAvailableSocket();
	bool							ReleaseSocket(CClientSocket *param);

	static CClientManager			&GetInstance();
};
