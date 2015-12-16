#include "stdafx.h"

void err_quit(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, (LPCWSTR)msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}

void err_display(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[%s] %s", msg, (char *)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

int recvn(SOCKET s, char *buf, int len, int flags)
{
	int received;
	char *ptr = buf;
	int left = len;

	while (left > 0){
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}

	return (len - left);
}

int main(int argc, char *argv[])
{
	int retval;

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) err_quit("socket()");

	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit("connect()");

	printf("커넥션이 이루어졌습니다.\n");

	char buf[BUFSIZE + 1];
	int len;

	while (1){
		protocol::PacketHeader header;
		protocol::CS_room_create roomCreate;
		protocol::CS_room_join roomJoin;

		string id, password;
		string buffer;

		std::string createOrJoin;
		char tmpChar;

		bool loopForCreateOrJoin = true;

		cout << "[Loin]" << endl;
		cout << "ID input : ";
		cin >> id;

		cout << "Password input : ";
		cin >> password;

		while (loopForCreateOrJoin)
		{
			cout << "create or join (input 'c' or 'j') : ";
			cin >> createOrJoin;

			tmpChar = createOrJoin.c_str()[0];

			if (tmpChar == 'c' || tmpChar == 'j')
			{
				loopForCreateOrJoin = false;
			}
		}

		switch (tmpChar)
		{
		case 'c':
			{
				header.set_size(roomCreate.ByteSize());
				header.set_type(protocol::PacketType::CS_ROOM_CREATE);
			}
			break;
		case 'j':
			{
				header.set_size(roomJoin.ByteSize());
				header.set_type(protocol::PacketType::CS_ROOM_JOIN);
			}
			break;
		}

		//int bufSize = header.ByteSize();
		//header.SerializeToArray(&buffer, bufSize);

		//// Sending header
		//retval = send(sock, buffer.data(), bufSize, 0);
		//if (retval == SOCKET_ERROR){
		//	err_display("header send()");
		//	break;
		//}
		//printf("헤더 %d바이트를 보냈습니다.\n", retval);

		//bufSize = login.ByteSize();
		//login.SerializeToArray(&buffer, bufSize);

		//// Sending payload
		//retval = send(sock, buffer.data(), bufSize, 0);
		//if (retval == SOCKET_ERROR){
		//	err_display("body send()");
		//	break;
		//}
		//printf("몸통 %d바이트를 보냈습니다.\n", retval);

		//system("pause");
	}

	closesocket(sock);

	WSACleanup();
	return 0;
}