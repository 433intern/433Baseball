#include "stdafx.h"

unsigned int __stdcall WorkerThread(void *param)
{

	return 1;
}

CProactor::CProactor()
{
}

bool CProactor::Initializer(const HANDLE &deviceHandle, const int &threadNum)
{
	HANDLE iocp = (HANDLE)CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, threadNum);
	if (NULL == iocp)
	{
		MYPRINTF("Error on CreateIoCompletionPort in CProactor Initializer : %d\n", GetLastError());
		return false;
	}

	HANDLE threadHandle;

	for (int k = 0; k < threadNum; ++k)
	{
		threadHandle = (HANDLE)_beginthreadex(NULL, NULL, WorkerThread, NULL, NULL, NULL);

		if (NULL == threadHandle)
		{
			MYPRINTF("Error on _beginthreadex on %d th thread creation in CProactor Initializer : %d\n", k, GetLastError);
			return false;
		}

		iocpThreads.push_back(threadHandle);
	}

	return true;
}

CProactor::~CProactor()
{
}
