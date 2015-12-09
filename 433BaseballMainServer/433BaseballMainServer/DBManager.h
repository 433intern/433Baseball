#pragma once

class CDBManager
{
	CProactor				proactor;

	const std::string		dbHost;
	const std::string		dbUser;
	const std::string		dbPasswd;
	const std::string		dbSchema;

	CDBConnector			connector;
	CDBDisconnector			disconnector;
	CDBHarvester			harvester;
	CDBQuerier				querier;

	int						threadPoolSize, handlePoolSize;
	
	//int						availableDBHandles;
	HANDLE					dbHandleSema;
	std::queue<CDBHandle*>	dbHandles;
public:
	CDBManager(const std::string &hostAddress, const std::string &userName,
		const std::string &userPassword, const std::string &schemaName);
	~CDBManager();

	CDBHandle				*GetAvailableHandle();
	bool					ReleaseHandle(CDBHandle *param);

	bool					Initializer(const int &threadNum, const int &handleNumParam);

	bool					QueryEx(const char *str);
	bool					HarvestEx(CDBHandle *param);

	bool					ConnectEx(CDBHandle *param);
	bool					DisconnectEx(CDBHandle *param);
};