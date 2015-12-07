#pragma once

typedef struct CDBHandle
{
	MYSQL					*dbConnection;
	HANDLE					*dbSema;
	bool					isAvailable;

	std::string				dbQuery;
	MYSQL_RES				*sqlResult;

	CProactor				*proactor;

	CDBConnector			*connector;
	CDBDisconnector			*disconnector;
	CDBQuerier				*querier;
	CDBHarvester			*harvester;

	enum DB_ACK_TYPE
	{
		CONNECT,
		DISCONNECT,
		QUERY,
		HARVEST,
		ACK_CNT
	};

	CDBAct acts[ACK_CNT];

	//--------------------------------------------

	CDBHandle();
	~CDBHandle();

private:
	friend class CDBManager;

	bool			Query(const char *str);
	MYSQL_RES		*Harvest();

	bool			Initializer(MYSQL &connTmp, const std::string &hostAddress, const std::string &userName,
							const std::string &userPassword, const std::string &schemaName);

	bool			InitActs(CProactor *proactorParam, CDBConnector *connectorParam, CDBDisconnector *disconnectorParam,
							CDBQuerier *querierParam, CDBHarvester *harvesterParam);

	
}CDBHandle;

