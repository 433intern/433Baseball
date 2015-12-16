#include "stdafx.h"

CClientAct::CClientAct()
{
}

CClientAct::~CClientAct()
{
}

bool CClientAct::Initializer(CActor *actorParam, CClientSocket *sock)
{
	clientSocket = sock;
	actor = actorParam;

	return true;
}

bool CClientAct::Complete(DWORD bytes_transferred)
{
	actor->EventProc(this, bytes_transferred);

	return true;
}

bool CClientAct::Error(DWORD error)
{
	actor->ErrorProc(this, error);

	return true;
}