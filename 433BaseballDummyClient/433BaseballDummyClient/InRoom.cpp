#include "stdafx.h"

bool InRoom()
{
	CGlobalManager &globalManager = CGlobalManager::GetInstance();
	protocol::PacketHeader header;
	std::string choosing;
	char tmpChar;

	PLAYER_STATE &playerState = globalManager.playerState;

	SOCKET &sock = globalManager.sock;

	bool loopForChoose = true;

	while (loopForChoose)
	{
		cout << "[InRoom]room info request||leave||game start('r'||'l'||'s') :";
		cin >> choosing;

		tmpChar = choosing.c_str()[0];

		if ('r' == tmpChar || 'R' == tmpChar)
		{
			protocol::SC_room_info roomInfo;

			if (!PingPongMsg(sock, 0, protocol::PacketType::CS_ROOM_INFO_REQUEST,
				header, NULL, roomInfo))
			{
				printf("PingPongMsg in Inroom error !\n");
				return false;
			}

			cout << "Your enemy : " << roomInfo.playernicknames << endl;
		}
		else if ('s' == tmpChar || 'S' == tmpChar)
		{
			protocol::SC_ingame_start_result ingameStartResult;

			if (!PingPongMsg(sock, 0, protocol::PacketType::CS_REQUEST_INGAME_START,
				header, NULL, ingameStartResult))
			{
				printf("PingPongMsg in Inroom error !\n");
				return false;
			}
			if (!interpretFailSignal(ingameStartResult.failsignal()))
			{
				return false;
			}
			playerState = PLAYER_STATE::INGAME;
			break;
		}
		else if ('l' == tmpChar || 'L' == tmpChar)
		{
			protocol::SC_room_leave_result roomLeaveResult;

			if (!PingPongMsg(sock, 0, protocol::PacketType::CS_ROOM_LEAVE,
				header, NULL, roomLeaveResult))
			{
				printf("PingPongMsg in Inroom error !\n");
				return false;
			}
			if (!interpretFailSignal(roomLeaveResult.failsignal()))
			{
				return false;
			}
			playerState = PLAYER_STATE::LOBBY;
			break;
		}
	}

	return true;
}