#pragma once

struct CGlobalManager
{
	CLogWriter			logWriter;

	std::string			dbServerIp;
	unsigned short		dbPort;
	std::string			dbSchemaName;
	std::string			dbUsername;
	std::string			dbPassword;

	std::string			dbStasticalTableName, dbMatchRecordTableName, dbOverloadRecordTableName;

	unsigned short		mainServerPort;

	static CGlobalManager &GetInstance();
	~CGlobalManager();

	bool Initializer(const std::string &dbServerIp, const unsigned short dbPort, const std::string &dbSchema,
		const std::string &dbStasticalTableName, const std::string &dbMatchRecordTableName,
		const std::string &dbOverloadRecordTableName,
		const std::string &dbUserName, const std::string &dbPassword,
		const unsigned short mainServerPort);
private:
	CGlobalManager();

};

