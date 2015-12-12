#include "stdafx.h"

SERVICE_STATUS					serviceStatus = { 0 };
SERVICE_STATUS_HANDLE			statusHandle = NULL;
HANDLE							serviceStopEvent = INVALID_HANDLE_VALUE;

VOID	__stdcall	ServiceMain(DWORD argc, LPTSTR *argv);
VOID	__stdcall	ServiceCtrlHandler(DWORD);
DWORD	__stdcall	ServiceWorkerThread(LPVOID lpParam);

#define SERVICE_NAME _T("433LoginServer")
#define DEBUGSTR(A) OutputDebugString(_T(A))
#define STR1 "433_Baseball_Login_Server : ServiceMain : SetServiceStatus returned error"
#define STR2 "433_Baseball_Login_Server : ServiceCtrlHandler : SetServiceStatus returned error"

int _tmain(int argc, TCHAR *argv[])
{
	SERVICE_TABLE_ENTRY serviceTable[] =
	{
		{ SERVICE_NAME, (LPSERVICE_MAIN_FUNCTION) ServiceMain },
		{ NULL, NULL }
	};

	if (FALSE == StartServiceCtrlDispatcher(serviceTable))
	{
		return GetLastError();
	}

	return 0;
}

VOID __stdcall ServiceMain(DWORD argc, LPTSTR *argv)
{
	DWORD status = E_FAIL;

	statusHandle = RegisterServiceCtrlHandler(SERVICE_NAME, ServiceCtrlHandler);

	if (NULL == statusHandle)
	{
		return;
	}

	memset(&serviceStatus, 0, sizeof(serviceStatus));
	serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	serviceStatus.dwControlsAccepted = 0;
	serviceStatus.dwCurrentState = SERVICE_START_PENDING;
	serviceStatus.dwWin32ExitCode = 0;
	serviceStatus.dwServiceSpecificExitCode = 0;
	serviceStatus.dwCheckPoint = 0;

	if (FALSE == SetServiceStatus(statusHandle, &serviceStatus))
	{
		DEBUGSTR(STR1);
	}

	// Perform tasks necessary to start the service here !

	serviceStopEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (NULL == serviceStopEvent)
	{
		serviceStatus.dwControlsAccepted = 0;
		serviceStatus.dwCurrentState = SERVICE_STOPPED;
		serviceStatus.dwWin32ExitCode = GetLastError();
		serviceStatus.dwCheckPoint = 1;

		if (FALSE == SetServiceStatus(statusHandle, &serviceStatus))
		{
			DEBUGSTR(STR1);
		}
		return;
	}

	serviceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;
	serviceStatus.dwCurrentState = SERVICE_RUNNING;
	serviceStatus.dwWin32ExitCode = 0;
	serviceStatus.dwCheckPoint = 0;

	if (FALSE == SetServiceStatus(statusHandle, &serviceStatus))
	{
		DEBUGSTR(STR1);
	}

	HANDLE serviceThread = CreateThread(NULL, 0, ServiceWorkerThread, NULL, 0, NULL);

	WaitForSingleObject(serviceThread, INFINITE);

	// Perform any cleanup tasks here !

	CloseHandle(serviceStopEvent);

	serviceStatus.dwControlsAccepted = 0;
	serviceStatus.dwCurrentState = SERVICE_STOPPED;
	serviceStatus.dwWin32ExitCode = 0;
	serviceStatus.dwCheckPoint = 3;

	if (FALSE == SetServiceStatus(statusHandle, &serviceStatus))
	{
		DEBUGSTR(STR1);
	}
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

		serviceStatus.dwControlsAccepted = 0;
		serviceStatus.dwCurrentState = SERVICE_STOP_PENDING;
		serviceStatus.dwWin32ExitCode = 0;
		serviceStatus.dwCheckPoint = 4;

		if (FALSE == SetServiceStatus(statusHandle, &serviceStatus))
		{
			DEBUGSTR(STR2);
		}

		SetEvent(serviceStopEvent);
		break;
	default:
		break;
	}
}

DWORD	__stdcall	ServiceWorkerThread(LPVOID lpParam)
{
	while (WAIT_OBJECT_0 != WaitForSingleObject(serviceStopEvent, 0))
	{
		// Perform main service function here

		Sleep(3000);
	}

	return ERROR_SUCCESS;
}