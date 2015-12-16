#pragma once
class CGlobalManager
{
	CGlobalManager();
public:
	static CGlobalManager &GetInstance();
	~CGlobalManager();
};

