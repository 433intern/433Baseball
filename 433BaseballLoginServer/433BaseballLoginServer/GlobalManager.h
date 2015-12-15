#pragma once

struct CGlobalManager
{
	CLogWriter			logWriter;

	std::string			dbServerIp;
	unsigned short		dbPort;
	std::string			dbSchemaName;
	std::string			dbUsername;
	std::string			dbPassword;
	std::string			dbSecurityTableName;
	unsigned short		loginServerPort;

	unsigned short		clientPort;

	static CGlobalManager &GetInstance();
	~CGlobalManager();

	bool Initializer(const std::string &dbServerIp, const unsigned short dbPort, const std::string &dbSchema,
		const std::string &dbSecurityTableName, const std::string &dbUserName, const std::string &dbPassword, const unsigned short clientPort, const unsigned short loginServerPort);
private:
	CGlobalManager();
};

