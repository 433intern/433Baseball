#include "stdafx.h"
#include "RoomManager.h"


CRoomManager::CRoomManager()
{
	InitializeCriticalSectionAndSpinCount(&roomLock, 4000);
}


CRoomManager::~CRoomManager()
{
	DeleteCriticalSection(&roomLock);
}


int CRoomManager::CreateRoom(int roomNum)
{
	EnterCriticalSection(&roomLock);
	if (MAX_ROOMS < rooms.size())
	{
		LeaveCriticalSection(&roomLock);
		return 0;
	}
	else
	{
		std::list<CRoom*>::iterator insertIter = rooms.begin();
		for (; insertIter != rooms.end(); ++insertIter)
		{
			if ((*insertIter)->GetRoomNumber() < roomNum) continue;
			else if ((*insertIter)->GetRoomNumber() == roomNum)
			{
				LeaveCriticalSection(&roomLock);
				return 1;
			}
			else
			{
				break;
			}
		}

		CRoom* room = new CRoom(roomNum);
		rooms.insert(insertIter, room);
		LeaveCriticalSection(&roomLock);
	}
	TotalRoomInfoPrint();
	return -1;
}

int CRoomManager::DestroyRoom(int roomNum)
{
	CRoom* room = FindRoom(roomNum);
	if (room == nullptr)
	{
		return 0;
	}

	EnterCriticalSection(&roomLock);
	
	rooms.remove(room);

	LeaveCriticalSection(&roomLock);
		
	TotalRoomInfoPrint();

	return -1;

}

CRoom* CRoomManager::FindRoom(int roomNum)
{
	if (roomNum == -1) return nullptr;

	CRoom* room = nullptr;
	
	EnterCriticalSection(&roomLock);

	auto finder = std::find_if(rooms.begin(), 
							   rooms.end(), 
							   [&](CRoom* room){ return room->GetRoomNumber() == roomNum;}
	);

	room = *finder;
	
	LeaveCriticalSection(&roomLock);

	return room;
}

int CRoomManager::EnterRoom(CClientSocket* pPlayer, int roomNum)
{
	CRoom* room = FindRoom(roomNum);
	if (room == nullptr)
		return 0; 
	if (MAX_ROOM_PLAYERS >= room->InRoomPlayerSize())
		return 1;

	EnterCriticalSection(&roomLock);
	
	room->EnterPlayer(pPlayer);

	LeaveCriticalSection(&roomLock);
	
	TotalRoomInfoPrint();
}

bool CRoomManager::LeaveRoom(CClientSocket* pPlayer, int roomNum)
{
	CRoom* room = FindRoom(roomNum);

	if (room == nullptr)
	{
		return false;
	}

	EnterCriticalSection(&roomLock);

	room->LeavePlayer(pPlayer);
	
	LeaveCriticalSection(&roomLock);

	TotalRoomInfoPrint();

	return true;
}



void CRoomManager::SendTotalRoomInfo(CClientSocket* pPlayer)
{
	EnterCriticalSection(&roomLock);
	protocol::PacketHeader header; 
	protocol::SC_total_room_info totalRoomInfoPkt;

	char* buf = pPlayer->sendBuf;

	for (auto& room : rooms)
	{
		protocol::RoomInfo* roomInfo = totalRoomInfoPkt.add_roomlist();
		roomInfo->set_roomnum(room->GetRoomNumber());
	}
	header.set_type(protocol::PacketType::SC_TOTAL_ROOM_INFO);
	header.set_size(totalRoomInfoPkt.ByteSize());
	
	header.SerializeToArray(buf, HEADER_SIZE);
	totalRoomInfoPkt.SerializeToArray(buf + header.ByteSize(), totalRoomInfoPkt.ByteSize());

	pPlayer->Send(buf, header.ByteSize() + totalRoomInfoPkt.ByteSize());

	LeaveCriticalSection(&roomLock);

}

void CRoomManager::TotalRoomInfoPrint()
{
	printf("[Room Manager] Current Room Total Info\n");

	EnterCriticalSection(&roomLock);
	for (const auto& room : rooms)
	{
		printf("[%d] Room : %d Joined in Room\n", room->GetRoomNumber(), room->InRoomPlayerSize());
	}
	LeaveCriticalSection(&roomLock);

}