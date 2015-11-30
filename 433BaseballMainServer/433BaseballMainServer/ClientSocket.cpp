#include "stdafx.h"

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}

bool CClientSocket::Initializer(CProactor *proactorParam, CConnector *connectorParam, CDisconnector *disconnectorParam
	, CReceiver *receiverParam, CSender *senderParam, CAcceptor *acceptorParam)
{
	wsaRecvBuf.buf = recvBuf;
	wsaRecvBuf.len = BUFSIZE;

	wsaSendBuf.buf = sendBuf;
	wsaSendBuf.len = BUFSIZE;

	memset(recvBuf, 0, BUFSIZE);
	memset(sendBuf, 0, BUFSIZE);

	proactor = proactorParam;

	connector = connectorParam;
	disconnector = disconnectorParam;
	receiver = receiverParam;
	sender = senderParam;
	acceptor = acceptorParam;

	acts[CONNECT].Initializer(connector);
	acts[DISCONNECT].Initializer(disconnector);
	acts[RECEIVE].Initializer(receiver);
	acts[SEND].Initializer(sender);
	acts[ACCEPT].Initializer(acceptor);
}

bool Recv(TCHAR *buf, int bufSize)
{
	return true;
}

bool Send(TCHAR *buf, int bufSize)
{
	return true;
}

bool Connect()
{
	return true;
}

bool Disconnect()
{
	return true;
}