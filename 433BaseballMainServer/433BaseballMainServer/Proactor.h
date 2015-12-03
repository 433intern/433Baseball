#pragma once

typedef struct CProactor
{
	HANDLE iocp;
	std::vector<HANDLE> iocpThreads;

	CProactor();
	~CProactor();

	bool Initializer(const int &threadNum);
	bool Register(const HANDLE &deviceHandle);
	bool ProcEvents();
}CProactor;

