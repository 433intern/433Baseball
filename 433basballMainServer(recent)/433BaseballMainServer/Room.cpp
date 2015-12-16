#include "stdafx.h"
#include "Room.h"


CRoom::CRoom(int roomNumber)
:roomNum(roomNumber),
 currWhoTurn(-1),
 roomState(ROOM_STATE::WAIT)
{
	InitializeCriticalSectionAndSpinCount(&playerLock, 4000);
}


CRoom::~CRoom()
{
	DeleteCriticalSection(&playerLock);
}

void CRoom::EnterPlayer(CClientSocket* pPlayer)
{
	EnterCriticalSection(&playerLock);
	if (MAX_ROOM_PLAYERS > players.size())
	{
		if (MAX_ROOM_PLAYERS == players.size())
			roomState = ROOM_STATE::FULL;

		pPlayer->currRoomNum = roomNum;
		pPlayer->currState = CClientSocket::PLAYER_STATE::INROOM;

		EnterCriticalSection(&playerLock);
		players.push_back(pPlayer);
	}
	LeaveCriticalSection(&playerLock);
}

void CRoom::LeavePlayer(CClientSocket* pPlayer)
{
	EnterCriticalSection(&playerLock);

	bool check = false;
	if (0 < players.size())
	{
		if (MAX_ROOM_PLAYERS > players.size())
			roomState = ROOM_STATE::WAIT;

		for (auto& player : players)
		{
			if (player->nickName == pPlayer->nickName)
			{
				check = true;
				break;
			}
		}

		if (!check) 
		{
			LeaveCriticalSection(&playerLock);
			return;
		}

		players.remove(pPlayer);
	}
	LeaveCriticalSection(&playerLock);
	
	SendRoomSync();

}

void CRoom::SendRoomSync()
{
	EnterCriticalSection(&playerLock);
	if (players.size() == 0)
	{
		LeaveCriticalSection(&playerLock);
		return;
	}

	protocol::PacketHeader header;

	protocol::SC_room_info roomInfoPkt;
	
	for (const auto& player : players)
	{
		std::string* dummyNickName = roomInfoPkt.add_playernicknames();
		*dummyNickName = player->nickName;
	}

	header.set_size(roomInfoPkt.ByteSize());
	header.set_type(protocol::PacketType::SC_ROOM_INFO);

	for (const auto& player : players)
	{
		header.SerializeToArray(player->sendBuf, HEADER_SIZE);

		roomInfoPkt.SerializeToArray(player->sendBuf + header.ByteSize(), roomInfoPkt.ByteSize());

		player->Send(player->sendBuf, header.ByteSize() + roomInfoPkt.ByteSize());
	}
	
	LeaveCriticalSection(&playerLock);
}

void CRoom::GameStart()
{


}