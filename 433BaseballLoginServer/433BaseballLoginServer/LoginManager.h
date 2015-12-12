#pragma once

class CLoginManager
{
	HANDLE							iocp;
	std::vector<HANDLE>				threads;

	CListenSocket					listenSocket;

	CConnector						connector;
	CDisconnector					disconnector;
	CReceiver						receiver;
	CSender							sender;
	CAcceptor						acceptor;

	int								socketPoolSize;
	std::vector<CLoginSocket*>		sockets;
public:
	CProactor						proactor;

	//--------------------------------------------

	~CLoginManager();

	bool FirstInitializer();
	bool SecondInitializer(const int &threadNum, const int& socketPoolSize, const WORD &port);

	bool MakeSocketPool();
	bool SocketCreate(CLoginSocket &socket);

	static CLoginManager			&GetInstance();
};
