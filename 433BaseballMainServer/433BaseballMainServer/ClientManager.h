#pragma once
class CClientManager
{
	HANDLE					iocp;
	std::vector<HANDLE>		threads;

	CClientSocket			socket;
	CProactor				proactor;

	CConnector				connector;
	CDisconnector			disconnector;
	CReceiver				receiver;
	CSender					sender;
	CAcceptor				acceptor;
public:
	CClientManager();
	~CClientManager();

	bool Initializer(const int &threadNum);
	bool Bind(bool reuse);
};

