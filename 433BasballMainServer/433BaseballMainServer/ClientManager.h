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

	std::list<CClientSocket*>		players;

	CRITICAL_SECTION				playersLock;

public:
	CAcceptor						acceptor;
	CProactor						proactor;

	//--------------------------------------------

	~CClientManager();

	static CClientManager&			GetInstance();

public:

	bool FirstInitializer();
	bool SecondInitializer(const int &threadNum, const int& socketPoolSize, const WORD &port);

	bool MakeSocketPool(const int &sockPoolSizeParam);
	bool SocketCreate(CClientSocket &socket);
	
	void AddUser(CClientSocket* pPlayer);
	void DeleteUser(CClientSocket* pPlayer);
	void TotalUserInfoPrint();

	
};
