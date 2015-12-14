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

	int								socketPoolSize;
	std::vector<CLoginSocket*>		sockets;
public:
	CProactor						proactor;
	CAcceptor						acceptor;

	//--------------------------------------------

	~CLoginManager();

	bool FirstInitializer();
	bool SecondInitializer(const int &threadNum, const int& socketPoolSize, const WORD &port);

	bool MakeSocketPool(const int &sockPoolSizeParam);
	bool SocketCreate(CLoginSocket &socket);

	static CLoginManager			&GetInstance();
};
