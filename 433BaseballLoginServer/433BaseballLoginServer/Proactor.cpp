#include "stdafx.h"

CProactor::~CProactor()
{
}

bool CProactor::Initializer(const int &threadNum)
{
	iocp = NULL;

	if (!CreateIOCP(threadNum))
	{
		MYERRORPRINTF("CreateIOCP");
		return false;
	}

	if (!CreateThreadPool(threadNum))
	{
		MYERRORPRINTF("CreatetThreadPool");
		return false;
	}
	
	return true;
}

bool CProactor::CreateIOCP(const int &threadNum)
{
	iocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, threadNum);

	if (NULL == iocp)
	{
		MYERRORPRINTF("CreateIoCompletionPort");
		return false;
	}

	return true;
}

bool CProactor::CreateThreadPool(const int &threadNum)
{
	HANDLE threadHandle;

	iocpThreads.reserve(threadNum);
	for (int k = 0; k < threadNum; ++k)
	{
		threadHandle = (HANDLE)_beginthreadex(NULL, NULL, CProactor::WorkerThread, (void*)this, NULL, NULL);
		if (NULL == threadHandle)
		{
			MYERRORPRINTF("_beginthreadex");
			return false;
		}

		iocpThreads.push_back(threadHandle);
	}
	return true;
}

bool CProactor::Register(HANDLE deviceHandle)
{
	HANDLE result = (HANDLE)CreateIoCompletionPort(deviceHandle, iocp, NULL, NULL);
	if (NULL == result)
	{
		MYERRORPRINTF("CreateIoCompletionPort");
		return false;
	}
	return true;
}

unsigned int __stdcall CProactor::WorkerThread(void *param)
{
	static_cast<CProactor*>(param)->ProcEvents();
	return 1;
}

bool CProactor::ProcEvents()
{
	while (1)
	{
		DWORD bytesTransferred;
		DWORD completionkey;

		OVERLAPPED* overlapped = NULL;

		BOOL result = GetQueuedCompletionStatus(iocp, &bytesTransferred, static_cast<PULONG_PTR>(&completionkey), &overlapped, INFINITE);

		if (TRUE == result)
		{
			if (NULL == overlapped)
			{
				MYERRORPRINTF("GetQueuedCompletionStatus");
				continue;
			}

			CAct* act = static_cast<CAct*>(overlapped);
			act->Complete(bytesTransferred);
		}
		else
		{
			if (overlapped != NULL)
			{
				CAct* act = static_cast<CAct*>(overlapped);

				DWORD error = WSAGetLastError();

				act->Error(error);
				continue;
			}

			MYERRORPRINTF("GetQueuedCompletionStatus");
			continue;
		}
	}
	return false;
}