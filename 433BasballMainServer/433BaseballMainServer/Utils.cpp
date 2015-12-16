#include "stdafx.h"

std::string GetLastErrorStdStr()
{
	DWORD error = GetLastError();
	if (error)
	{
		LPVOID msgBuf;
		DWORD bufLen = FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			error,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&msgBuf,
			0, NULL);
		if (bufLen)
		{
			LPCSTR msgStr = (LPCSTR)msgBuf;
			std::string result(msgStr, msgStr + bufLen);

			LocalFree(msgBuf);

			return result;
		}
	}
	return std::string();
}

std::string WSAGetLastErrorStdStr()
{
	char tmpstr[100];

	FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		tmpstr, 0, NULL);

	std::string tmpWStr(tmpstr);

	return tmpstr;
}