#include "stdafx.h"

CGlobalManager::CGlobalManager()
{
}

CGlobalManager::~CGlobalManager()
{
}

CGlobalManager &CGlobalManager::GetInstance()
{
	static CGlobalManager globalManager;
	return globalManager;
}

bool CGlobalManager::Initializer(const std::string &dbServerIp, const unsigned short dbPort, const std::string &dbSchema,
	const std::string &dbStasticalTableName, const std::string &dbMatchRecordTableName,
	const std::string &dbOverloadRecordTableName,
	const std::string &dbUserName, const std::string &dbPassword,
	const unsigned short mainServerPort)
{
	if (mainServerPort < 1024)
	{
		MYERRORPRINTF("You shouldn't use the well-known port numbers on clientPort.");
		return false;
	}

	this->mainServerPort = mainServerPort;
	this->dbSchemaName = dbSchema;
	this->dbServerIp = dbServerIp;
	this->dbUsername = dbUserName;
	this->dbPassword = dbPassword;
	this->dbStasticalTableName = dbStasticalTableName;
	this->dbMatchRecordTableName = dbMatchRecordTableName;
	this->dbStasticalTableName = dbStasticalTableName;
	this->dbOverloadRecordTableName = dbOverloadRecordTableName;
	this->dbPort = dbPort;

	return true;
}