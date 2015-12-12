#include "stdafx.h"

CLoginSocket::CLoginSocket()
:stateMachine(this)
{
}

CLoginSocket::~CLoginSocket()
{
}

bool CLoginSocket::Initializer(CProactor *proactorParam, CConnector *connectorParam, CDisconnector *disconnectorParam
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
		MYPRINTF("error on acts[CONNECT].Initializer in Initializer of CLoginSocket : %d\n", WSAGetLastError());
		return false;
	}
	if (!acts[DISCONNECT].Initializer(disconnector, this))
	{
		MYPRINTF("error on acts[DISCONNECT].Initializer in Initializer of CLoginSocket : %d\n", WSAGetLastError());
		return false;
	}
	if (!acts[RECEIVE].Initializer(receiver, this))
	{
		MYPRINTF("error on acts[RECEIVE].Initializer in Initializer of CLoginSocket : %d\n", WSAGetLastError());
		return false;
	}
	if (!acts[SEND].Initializer(sender, this))
	{
		MYPRINTF("error on acts[SEND].Initializer in Initializer of CLoginSocket : %d\n", WSAGetLastError());
		return false;
	}
	if(!acts[ACCEPT].Initializer(acceptor, this))
	{
		MYPRINTF("error on acts[ACCEPT].Initializer in Initializer of CLoginSocket : %d\n", WSAGetLastError());
		return false;
	}

	return true;
}

bool CLoginSocket::Recv(CHAR *buf, int bufSize)
{
	return true;
}

bool CLoginSocket::Send(CHAR *buf, int bufSize)
{
	return true;
}

bool CLoginSocket::Connect()
{
	// Useless function
	return true;
}

bool CLoginSocket::Disconnect()
{
	// Useless function
	return true;
}

bool CLoginSocket::InitBuf()
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