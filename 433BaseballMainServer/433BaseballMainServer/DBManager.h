#pragma once

class CDBManager
{
	HANDLE		deviceHandle;
	CProactor	proactor;

	MYSQL *dbConnection, connTmp;
	MYSQL_RES *sqlResult;

	const std::string dbHost;
	const std::string dbUser;
	const std::string dbPasswd;
	const std::string dbSchema;
public:
	CDBManager();
	~CDBManager();

	bool Initializer(const int &threadNum);
};

