#include "stdafx.h";

CWaitLoginResponse* CWaitLoginResponse::Instance()
{
	static CWaitLoginResponse instance;

	return &instance;
}

void CWaitLoginResponse::Enter(CLoginSocket *login)
{
}

void CWaitLoginResponse::Exit(CLoginSocket *login)
{
}

void CWaitLoginResponse::Execute(CLoginSocket *login)
{
}

//-----------------------------------------------------

CWaitCreateAccountResponse* CWaitCreateAccountResponse::Instance()
{
	static CWaitCreateAccountResponse instance;

	return &instance;
}

void CWaitCreateAccountResponse::Enter(CLoginSocket *login)
{
}

void CWaitCreateAccountResponse::Exit(CLoginSocket *login)
{
}

void CWaitCreateAccountResponse::Execute(CLoginSocket *login)
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

//-----------------------------------------------------

CDisconnected* CDisconnected::Instance()
{
	static CDisconnected instance;

	return &instance;
}

void CDisconnected::Enter(CLoginSocket *login)
{
}

void CDisconnected::Exit(CLoginSocket *login)
{
}

void CDisconnected::Execute(CLoginSocket *login)
{
}