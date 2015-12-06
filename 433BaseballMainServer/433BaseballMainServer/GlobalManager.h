#pragma once
typedef struct CGlobalManager
{
	CLogWriter			logWriter;

	CDBManager			*dbManager;
	CClientManager		*clientManager;

	static CGlobalManager &GetInstance();
	~CGlobalManager();
private:
	CGlobalManager();
}CGlobalManager;

