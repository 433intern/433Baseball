#pragma once

struct CProactor
{
	HANDLE							iocp;
	std::vector<HANDLE>				iocpThreads;

	~CProactor();

	bool							Initializer(const int &threadNum);
	bool							Register(HANDLE deviceHandle);

	bool							CreateIOCP(const int &treadNum);
	bool							CreateThreadPool(const int &threadNum);

	static unsigned int __stdcall	WorkerThread(void *param);
	bool							ProcEvents();
};