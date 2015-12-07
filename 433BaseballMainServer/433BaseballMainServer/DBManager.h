#pragma once

class CDBManager
{
	HANDLE					deviceHandle;
	CProactor				proactor;

	MYSQL					connTmp;

	const std::string		dbHost;
	const std::string		dbUser;
	const std::string		dbPasswd;
	const std::string		dbSchema;

	CDBConnector			connector;
	CDBDisconnector			disconnector;
	CDBHarvester			harvester;
	CDBQuerier				querier;

	int						threadPoolSize, handlePoolSize;
	
	int						availableDBHandles;
	std::queue<CDBHandle*>	dbHandles;

	bool					ConnectEx(CDBHandle *handle, CDBAct *act);
	bool					DisconnectEx(CDBHandle *handle, CDBAct *act);
public:
	CDBManager(const std::string &hostAddress, const std::string &userName,
		const std::string &userPassword, const std::string &schemaName);
	~CDBManager();

	CDBHandle				*GetAvailableHandle();
	bool					ReleaseHandle(CDBHandle *param);

	bool Initializer(const int &threadNum, const int &handleNumParam);

	bool					QueryEx(const char *str, CDBAct *act);
	bool					HarvestEx(CDBAct *act);
};