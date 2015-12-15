#pragma once

class CDBManager
{
	CProactor				proactor;

	std::string				dbHost;
	std::string				dbUser;
	std::string				dbPasswd;
	std::string				dbSchema;

	CDBConnector			connector;
	CDBDisconnector			disconnector;
	CDBQuerier				querier;

	int						threadPoolSize, handlePoolSize;
	
	HANDLE					dbHandleSema;
	std::queue<CDBHandle*>	dbHandles;
public:
	~CDBManager();

	static CDBManager		&GetInstance();

	CDBHandle				*GetAvailableHandle();
	bool					ReleaseHandle(CDBHandle *param);

	bool					FirstInitializer(const std::string &hostAddress, const std::string &userName,
		const std::string &userPassword, const std::string &schemaName);
	bool					SecondInitializer(const int &threadNum, const int &handleNumParam);

	bool					QueryEx(std::string &str, CLoginSocket &sock);
	bool					HarvestEx(CDBHandle *param);

	bool					ConnectEx(CDBHandle *param);
	bool					DisconnectEx(CDBHandle *param);

	bool					CreateDBHandlePool(const int &handleNumParam);
};