#include "stdafx.h"

bool InLobby()
{
	CGlobalManager &globalManager = CGlobalManager::GetInstance();
	protocol::PacketHeader header;
	std::string createOrJoin;
	char tmpChar;
	int tmpRoomNum;

	PLAYER_STATE &playerState = globalManager.playerState;

	SOCKET &sock = globalManager.sock;

	bool loopForChoose = true;

	while (loopForChoose)
	{
		cout << "[Lobby]create||join('c'||'j'),exit-'q'):";
		cin >> createOrJoin;

		tmpChar = createOrJoin.c_str()[0];

		if ('c' == tmpChar || 'C' == tmpChar)
		{
			protocol::CS_room_create roomCreate;
			protocol::SC_room_create_result roomCreateResult;

			cout << "[Lobby]input room num to create : ";
			cin >> tmpRoomNum;

			roomCreate.set_roomnum(tmpRoomNum);

			if (!PingPongMsg(sock, roomCreate.ByteSize(), protocol::PacketType::CS_ROOM_CREATE, 
				header, &roomCreate, roomCreateResult))
			{
				printf("PingPongMsg error about roomCreate on main\n");
				return false;
			}

			if (!interpretFailSignal(roomCreateResult.failsignal()))
			{
				return false;
			}
			printf("Creating room success !!\n");
		}
		else if ('j' == tmpChar || 'J' == tmpChar)
		{
			protocol::CS_room_join roomJoin;
			protocol::SC_room_join_result roomJoinResult;

			cout << "[Lobby]input room num to join : ";
			cin >> tmpRoomNum;

			roomJoin.set_roomnum(tmpRoomNum);

			if (!PingPongMsg(sock, roomJoin.ByteSize(), protocol::PacketType::CS_ROOM_JOIN,
				header, &roomJoin, roomJoinResult))
			{
				printf("PingPongMsg error about roomJoin on main\n");
				return false;
			}

			if (!interpretFailSignal(roomJoinResult.failsignal()))
			{
				return false;
			}
			printf("Joinning the room success !!\n");

			playerState = PLAYER_STATE::INROOM;
			break;
		}
		else if ('q' == tmpChar || 'Q' == tmpChar)
		{
			exit(1);
		}
	}

	return true;
}