#pragma once

typedef struct CProactor
{
	HANDLE iocp;
	std::vector<HANDLE> iocpThreads;

	CProactor();
	~CProactor();

	bool Initializer(const HANDLE &deviceHandle, const int &threadNum);
}CProactor;

