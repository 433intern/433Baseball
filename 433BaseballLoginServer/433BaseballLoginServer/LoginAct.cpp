#include "stdafx.h"

CLoginAct::CLoginAct()
{
}

CLoginAct::~CLoginAct()
{
}

bool CLoginAct::Initializer(CActor *actorParam, CLoginSocket *sock)
{
	loginSocket = sock;
	actor = actorParam;

	return true;
}

bool CLoginAct::Complete(DWORD bytes_transferred)
{
	actor->EventProc(this, bytes_transferred);

	return true;
}

bool CLoginAct::Error(DWORD error)
{
	actor->ErrorProc(this, error);

	return true;
}