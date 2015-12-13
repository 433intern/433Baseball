#include "stdafx.h"

CLogWriter::CLogWriter()
{
#ifdef _DEBUG
#else
	logFile = fopen("433BaseballLoginServer.log", "w");
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

bool CLogWriter::MyErrorPrintf(const std::string &str, const std::string &strClassName,
	const std::string &strFuncName, ...)
{
	va_list vaList;
	va_start(vaList, str);

	std::string tmpStr = "Error : " + std::string(str) + " in the " + strFuncName + " function of " + strClassName + " Class.\n"
		+ "err,hr : " + GetLastErrorStdStr() + "\n"
		+ "WSAGetLastError() : " + WSAGetLastErrorStdStr() + "\n";
#ifdef _DEBUG
	if (-1 == vprintf(tmpStr.c_str(), vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#else
	if (-1 == vfprintf(logFile, tmpStr.c_str(), vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#endif
	va_end(vaList);

	return true;
}

bool CLogWriter::MyServiceErrorPrintf(const std::string &str, const std::string &strFuncName, ...)
{
	va_list vaList;
	va_start(vaList, str);

	std::string tmpStr = "Service Error : " + std::string(str) + " in the " + strFuncName + " function.\n"
		+ "err,hr : " + GetLastErrorStdStr() + "\n"
		+ "WSAGetLastError() : " + WSAGetLastErrorStdStr() + "\n";
#ifdef _DEBUG
	if (-1 == vprintf(tmpStr.c_str(), vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#else
	if (-1 == vfprintf(logFile, tmpStr.c_str(), vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#endif
	va_end(vaList);

	return true;
}

bool CLogWriter::MyDBErrorPrintf(MYSQL &handle, const std::string &str, const std::string &strFuncName, ...)
{
	va_list vaList;
	va_start(vaList, str);

	std::string tmpStr = "DB Error : " + std::string(str) + " in the " + strFuncName + " function.\n"
		+ "mysql_error : " + mysql_error(&handle) + "\n";
#ifdef _DEBUG
	if (-1 == vprintf(tmpStr.c_str(), vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#else
	if (-1 == vfprintf(logFile, tmpStr.c_str(), vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#endif
	va_end(vaList);

	return true;
}

bool CLogWriter::MyPrintf(const char *str, ...)
{
	va_list vaList;
	va_start(vaList, str);

	std::string tmpStr = std::string(str) + "\n";

#ifdef _DEBUG
	if (-1 == vprintf(tmpStr.c_str(), vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#else
	if (-1 == vfprintf(logFile, tmpStr.c_str(), vaList))
	{
		va_end(vaList);
		Beep(750, 10000);
		return false;
	}
#endif
	va_end(vaList);

	return true;
}