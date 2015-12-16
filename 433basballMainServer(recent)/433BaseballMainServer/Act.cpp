#include "stdafx.h"

CAct::CAct()
{
	hEvent = NULL;
	Internal = 0;
	InternalHigh = 0;
	Offset = 0;
	OffsetHigh = 0;

	actor = NULL;
}

CAct::~CAct()
{
}

bool CAct::Initializer(CActor *actorParam)
{
	actor = actorParam;

	return true;
}
