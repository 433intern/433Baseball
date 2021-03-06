#pragma once

class CLogWriter
{
#ifdef _DEBUG
#else
	FILE *logFile;
#endif
public:
	CLogWriter();
	~CLogWriter();

	bool MyErrorPrintf(const std::string &str, const std::string &strClassName,
		const std::string &strFuncName, ...);
	bool MyServiceErrorPrintf(const std::string &str, const std::string &strFuncName, ...);
	bool MyDBErrorPrintf(MYSQL &handle, const std::string &str, const std::string &strFuncName, ...);
	bool MyPrintf(const char *str, ...);
};

