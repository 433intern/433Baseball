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
	const std::string &dbSecurityTableName, const std::string &dbUserName, const std::string &dbPassword, const unsigned short clientPort, const unsigned short loginServerPort)
{
	if (clientPort < 1024)
	{
		MYERRORPRINTF("You shouldn't use the well-known port numbers on clientPort.");
		return false;
	}

	this->clientPort = clientPort;
	this->dbSchemaName = dbSchema;
	this->dbServerIp = dbServerIp;
	this->dbUsername = dbUserName;
	this->dbPassword = dbPassword;
	this->dbSecurityTableName = dbSecurityTableName;
	this->loginServerPort = loginServerPort;
	this->dbPort = dbPort;

	return true;
}