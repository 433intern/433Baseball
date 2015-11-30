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
	if (NULL != iocp)
	{
		MYPRINTF("The IOCP has been already initialized !\n");
		return false;
	}

	HANDLE iocp = (HANDLE)CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, threadNum);

	if (NULL == iocp)
	{
		MYPRINTF("Error on CreateIoCompletionPort about creating iocp kernel object in CProactor Initializer : %d\n", GetLastError());
		return false;
	}

	HANDLE threadHandle;

	iocpThreads.resize(threadNum);
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

	HANDLE result = (HANDLE)CreateIoCompletionPort(deviceHandle, iocp, NULL, NULL);
	if (NULL == result)
	{
		MYPRINTF("Error on CreateIoCompletionPort about device assignment in CProactor Initializer : %d\n", GetLastError());
		return false;
	}

	return true;
}

CProactor::~CProactor()
{
}
