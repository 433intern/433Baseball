#pragma once
class CRoom
{
public:
	enum ROOM_STATE
	{
		WAIT,
		FULL,
		INGAME
	};

private:
	std::list<CClientSocket*> players;

	int roomNum;
	int inputBaseballNum[MAX_ROOM_PLAYERS];
	int checkBaseballNum[MAX_ROOM_PLAYERS];

	short currWhoTurn;
	
	CRITICAL_SECTION playerLock;

	short roomState;

public:
	CRoom(int roomNum);
	~CRoom();

public:
	void EnterPlayer(CClientSocket* pPlayer);
	void LeavePlayer(CClientSocket* pPlayer);
	void SendRoomSync();
	void GameStart();

	int InRoomPlayerSize() { return players.size(); }
	int GetRoomNumber() { return roomNum; }
	

};

