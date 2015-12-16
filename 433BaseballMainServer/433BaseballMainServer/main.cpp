#include "stdafx.h"

SERVICE_STATUS					serviceStatus = { 0 };
SERVICE_STATUS_HANDLE			statusHandle = NULL;
HANDLE							serviceStopEvent = INVALID_HANDLE_VALUE;

#ifndef _DEBUG
VOID	__stdcall	ServiceMain(DWORD argc, LPTSTR *argv);
VOID	__stdcall	ServiceCtrlHandler(DWORD);
bool				ServiceInit();
bool				SetService(const DWORD controlAccepted, const DWORD currentState, const DWORD win32ExitCode, const DWORD checkPoint);
#endif

bool				TotalInitializer();

#define SERVICE_NAME	_T("433MainServer")

bool RealMain()
{
	MYPRINTF("[Game Server] Start\n");
	CDBManager		&dbManager = CDBManager::GetInstance();
	CClientManager	&clientManager = CClientManager::GetInstance();
	CGlobalManager	&global = CGlobalManager::GetInstance();
	CRoomManager	&roomManager = CRoomManager::GetInstance();

	WSADATA				wsa;

	std::string		tmpIp, tmpSchema, tmpDBUserName, tmpDBPassword;
	std::string		tmpStasticalTableName, tmpMatchRecordTableName, tmpOverloadRecordTableName;
	unsigned short  tmpDBPort = 0, tmpMainServerPort = 0;

	std::ifstream	file;

	file.open("433Baseball_config.cfg");

	if (!file)
	{
		MYPRINTF("File openning failed no RealMain");
		return false;
	}

	try
	{
		file >> tmpIp >> tmpDBPort >> tmpSchema >> tmpStasticalTableName >> tmpMatchRecordTableName
			>> tmpOverloadRecordTableName >> tmpDBUserName >> tmpDBPassword >> tmpMainServerPort;
	}
	catch (const std::ifstream::failure &e)
	{
		MYSERVICEERRORPRINTF("ifstream read failed on realmain function : %s", e.what());
		return false;
	}

	if (!global.Initializer(tmpIp, tmpDBPort, tmpSchema, tmpStasticalTableName, tmpMatchRecordTableName,
		tmpOverloadRecordTableName, tmpDBUserName, tmpDBPassword, tmpMainServerPort))
	{
		MYSERVICEERRORPRINTF("Initializer of CGlobalManager error");
		return false;
	}

	if (NULL != WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		MYSERVICEERRORPRINTF("WSAStartup");
		return false;
	}

	if (!TotalInitializer())
	{
		MYSERVICEERRORPRINTF("TotalInitializer");
		return false;
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef _DEBUG
	if (!RealMain())
	{
		MYSERVICEERRORPRINTF("RealMain");
		return -1;
	}
	Sleep(INFINITE);
#else
	SERVICE_TABLE_ENTRY serviceTable[] =
	{
		{ SERVICE_NAME, (LPSERVICE_MAIN_FUNCTION)ServiceMain },
		{ NULL, NULL }
	};

	if (FALSE == StartServiceCtrlDispatcher(serviceTable))
	{
		return GetLastError();
	}
#endif
	return 0;
}

#ifndef _DEBUG
VOID __stdcall ServiceMain(DWORD argc, LPTSTR *argv)
{
	DWORD status = E_FAIL;

	statusHandle = RegisterServiceCtrlHandler(SERVICE_NAME, ServiceCtrlHandler);

	if (NULL == statusHandle)
	{
		MYPRINTF("RegisterServiceCtrlHandler's return value is null : %u", WSAGetLastError());
		return;
	}

	if (!ServiceInit())
		return;

	//--------------------------------------------------------------
	// Perform tasks necessary to start the service here !

	if (!RealMain())
	{
		MYSERVICEERRORPRINTF("RealMain");
		return;
	}

	//--------------------------------------------------------------

	serviceStopEvent = CreateEvent(NULL, TRUE, FALSE, L"433_Main_KillServer");

	if (NULL == serviceStopEvent)
	{
		if (!SetService(0, SERVICE_STOPPED, GetLastError(), 1))
			return;
	}

	if (!SetService(SERVICE_ACCEPT_STOP, SERVICE_RUNNING, 0, 0))
		return;

	DWORD result = WaitForSingleObject(serviceStopEvent, INFINITE);
	if (WAIT_FAILED == result)
	{
		MYSERVICEERRORPRINTF("WaitForSingleObject");
		return;
	}

	// Perform any cleanup tasks here !

	CloseHandle(serviceStopEvent);

	if (!SetService(0, SERVICE_STOPPED, 0, 3))
		return;

	return;
}

VOID __stdcall ServiceCtrlHandler(DWORD ctrlCode)
{
	switch (ctrlCode)
	{
	case SERVICE_CONTROL_STOP:
		if (serviceStatus.dwCurrentState != SERVICE_RUNNING)
			break;

		// Perform tasks necessary to stop the service here !

		if (!SetService(0, SERVICE_STOP_PENDING, 0, 4))
			return;

		SetEvent(serviceStopEvent);
		break;
	default:
		break;
	}
}

bool ServiceInit()
{
	memset(&serviceStatus, 0, sizeof(serviceStatus));
	serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	serviceStatus.dwControlsAccepted = 0;
	serviceStatus.dwCurrentState = SERVICE_START_PENDING;
	serviceStatus.dwWin32ExitCode = 0;
	serviceStatus.dwServiceSpecificExitCode = 0;
	serviceStatus.dwCheckPoint = 0;

	if (FALSE == SetServiceStatus(statusHandle, &serviceStatus))
	{
		MYSERVICEERRORPRINTF("ServiceInit()");
		return false;
	}

	return true;
}

bool SetService(const DWORD controlAccepted, const DWORD currentState,
	const DWORD win32ExitCode, const DWORD checkPoint)
{
	serviceStatus.dwControlsAccepted = controlAccepted;
	serviceStatus.dwCurrentState = currentState;
	serviceStatus.dwWin32ExitCode = win32ExitCode;
	serviceStatus.dwCheckPoint = checkPoint;

	if (FALSE == SetServiceStatus(statusHandle, &serviceStatus))
	{
		MYSERVICEERRORPRINTF("SetService");
		return false;
	}
	return true;
}
#endif

bool TotalInitializer()
{
	SYSTEM_INFO		systemInfo;

	CDBManager		&dbManager = CDBManager::GetInstance();
	CClientManager	&clientManager = CClientManager::GetInstance();
	CGlobalManager	&globalManager = CGlobalManager::GetInstance();

	GetSystemInfo(&systemInfo);

	if (!clientManager.FirstInitializer())
	{
		MYPRINTF("error in Initializer : %d\n", GetLastError());
		return false;
	}

	if (!clientManager.SecondInitializer(systemInfo.dwNumberOfProcessors << 1, SOCKET_POOL_SIZE, globalManager.mainServerPort))
	{
		MYPRINTF("error in Initializer : %d\n", GetLastError());
		return false;
	}

	if (!dbManager.FirstInitializer(globalManager.dbServerIp, globalManager.dbUsername,
		globalManager.dbPassword, globalManager.dbSchemaName))
	{
		MYPRINTF("error on FirstInitializer in _tmain : %d\n", GetLastError());
		return false;
	}

	// thread pool size for DB, DB handle pool size
	// These handles must be dynamically resized by the number of clients !
	if (!dbManager.SecondInitializer(DB_THREAD_POOL_SIZE, DB_HANDLE_POOL_SIZE))
	{
		MYPRINTF("error on SecondInitializer in _tmain : %d\n", GetLastError());
		return false;
	}

	return true;
}

