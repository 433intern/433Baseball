#include "stdafx.h"

unsigned int __stdcall WorkerThread(void *param)
{
	static_cast<CProactor*>(param)->ProcEvents();
	return 1;
}

bool CProactor::ProcEvents()
{
	while(1)
	{
		DWORD bytesTransferred;
		DWORD completionkey;

		OVERLAPPED* overlapped = NULL;

		BOOL result = GetQueuedCompletionStatus(iocp, &bytesTransferred, static_cast<PULONG_PTR>(&completionkey), &overlapped, INFINITE);

		if (true == result)
		{
			if (NULL == overlapped)
			{
				MYPRINTF("Error on GetQueuedCompletionStatus in ProcEvents of CProactor - 1 : %d\n", WSAGetLastError());
				continue;
			}

			CAct* act = static_cast<CAct*>(overlapped);
			act->Complete(bytesTransferred);
		}
		else
		{
			DWORD error = WSAGetLastError();

			if (overlapped != NULL)
			{
				CAct* act = static_cast<CAct*>(overlapped);
				act->Error(error);
				continue;
			}

			MYPRINTF("Error on GetQueuedCompletionStatus in ProcEvents of CProactor - 2 : %d\n", WSAGetLastError());
			continue;
		}
	}
}

CProactor::CProactor()
{
}

bool CProactor::Initializer(const int &threadNum)
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
	return true;
}

bool CProactor::Register(const HANDLE &deviceHandle)
{
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
