#include "stdafx.h"

CDBAct::CDBAct()
{
	dbHandle = NULL;
}

CDBAct::~CDBAct()
{
}

bool CDBAct::Complete(DWORD bytes_transferred)
{

	return true;
}

bool CDBAct::Error(DWORD error)
{
	
	return true;
}

bool CDBAct::Initializer(CActor *actorParam, CDBHandle *handleParam)
{
	actor = actorParam;
	dbHandle = handleParam;

	return true;
}