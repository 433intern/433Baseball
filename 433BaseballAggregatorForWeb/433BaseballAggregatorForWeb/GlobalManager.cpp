#include "stdafx.h"

CGlobalManager::CGlobalManager()
{
}

CGlobalManager::~CGlobalManager()
{
}

CGlobalManager &CGlobalManager::GetInstance()
{
	static CGlobalManager GlobalManager;
	return GlobalManager;
}
