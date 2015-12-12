#include "stdafx.h";

CWaitResponse* CWaitResponse::Instance()
{
	static CWaitResponse instance;

	return &instance;
}

void CWaitResponse::Enter(CLoginSocket *login)
{
}

void CWaitResponse::Exit(CLoginSocket *login)
{
}

void CWaitResponse::Execute(CLoginSocket *login)
{
}

//-----------------------------------------------------

CWaitMessage* CWaitMessage::Instance()
{
	static CWaitMessage instance;

	return &instance;
}

void CWaitMessage::Enter(CLoginSocket *login)
{
}

void CWaitMessage::Exit(CLoginSocket *login)
{
}

void CWaitMessage::Execute(CLoginSocket *login)
{
}