#include<windows.h>
#include<winsvc.h>
#include<tchar.h>

SERVICE_STATUS					serviceStatus = { 0 };
SERVICE_STATUS_HANDLE			statusHandle = NULL;
HANDLE							serviceStopEvent = INVALID_HANDLE_VALUE;

VOID	__stdcall	ServiceMain(DWORD argc, LPTSTR *argv);
VOID	__stdcall	ServiceCtrlHandler(DWORD);
DWORD	__stdcall	ServiceWorkerThread(LPVOID lpParam);

#define SERVICE_NAME _T("433_Baseball_Login_Server")

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


}