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

	int								socketPoolSize;
	std::vector<CClientSocket*>		sockets;
public:
	CAcceptor						acceptor;
	CProactor						proactor;

	//--------------------------------------------

	~CClientManager();

	bool FirstInitializer();
	bool SecondInitializer(const int &threadNum, const int& socketPoolSize, const WORD &port);

	bool MakeSocketPool(const int &sockPoolSizeParam);
	bool SocketCreate(CClientSocket &socket);

	static CClientManager			&GetInstance();
};
