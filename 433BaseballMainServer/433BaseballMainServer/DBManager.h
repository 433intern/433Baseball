#pragma once

class CDBManager
{
	HANDLE					deviceHandle;
	CProactor				proactor;

	MYSQL					connTmp;
	MYSQL_RES				*sqlResult;

	const std::string		dbHost;
	const std::string		dbUser;
	const std::string		dbPasswd;
	const std::string		dbSchema;

	int						threadPoolSize, handlePoolSize;
	
	HANDLE					dbHandleSemaphore;
	std::vector<CDBHandle*>	dbHandles;
public:
	CDBManager(const std::string &hostAddress, const std::string &userName,
		const std::string &userPassword, const std::string &schemaName);
	~CDBManager();

	MYSQL GetAvailableHandle();

	bool Initializer(const int &threadNum, const int &handleNumParam);
};