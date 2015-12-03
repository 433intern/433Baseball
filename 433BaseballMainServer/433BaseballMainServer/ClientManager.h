#pragma once
class CClientManager
{
	HANDLE							iocp;
	std::vector<HANDLE>				threads;

	CListenSocket					listenSocket;
	CProactor						proactor;

	CConnector						connector;
	CDisconnector					disconnector;
	CReceiver						receiver;
	CSender							sender;
	CAcceptor						acceptor;

	int								socketPoolSize;
	std::vector<CClientSocket*>		sockets;
public:
	CClientManager();
	~CClientManager();

	bool Initializer(const int &threadNum, const int& socketPoolSize, const WORD &port);
	bool CreateAndBind(CClientSocket &socket, bool reuse);
};

