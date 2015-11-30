#include "stdafx.h"

CClientAct::CClientAct()
{
}

CClientAct::~CClientAct()
{
}

bool CClientAct::Initializer(CActor *actorParam)
{
	actor = actorParam;

	return true;
}