#include "stdafx.h"

CClientSocket::CClientSocket()
:stateMachine(this)
{
}

CClientSocket::~CClientSocket()
{
}

bool CClientSocket::Initializer(CProactor *proactorParam, CConnector *connectorParam, CDisconnector *disconnectorParam
	, CReceiver *receiverParam, CSender *senderParam, CAcceptor *acceptorParam)
{
	stateMachine.SetCurrentState(CWaitMessage::Instance());

	proactor = proactorParam;

	connector = connectorParam;
	disconnector = disconnectorParam;
	receiver = receiverParam;
	sender = senderParam;
	acceptor = acceptorParam;

	if (!acts[CONNECT].Initializer(connector, this))
	{
		MYPRINTF("error on acts[CONNECT].Initializer in Initializer of CClientSocket : %d\n", WSAGetLastError());
		return false;
	}
	if (!acts[DISCONNECT].Initializer(disconnector, this))
	{
		MYPRINTF("error on acts[DISCONNECT].Initializer in Initializer of CClientSocket : %d\n", WSAGetLastError());
		return false;
	}
	if (!acts[RECEIVE].Initializer(receiver, this))
	{
		MYPRINTF("error on acts[RECEIVE].Initializer in Initializer of CClientSocket : %d\n", WSAGetLastError());
		return false;
	}
	if (!acts[SEND].Initializer(sender, this))
	{
		MYPRINTF("error on acts[SEND].Initializer in Initializer of CClientSocket : %d\n", WSAGetLastError());
		return false;
	}
	if(!acts[ACCEPT].Initializer(acceptor, this))
	{
		MYPRINTF("error on acts[ACCEPT].Initializer in Initializer of CClientSocket : %d\n", WSAGetLastError());
		return false;
	}

	return true;
}

bool CClientSocket::Recv(CHAR *buf, int bufSize)
{
	return true;
}

bool CClientSocket::Send(CHAR *buf, int bufSize)
{
	return true;
}

bool CClientSocket::Connect()
{
	// Useless function
	return true;
}

bool CClientSocket::Disconnect()
{
	// Useless function
	return true;
}

bool CClientSocket::InitBuf()
{
	wsaRecvBuf.buf = recvBuf;
	wsaRecvBuf.len = BUFSIZE;

	wsaSendBuf.buf = sendBuf;
	wsaSendBuf.len = BUFSIZE;

	memset(acceptBuf, 0, BUFSIZE);
	memset(recvBuf, 0, BUFSIZE);
	memset(sendBuf, 0, BUFSIZE);

	return true;
}