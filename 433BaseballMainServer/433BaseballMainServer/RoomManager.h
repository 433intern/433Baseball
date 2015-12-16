#pragma once

class CRoomManager
{
	std::list<CRoom*> rooms;
	CRITICAL_SECTION roomLock;
	CRoomManager();
public:
	
	static CRoomManager &GetInstance();
	~CRoomManager();
	
public:
	int		CreateRoom(int roomNum);
	int		DestroyRoom(int roomNuem);
	CRoom*  FindRoom(int roomNum);

	int		EnterRoom(CClientSocket* pPlayer, int roomNum);
	bool	LeaveRoom(CClientSocket* pPlayer, int roomNum);

	void	SendTotalRoomInfo(CClientSocket* pPlayer);
	void	TotalRoomInfoPrint();
};

