#pragma once

struct CClientSocket : public CSockInfo
{
	enum ACT_TYPE
	{
		CONNECT
		,DISCONNECT
		,RECEIVE
		,SEND
		,ACCEPT
		,TYPE_CNT
	};

	struct mswsock_s {
		LPFN_CONNECTEX ConnectEx;
	} mswsock;

	CClientAct						acts[ACT_TYPE::TYPE_CNT];

public:
	int								roomNum;
	std::string						id;

public:
	CProactor						*proactor;

	CConnector						*connector;
	CDisconnector					*disconnector;
	CReceiver						*receiver;
	CSender							*sender;
	CAcceptor						*acceptor;

public:
	CHAR							acceptBuf[BUFSIZE];
	CHAR							recvBuf[BUFSIZE];
	CHAR							sendBuf[BUFSIZE];

	WSABUF							wsaRecvBuf, wsaSendBuf;
	
	int								position;
	int								remainBytes;
	
	bool disconnectCall;

	StateMachine<CClientSocket>		stateMachine;

	CClientSocket();
	~CClientSocket();

	bool Initializer(CProactor *proactorParam, CConnector *connectorParam, CDisconnector *disconnectorParam
		, CReceiver *receiverParam, CSender *senderParam, CAcceptor *acceptorParam);

	bool Recv(CHAR *buf, int bufSize);
	bool Send(CHAR *buf, int bufSize);
	bool Connect();
	bool Disconnect();
	bool InitBuf();

	void RecvProcess(bool isError, CAct* act, DWORD bytes_transferred);
	void SendProcess(bool isError, CAct* act, DWORD bytes_transferred);
	void AcceptProcess(bool isError, CAct* act, DWORD bytes_transferred);
	void DisconnProcess(bool isError, CAct* act, DWORD bytes_transferred);
	void ConnProcess(bool isError, CAct* act, DWORD bytes_transferred);

};

