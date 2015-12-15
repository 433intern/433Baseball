#pragma once

struct CLoginSocket : public CSockInfo
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

	CLoginAct								acts[ACT_TYPE::TYPE_CNT];

	CProactor								*proactor;

	CConnector								*connector;
	CDisconnector							*disconnector;
	CReceiver								*receiver;
	CSender									*sender;
	CAcceptor								*acceptor;

	CHAR									acceptBuf[BUFSIZE];
	CHAR									recvBuf[BUFSIZE];
	CHAR									sendBuf[BUFSIZE];

	WSABUF									wsaRecvBuf, wsaSendBuf;

	StateMachine<CLoginSocket>				stateMachine;

	protocol::PacketHeader					header;
	protocol::LSC_account_create_result		accountCreateResult;
	protocol::CLS_login_request				loginRequest;

	CLoginSocket();
	~CLoginSocket();

	bool Initializer(CProactor *proactorParam, CConnector *connectorParam, CDisconnector *disconnectorParam
		, CReceiver *receiverParam, CSender *senderParam, CAcceptor *acceptorParam);

	bool Recv(CHAR *buf, int bufSize);
	bool Send(CHAR *buf, int bufSize);
	bool Connect();
	bool Disconnect();
	bool InitBuf();
};

