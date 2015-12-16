#include "stdafx.h"

bool InGame()
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
		cout << "[InGame]exit to lobby-'q'):";
		cin >> choosing;

		tmpChar = choosing.c_str()[0];

		if ('c' == tmpChar || 'C' == tmpChar)
		{
		}
		else if ('j' == tmpChar || 'J' == tmpChar)
		{
		}
		else if ('q' == tmpChar || 'Q' == tmpChar)
		{
		}
	}

	return true;
}