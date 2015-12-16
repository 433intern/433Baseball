#include "stdafx.h"

void ShowAllCurrentRooms(const protocol::SC_total_room_info &roomInfo)
{
	cout << " < Current Rooms List >" << endl;
	protobuf::RepeatedPtrField<protocol::RoomInfo> tmpRepeat = roomInfo.roomlist();
	for (protocol::RoomInfo &aRoom : tmpRepeat)
	{
		cout << aRoom.roomnum << '/';
	}
	cout << endl;
}

bool SendingMessage(SOCKET &sock, int byteSize, protocol::PacketType type, protobuf::Message &messageToSend)
{
	string buffer;

	int bufSize = messageToSend.ByteSize();

	messageToSend.SerializeToArray(&buffer, bufSize);

	// Sending header
	int retval = send(sock, buffer.data(), bufSize, 0);
	if (retval == SOCKET_ERROR){
		err_display("header send()");
		return false;
	}
	printf("header %d bytes were sent.\n", retval);
	return true;
}

bool ReceivingMessage(SOCKET &sock, int byteSize, protobuf::Message &message)
{
	char buf[BUFSIZE];

	int receivedBytes = recvn(sock, buf, byteSize, 0);

	if (!message.ParseFromArray(buf, byteSize))
	{
		return false;
	}
	return true;
}

bool PingPongMsg(SOCKET &sock, int sentBytes, const protocol::PacketType &type, protocol::PacketHeader &header, protobuf::Message *messageToSend,protobuf::Message &resultMessage)
{
	header.set_size(sentBytes);
	header.set_type(type);

	if (!SendingMessage(sock, HEADERSIZE, type, *messageToSend))
	{
		printf("SendingMessage Error - header");
		return false;
	}

	if (NULL != messageToSend)
	{
		if (!SendingMessage(sock, sentBytes, type, *messageToSend))
		{
			printf("SendingMessage Error - payload");
			return false;
		}
	}

	if (!ReceivingMessage(sock, HEADERSIZE, header))
	{
		printf("ReceivingMessage Error - header\n");
		return false;
	}

	if (!ReceivingMessage(sock, header.size(), resultMessage))
	{
		printf("ReceivingMessage Error - payload\n");
		return false;
	}

	return true;
}

bool interpretFailSignal(const protocol::FailSignal &fail)
{
	switch (fail)
	{
	case protocol::FailSignal::EXIST_REPETITION_NUMBER:
		printf("FailSignal::EXIST_REPETITION_NUMBER\n");
		return false;
	case protocol::FailSignal::FULL_ROOM:
		printf("FailSignal::FULL_ROOM\n");
		return false;
	case protocol::FailSignal::NO_EXIST:
		printf("FailSignal::NO_EXIST\n");
		return false;
	case protocol::FailSignal::SUCCESS:
		return true;
	default:
		printf("Trash value on interpreFailSignal\n");
		return false;
	}
}