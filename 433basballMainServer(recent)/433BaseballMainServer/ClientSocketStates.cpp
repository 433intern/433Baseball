#include "stdafx.h";

CWaitResponse* CWaitResponse::Instance()
{
	static CWaitResponse instance;

	return &instance;
}

void CWaitResponse::Enter(CClientSocket *client)
{
}

void CWaitResponse::Exit(CClientSocket *client)
{
}

void CWaitResponse::Execute(CClientSocket *client)
{
}

//-----------------------------------------------------

CWaitMessage* CWaitMessage::Instance()
{
	static CWaitMessage instance;

	return &instance;
}

void CWaitMessage::Enter(CClientSocket *client)
{
}

void CWaitMessage::Exit(CClientSocket *client)
{
}

void CWaitMessage::Execute(CClientSocket *client)
{
}