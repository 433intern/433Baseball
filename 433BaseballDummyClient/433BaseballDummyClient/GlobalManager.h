#pragma once
class CGlobalManager
{
	CGlobalManager();
public:
	SOCKET sock;

	PLAYER_STATE playerState;

	std::string securityCode;

	static CGlobalManager &GetInstance();
	~CGlobalManager();
};

