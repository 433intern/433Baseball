#include "stdafx.h"

CLogWriter::CLogWriter()
{
#ifdef _DEBUG
#else
	logFile = fopen("433BaseballMainServer.log", "w");
	if (NULL == logFile)
	{
		Beep(750, 10000);
	}
#endif
}

CLogWriter::~CLogWriter()
{
#ifdef _DEBUG
#else
	if (logFile)
	{
		fclose(logFile);
	}
#endif
}

bool CLogWriter::MyPrintf(const char *str, ...)
{
	va_list vaList;
	va_start(vaList, str);
#ifdef _DEBUG
	if(-1 == vprintf(str, vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#else
	if(-1 == vfprintf(logFile, str, vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#endif
	va_end(vaList);

	return true;
}
