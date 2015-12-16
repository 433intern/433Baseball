#pragma once

struct CDBHandle
{
	MYSQL					*dbConnection;
	MYSQL					connTmp;

	std::string				dbQuery;
	MYSQL_RES				*sqlResult;

	CProactor				*proactor;

	CDBConnector			*connector;
	CDBDisconnector			*disconnector;
	CDBQuerier				*querier;
	CDBHarvester			*harvester;

	std::string				dbHost, dbUser, dbPasswd, dbSchema;
	std::string				queryStr;

	enum DB_ACK_TYPE
	{
		CONNECT,
		DISCONNECT,
		QUERY,
		HARVEST,
		ACK_CNT
	};

	CDBAct acts[ACK_CNT];

	StateMachine<CDBHandle> stateMachine;

	//--------------------------------------------

	CDBHandle();
	~CDBHandle();

private:
	friend class CDBManager;

	bool			Initializer(const std::string &hostAddress, const std::string &userName,
							const std::string &userPassword, const std::string &schemaName);

	bool			InitActs(CProactor *proactorParam, CDBConnector *connectorParam, CDBDisconnector *disconnectorParam,
							CDBQuerier *querierParam, CDBHarvester *harvesterParam);
};

