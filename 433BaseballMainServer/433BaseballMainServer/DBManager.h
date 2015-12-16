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

	bool					QueryEx(std::string &str);

	bool					CreateDBHandlePool(const int &handleNumParam);
public:
	~CDBManager();

	static CDBManager		&GetInstance();

	CDBHandle				*GetAvailableHandle();
	bool					ReleaseHandle(CDBHandle *param);

	bool					FirstInitializer(const std::string &hostAddress, const std::string &userName,
		const std::string &userPassword, const std::string &schemaName);
	bool					SecondInitializer(const int &threadNum, const int &handleNumParam);

	// Async fucntion
	bool					InsertMatchResultEx(const std::string &looserID, const std::string &winnerID,
		int looserScore, int winnerScore, const std::string &timeStamp);
	// Async fucntion
	bool					InsertOverloadRecordEx(const std::string &timeStamp, int totalUserCnt);

	// Sync fucntion
	std::pair<int, int>		GetOnesStastics(const std::string onesID);

	bool					ConnectEx(CDBHandle *param);
	bool					DisconnectEx(CDBHandle *param);
};