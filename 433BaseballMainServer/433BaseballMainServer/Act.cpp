#include "stdafx.h"

CAct::CAct()
{
}

CAct::~CAct()
{
}

bool CAct::Initializer(CActor *actorParam)
{
	actor = actorParam;

	return true;
}
