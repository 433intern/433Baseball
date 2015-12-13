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

	HANDLE							sockPoolSema;
	int								socketPoolSize;
	std::queue<CLoginSocket*>		sockets;
public:
	CProactor						proactor;

	//--------------------------------------------

	~CLoginManager();

	bool FirstInitializer();
	bool SecondInitializer(const int &threadNum, const int& socketPoolSize, const WORD &port);

	bool MakeSocketPool(const int &sockPoolSizeParam);
	bool SocketCreate(CLoginSocket &socket);

	CLoginSocket					*GetAvailableSocket();
	bool							ReleaseSocket(CLoginSocket *param);

	static CLoginManager			&GetInstance();
};
