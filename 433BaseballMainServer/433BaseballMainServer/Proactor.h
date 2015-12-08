#pragma once

struct CProactor
{
	HANDLE iocp;
	std::vector<HANDLE> iocpThreads;

	CProactor();
	~CProactor();

	bool Initializer(const int &threadNum);
	bool Register(HANDLE deviceHandle);
	bool ProcEvents();

	static unsigned int __stdcall WorkerThread(void *param);
};