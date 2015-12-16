#include "stdafx.h"

CClientSocket::CClientSocket()
:stateMachine(this),
 bytePosition(0),
 remainBytes(HEADER_SIZE),
 payloadType(0),
 payloadSize(0),
 nickName(""),
 currRoomNum(-1),
 currState(PLAYER_STATE::LOBBY)
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
	wsaRecvBuf.buf = buf;
	wsaRecvBuf.len = bufSize;

	int result = WSARecv(sock, &(wsaRecvBuf), 1, &recvbytes, &flags, static_cast<OVERLAPPED*>(&acts[CClientSocket::ACT_TYPE::RECEIVE]), NULL);

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

bool CClientSocket::Send(CHAR *buf, int bufSize)
{
	if (0 == bufSize)
	{
		MYERRORPRINTF("bufSize is 0 in Send function");
		return false;
	}
	DWORD sentbytes = 0;
	wsaSendBuf.buf = buf;
	wsaSendBuf.len = bufSize;

	int result = WSASend(sock, &(wsaSendBuf), 1, &sentbytes, 0, static_cast<OVERLAPPED*>(&acts[CClientSocket::ACT_TYPE::SEND]), NULL);

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

bool CClientSocket::Connect()
{
	// Useless function
	return true;
}

bool CClientSocket::Disconnect()
{
	BOOL result = TransmitFile(
		sock,
		NULL,
		0,
		0,
		static_cast<OVERLAPPED*>(&acts[CClientSocket::ACT_TYPE::DISCONNECT]),
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
void CClientSocket::PacketHandling(char* buf, google::protobuf::uint32 type, google::protobuf::uint32 size)
{
	protocol::CS_contact_alram contactAlramPacket;
	protocol::CS_room_create roomCreatePacket;
	protocol::CS_room_join roomJoinPacket;
	protocol::CS_room_leave roomLeavePacket;
	protocol::CS_room_info_request roomInfoRequestPacket;
	protocol::CS_request_ingame_start ingameStartPacket;
	protocol::CS_send_baseball_number sendBaseballNumPacket;
	
	std::string textFormat;

	switch (type)
	{
	case protocol::PacketType::CS_CONTACT_ALRAM:
		MYPRINTF("[RECV] CS_CONTACT_ALRAM PACKET !");
		contactAlramPacket.ParseFromArray(buf, size);

		textFormat = roomCreatePacket.DebugString();
		MYPRINTF(textFormat.c_str());


		break;
	case protocol::PacketType::CS_ROOM_CREATE:
		MYPRINTF("[RECV] CS_ROOM_CREATE PACKET !");
		roomCreatePacket.ParseFromArray(buf, size);
		
		textFormat = roomCreatePacket.DebugString();
		MYPRINTF(textFormat.c_str());

		break;
	case protocol::PacketType::CS_ROOM_JOIN:
		MYPRINTF("[RECV] CS_ROOM_JOIN PACKET !");
		roomJoinPacket.ParseFromArray(buf, size);

		textFormat = roomCreatePacket.DebugString();
		MYPRINTF(textFormat.c_str());
		
		break;
	case protocol::PacketType::CS_ROOM_LEAVE:
		MYPRINTF("[RECV] CS_ROOM_LEAVE PACKET !");
		roomLeavePacket.ParseFromArray(buf, size);

		textFormat = roomCreatePacket.DebugString();
		MYPRINTF(textFormat.c_str());
		
		break;
	case protocol::PacketType::CS_ROOM_INFO_REQUEST:
		MYPRINTF("[RECV] CS_ROOM_INFO_REQUEST PACKET !");
		roomInfoRequestPacket.ParseFromArray(buf, size);

		textFormat = roomCreatePacket.DebugString();
		MYPRINTF(textFormat.c_str());
		
		break;
	case protocol::PacketType::CS_REQUEST_INGAME_START:
		MYPRINTF("[RECV] CS_REQUEST_INGAME_START PACKET !");
		ingameStartPacket.ParseFromArray(buf, size);

		textFormat = roomCreatePacket.DebugString();
		MYPRINTF(textFormat.c_str());
		
		break;
	case protocol::PacketType::CS_SEND_BASEBALL_NUMBER:
		MYPRINTF("[RECV] CS_SEND_BASEBALL_NUMBER PACKET !");
		sendBaseballNumPacket.ParseFromArray(buf, size);

		textFormat = roomCreatePacket.DebugString();
		MYPRINTF(textFormat.c_str());
		
		break;
	}
}

void CClientSocket::RecvProcess(bool isError, CAct* act, DWORD bytes_transferred)
{
	if (isError){
		MYPRINTF("Disconnect in Receiver ProcEvent() \n");
		Disconnect();
		return;
	}

	if (0 == bytes_transferred)
	{
		MYPRINTF("Disconnect in Receiver ProcEvent() \n");
		Disconnect();
		return;
	}

	bytePosition += bytes_transferred;
	remainBytes -= bytes_transferred;

	printf("[RECV] %d bytes_transferred\n", bytes_transferred);

	char* buf = this->recvBuf;

	if (bytePosition < HEADER_SIZE)
	{
		this->Recv(buf + bytePosition, remainBytes);
	}
	else
	{
		if (bytePosition == HEADER_SIZE)
		{
			protocol::PacketHeader header;
			header.ParseFromArray(buf, HEADER_SIZE);
		
			payloadSize = header.size();
			
			if (payloadSize != 0)
				remainBytes = payloadSize;

			payloadType = header.type();
		}
		
		if (remainBytes <= 0)
		{
			bytePosition = 0;
			remainBytes = HEADER_SIZE;
			
			PacketHandling(buf, this->payloadType, this->payloadSize);
		}

		this->Recv(buf, remainBytes);
	}
}

void CClientSocket::SendProcess(bool isError, CAct* act, DWORD bytes_transferred)
{

}

void CClientSocket::AcceptProcess(bool isError, CAct* act, DWORD bytes_transferred)
{
	if (!isError)
	{
		MYPRINTF("Connect Client Success, %d\n", this->socket_);

		CClientManager::GetInstance().AddUser(this);

		Recv(this->recvBuf, HEADER_SIZE);
	}
	else
	{
		MYPRINTF("Client Socket AcceptProcess : Error : %d\n", WSAGetLastError());
	}

}

void CClientSocket::DisconnProcess(bool isError, CAct* act, DWORD bytes_transferred)
{
	if (!isError)
	{
		MYPRINTF("Disconnect Client Success, %d\n", this->socket_);

		CClientManager::GetInstance().DeleteUser(this);
	}
	else
	{

	}


}
void CClientSocket::ConnProcess(bool isError, CAct* act, DWORD bytes_transferred)
{


}