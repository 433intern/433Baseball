#pragma once

struct CClientSocket : public CSockInfo
{
public:
	enum ACT_TYPE
	{
		CONNECT
		,DISCONNECT
		,RECEIVE
		,SEND
		,ACCEPT
		,TYPE_CNT
	};

	enum PLAYER_STATE
	{
		LOBBY,
		INROOM,
		INGAME
	};

	struct mswsock_s {
		LPFN_CONNECTEX ConnectEx;
	} mswsock;

	CClientAct						acts[ACT_TYPE::TYPE_CNT];

	CProactor						*proactor;

	CConnector						*connector;
	CDisconnector					*disconnector;
	CReceiver						*receiver;
	CSender							*sender;
	CAcceptor						*acceptor;

	CHAR							acceptBuf[BUFSIZE];
	CHAR							recvBuf[BUFSIZE];
	CHAR							sendBuf[BUFSIZE];

	WSABUF							wsaRecvBuf, wsaSendBuf;

	StateMachine<CClientSocket>		stateMachine;

	int								bytePosition;
	int								remainBytes;

	bool							isPayload;
	google::protobuf::uint32		payloadType;
	google::protobuf::uint32		payloadSize;
	

public:
	std::string						nickName;
	std::string						securityCode;
	int								currRoomNum;
	short							currState;
	PlayerStatus					status;
	
public:
	CClientSocket();
	~CClientSocket();

	bool Initializer(CProactor *proactorParam, CConnector *connectorParam, CDisconnector *disconnectorParam
		, CReceiver *receiverParam, CSender *senderParam, CAcceptor *acceptorParam);

	bool Recv(CHAR *buf, int bufSize);
	bool Send(CHAR *buf, int bufSize);
	bool Connect();
	bool Disconnect();
	bool InitBuf();

	void PacketHandling(char* buf, google::protobuf::uint32 type, google::protobuf::uint32 size);

	void RecvProcess(bool isError, CAct* act, DWORD bytes_transferred);
	void SendProcess(bool isError, CAct* act, DWORD bytes_transferred);
	void AcceptProcess(bool isError, CAct* act, DWORD bytes_transferred);
	void DisconnProcess(bool isError, CAct* act, DWORD bytes_transferred);
	void ConnProcess(bool isError, CAct* act, DWORD bytes_transferred);

public:
	void InitStatus(int winCount, int loseCount);
	
};

