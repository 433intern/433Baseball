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
	actor->EventProc(this, bytes_transferred);

	return true;
}

bool CDBAct::Error(DWORD error)
{
	MYERRORPRINTF("Error");
	
	return true;
}

bool CDBAct::Initializer(CActor *actorParam, CDBHandle *handleParam)
{
	actor = actorParam;
	dbHandle = handleParam;

	return true;
}