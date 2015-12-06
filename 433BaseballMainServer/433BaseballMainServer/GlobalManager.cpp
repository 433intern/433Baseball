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