#include "stdafx.h"

int main(int argc, char *argv[])
{
	CGlobalManager &globalManager = CGlobalManager::GetInstance();

	int retval;
	WSADATA wsa;
	char buf[BUFSIZE];
	int len;
	SOCKADDR_IN serveraddr;

	string id, password;

	std::string createOrJoin, securityCode;
	char tmpChar;

	bool loopForCreateOrJoin = true;

	SOCKET &sock = globalManager.sock;
	securityCode = globalManager.securityCode;

	PLAYER_STATE &playerState = globalManager.playerState;
	playerState = PLAYER_STATE::LOBBY;

	//--------------------------------------------
	// Connecting to MainServer

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) err_quit("socket()");

	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit("connect()");

	//--------------------------------------------

	printf("connected !!\n");

	cout << "[Login]" << endl;
	cout << "ID input : ";
	cin >> id;

	cout << "Password input : ";
	cin >> password;

	// Always Login Success ~!

	while (1)
	{
		//--------------------------------------------------------
		// This Client's Contact Alarm to MainServer
		protocol::CS_contact_alram contactAlram;
		protocol::SC_contact_result contactResult;
		protocol::PacketHeader header;

		contactAlram.set_nickname(id);
		contactAlram.set_securitycode(securityCode);

		if (!PingPongMsg(sock, contactAlram.ByteSize(), protocol::PacketType::CS_CONTACT_ALRAM, 
			header, &contactAlram, contactResult))
		{
			printf("PingPongMsg error about contact alarm on main\n");
			return -1;
		}
		if (!interpretFailSignal(contactResult.failsignal()))
		{
			return false;
		}
		//--------------------------------------------------------

		//--------------------------------------------------------
		// Receiving All Rooms informations and display
		protocol::SC_total_room_info roomInfo;
		protocol::PacketHeader header;

		if (!PingPongMsg(sock, 0, protocol::PacketType::CS_TOTAL_ROOM_INFO_REQUEST,
			header, NULL, roomInfo))
		{
			printf("PingPongMsg error about roominfo on main\n");
			return -1;
		}

		ShowAllCurrentRooms(roomInfo);
		//--------------------------------------------------------

		switch (playerState)
		{
		case PLAYER_STATE::LOBBY:
			if (!InLobby())
			{
				printf("Error in lobby !!\n");
				return -1;
			}
			break;
		case PLAYER_STATE::INGAME:
			if (!InGame())
			{
				printf("Error in ingame !!\n");
				return -1;
			}
			break;
		case PLAYER_STATE::INROOM:
			if (!InRoom())
			{
				printf("Error in inroom !!\n");
				return -1;
			}
			break;
		default:
			printf("Error on playerstate switch\n");
			return -1;
		}
	}

	closesocket(sock);

	WSACleanup();
	return 0;
}