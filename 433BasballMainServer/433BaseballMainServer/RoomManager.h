#pragma once

class CRoomManager
{
private:
	std::list<CRoom*> rooms;
	CRITICAL_SECTION roomLock;

public:
	CRoomManager();
	~CRoomManager();
	
public:
	protocol::FailSignal	CreateRoom(int roomNum);
	protocol::FailSignal	DestroyRoom(int roomNuem);
	
	CRoom*					FindRoom(int roomNum);

	protocol::FailSignal	EnterRoom(CClientSocket* pPlayer, int roomNum);
	bool					LeaveRoom(CClientSocket* pPlayer, int roomNum);

	void					SendTotalRoomInfo(CClientSocket* pPlayer);
	void					SendCreateRoomAck(CClientSocket* pPlayer, int roomNum , protocol::FailSignal fs);


	void					TotalRoomInfoPrint();
};

