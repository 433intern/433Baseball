#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SYSTEM_INFO			systemInfo;

	CDBManager			*dbManager		= new CDBManager("127.0.0.1", "root", "1234", "433Baseball");
	CClientManager		*clientManager	= new CClientManager();

	CGlobalManager &global = CGlobalManager::GetInstance();
	
	global.clientManager = clientManager;
	global.dbManager = dbManager;

	WSADATA				wsa;

	if (NULL != WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		MYPRINTF("Error on WSAStartup in _tmain : %d\n", WSAGetLastError());
		return 0;
	}

	GetSystemInfo(&systemInfo);

	if (!clientManager->Initializer(systemInfo.dwNumberOfProcessors << 1, SOCKET_POOL_SIZE, SERVERPORT))
	{
		MYPRINTF("error in Initializer : %d\n", GetLastError());
		return 0;
	}

	// thread pool size for DB, DB handle pool size
	// These handles must be dynamically resized by the number of clients !
	if (!dbManager->Initializer(4, 8))
	{
	MYPRINTF("error in Initializer : %d\n", GetLastError());
	return 0;
	}

	std::string command;
	//------------------------------------
	// test code
	while (1)
	{
		std::getline(std::cin, command);
		dbManager->QueryEx(command.c_str());
	}
	//------------------------------------

	Sleep(INFINITE);

	WSACleanup();

	return 1;
}

