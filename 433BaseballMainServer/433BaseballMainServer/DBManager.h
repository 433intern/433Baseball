#pragma once

class CDBManager
{
	HANDLE		deviceHandle;
	CProactor	proactor;
public:
	CDBManager(HANDLE deviceHandle);
	~CDBManager();

	bool Initializer(const HANDLE &deviceHandle, const int &threadNum);
};

