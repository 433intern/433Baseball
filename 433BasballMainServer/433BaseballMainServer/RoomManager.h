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
	int		CreateRoom(int roomNum);
	int		DestroyRoom(int roomNuem);
	CRoom*  FindRoom(int roomNum);

	int		EnterRoom(CClientSocket* pPlayer, int roomNum);
	bool	LeaveRoom(CClientSocket* pPlayer, int roomNum);

	void	SendTotalRoomInfo(CClientSocket* pPlayer);
	void	TotalRoomInfoPrint();
};

