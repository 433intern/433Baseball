#pragma once

typedef struct CDBHandle
{
	MYSQL			*dbConnection;
	HANDLE			*dbSema;
	bool			isAvailable;

	enum DB_ACK_TYPE
	{
		CONNECT,
		DISCONNECT,
		QUERY,
		GET_QUERY_RESULT,
		ACK_CNT
	};

	CDBAct acts[ACK_CNT];

	//--------------------------------------------

	bool Query(const char *str);

	bool Initializer(MYSQL &connTmp, const std::string &hostAddress, const std::string &userName,
		const std::string &userPassword, const std::string &schemaName);

	CDBHandle(HANDLE *dbSemaParam);
	~CDBHandle();
}CDBHandle;

