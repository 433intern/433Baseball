#pragma once

struct CGlobalManager
{
	CLogWriter			logWriter;

	static CGlobalManager &GetInstance();
	~CGlobalManager();

private:
	CGlobalManager();

};

