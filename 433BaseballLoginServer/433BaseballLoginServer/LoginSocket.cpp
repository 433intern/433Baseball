#include "stdafx.h"

CLoginSocket::CLoginSocket()
:stateMachine(this)
{
	stateMachine.SetCurrentState(CDisconnected::Instance());
	header.Clear();
}

CLoginSocket::~CLoginSocket()
{
	closesocket(sock);

	delete proactor;

	delete connector;
	delete receiver;
	delete sender;
	delete acceptor;
}

bool CLoginSocket::Initializer(CProactor *proactorParam, CConnector *connectorParam, CDisconnector *disconnectorParam
	, CReceiver *receiverParam, CSender *senderParam, CAcceptor *acceptorParam)
{
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
	DWORD recvbytes = 0;
	DWORD flags = 0;
	wsaRecvBuf.buf = buf;
	wsaRecvBuf.len = bufSize;

	int result = WSARecv(sock, &(wsaRecvBuf), 1, &recvbytes, &flags, static_cast<OVERLAPPED*>(&acts[CLoginSocket::ACT_TYPE::RECEIVE]), NULL);

	if (0 != result)
	{
		int error = WSAGetLastError();

		if (ERROR_IO_PENDING != error)
		{
			MYPRINTF("WSARecv");
			return false;
		}
	}

	return true;
}

bool CLoginSocket::Send(CHAR *buf, int bufSize)
{
	if (0 == bufSize)
	{
		MYERRORPRINTF("bufSize is 0 in Send function");
		return false;
	}
	DWORD sentbytes = 0;
	wsaSendBuf.buf = buf;
	wsaSendBuf.len = bufSize;

	int result = WSASend(sock, &wsaSendBuf, 1, &sentbytes, 0, static_cast<OVERLAPPED*>(&acts[CLoginSocket::ACT_TYPE::SEND]), NULL);

	printf("%d bytes were sent !", sentbytes);

	if (0 != result)
	{
		int error = WSAGetLastError();

		if (ERROR_IO_PENDING != error)
		{
			MYPRINTF("WSASend");
			return false;
		}
	}

	return true;
}

bool CLoginSocket::Connect()
{
	// Useless function
	return true;
}

bool CLoginSocket::Disconnect()
{
	BOOL result = TransmitFile(
		sock,
		NULL,
		0,
		0,
		static_cast<OVERLAPPED*>(&acts[CLoginSocket::ACT_TYPE::DISCONNECT]),
		NULL,
		TF_DISCONNECT | TF_REUSE_SOCKET
		);

	if (!result)
	{
		int error = WSAGetLastError();

		if (error != ERROR_IO_PENDING)
		{
			MYPRINTF("TransmitFile");
		}
	}

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