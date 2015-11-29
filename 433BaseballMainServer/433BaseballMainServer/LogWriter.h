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

	bool MyPrintf(const char *str, ...);
};

