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
	DWORD recvbytes = 0;
	DWORD flags = 0;

	INT ret = WSARecv(sock, &(wsaRecvBuf), 1, &recvbytes, &flags, static_cast<OVERLAPPED*>(&(acts[ACT_TYPE::RECEIVE])), NULL);

	if (ret != 0)
	{
		int error = WSAGetLastError();

		if (error != ERROR_IO_PENDING)
		{
			MYPRINTF("WSARecv() Error!!! s(%d) err(%d)\n", sock, error);
			//Disconnect();
		}
	}

	return true;
}

bool CClientSocket::Send(CHAR *buf, int bufSize)
{
	if (bufSize == 0) return;
	
	DWORD sentbytes = 0;
	wsaSendBuf.buf = buf;
	wsaSendBuf.len = bufSize;

	INT ret = WSASend(sock, &(wsaSendBuf), 1, &sentbytes, 0, static_cast<OVERLAPPED*>(&(acts[ACT_TYPE::SEND])), NULL);

	if (ret != 0)
	{
		int error = WSAGetLastError();

		if (error != ERROR_IO_PENDING)
		{
			MYPRINTF("WSASend() Error!!! s(%d) err(%d)\n", sock, error);
			//Disconnect();
		}
	}

	return true;
}

bool CClientSocket::Connect()
{
	// Useless function
	return true;
}

bool CClientSocket::Disconnect()
{
	if (disconnectCall) return;

	disconnectCall = true;

	BOOL ret = TransmitFile(
		sock,
		NULL,
		0,
		0,
		static_cast<OVERLAPPED*>(&(acts[ACT_TYPE::DISCONNECT])),
		NULL,
		TF_DISCONNECT | TF_REUSE_SOCKET
		);

	if (!ret)
	{
		int error = WSAGetLastError();

		if (error != ERROR_IO_PENDING)
		{
			MYPRINTF("already disconnected, DisconnectEx Error!!! s(%d), err(%d)\n", socket_, error);
		}
	}

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

void CClientSocket::RecvProcess(bool isError, CAct* act, DWORD bytes_transferred)
{
	if (isError)
	{
		MYPRINTF("[AgentClientSocket] RecvProcess Error : %d\n", WSAGetLastError);
		Disconnect();
		return;
	}

	if (bytes_transferred == 0)
	{
		Disconnect();
		return;
	}

	this->position += bytes_transferred;
	this->remainBytes -= bytes_transferred;

	if (this->sock == NULL){
		MYPRINTF("[AgentClientSocket] RecvProcess : recv buf socket is not available\n");
		return;
	}

	char* buf = this->recvBuf;

	if (this->position < HEADER_SIZE)
	{
		if (position == 0) remainBytes = HEADER_SIZE;
	}
	else
	{
		if (position == HEADER_SIZE && remainBytes == 0)

		if (remainBytes == 0)
		{



		}
	}
	Recv(buf + position, remainBytes);

}

void CClientSocket::SendProcess(bool isError, CAct* act, DWORD bytes_transferred)
{


}

void CClientSocket::AcceptProcess(bool isError, CAct* act, DWORD bytes_transferred)
{
	if (!isError){

	}
	else{
		/* error handling */
	}

}

void CClientSocket::DisconnProcess(bool isError, CAct* act, DWORD bytes_transferred)
{


}

void CClientSocket::ConnProcess(bool isError, CAct* act, DWORD bytes_transferred)
{


}