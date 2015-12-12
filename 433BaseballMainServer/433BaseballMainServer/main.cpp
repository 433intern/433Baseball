#include "stdafx.h"

bool TotalInitializer()
{
	SYSTEM_INFO		systemInfo;

	CDBManager		&dbManager = CDBManager::GetInstance();
	CClientManager	&clientManager = CClientManager::GetInstance();

	GetSystemInfo(&systemInfo);

	if (!clientManager.FirstInitializer())
	{
		MYPRINTF("error in Initializer : %d\n", GetLastError());
		return 0;
	}

	if (!clientManager.SecondInitializer(systemInfo.dwNumberOfProcessors << 1, SOCKET_POOL_SIZE, SERVERPORT))
	{
		MYPRINTF("error in Initializer : %d\n", GetLastError());
		return 0;
	}

	if (!dbManager.FirstInitializer("127.0.0.1", "root", "1234", "playerstastic"))
	{
		MYPRINTF("error on FirstInitializer in _tmain : %d\n", GetLastError());
		return 0;
	}

	// thread pool size for DB, DB handle pool size
	// These handles must be dynamically resized by the number of clients !
	if (!dbManager.SecondInitializer(4, 8))
	{
		MYPRINTF("error on SecondInitializer in _tmain : %d\n", GetLastError());
		return 0;
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CDBManager		&dbManager		= CDBManager::GetInstance();
	CClientManager	&clientManager	= CClientManager::GetInstance();
	CGlobalManager	&global			= CGlobalManager::GetInstance();

	WSADATA				wsa;

	if (NULL != WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		MYPRINTF("Error on WSAStartup in _tmain : %d\n", WSAGetLastError());
		return 0;
	}

	TotalInitializer();

	std::string command;
	//------------------------------------
	// test code

	while (1)
	{
		std::getline(std::cin, command);
		dbManager.QueryEx(command.c_str());
	}
	//------------------------------------

	Sleep(INFINITE);

	WSACleanup();

	return 1;
}

