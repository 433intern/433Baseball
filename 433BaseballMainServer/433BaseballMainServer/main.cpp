#include "stdafx.h"

CGlobalManager *globalManager;

int _tmain(int argc, _TCHAR* argv[])
{
	SYSTEM_INFO			systemInfo;
	CDBManager			dbManager;
	CClientManager		clientManager;

	WSADATA				wsa;

	if (NULL != WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		MYPRINTF("Error on WSAStartup in _tmain : %d\n", WSAGetLastError());
		return 0;
	}
	
	globalManager = new CGlobalManager();

	GetSystemInfo(&systemInfo);

	if (!dbManager.Initializer(systemInfo.dwNumberOfProcessors << 1))
	{
		MYPRINTF("error in Initializer : %d\n", GetLastError());
		return 0;
	}

	if (!clientManager.Initializer(systemInfo.dwNumberOfProcessors << 1))
	{
		MYPRINTF("error in Initializer : %d\n", GetLastError());
		return 0;
	}

	//------------------------------------

	//------------------------------------

	Sleep(INFINITE);

	delete globalManager;

	WSACleanup();

	return 1;
}

