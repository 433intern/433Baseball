#include "stdafx.h";

CToSendLoginResponse* CToSendLoginResponse::Instance()
{
	static CToSendLoginResponse instance;

	return &instance;
}

void CToSendLoginResponse::Enter(CLoginSocket *login)
{
}

void CToSendLoginResponse::Exit(CLoginSocket *login)
{
}

void CToSendLoginResponse::Execute(CLoginSocket *login)
{
}

//-----------------------------------------------------

CToSendCreateAccountResponse* CToSendCreateAccountResponse::Instance()
{
	static CToSendCreateAccountResponse instance;

	return &instance;
}

void CToSendCreateAccountResponse::Enter(CLoginSocket *login)
{
}

void CToSendCreateAccountResponse::Exit(CLoginSocket *login)
{
}

void CToSendCreateAccountResponse::Execute(CLoginSocket *login)
{
}

//-----------------------------------------------------

CSentLoginResponse* CSentLoginResponse::Instance()
{
	static CSentLoginResponse instance;

	return &instance;
}

void CSentLoginResponse::Enter(CLoginSocket *login)
{
}

void CSentLoginResponse::Exit(CLoginSocket *login)
{
}

void CSentLoginResponse::Execute(CLoginSocket *login)
{
}

//-----------------------------------------------------

CSentCreateAccountResponse* CSentCreateAccountResponse::Instance()
{
	static CSentCreateAccountResponse instance;

	return &instance;
}

void CSentCreateAccountResponse::Enter(CLoginSocket *login)
{
}

void CSentCreateAccountResponse::Exit(CLoginSocket *login)
{
}

void CSentCreateAccountResponse::Execute(CLoginSocket *login)
{
}

//-----------------------------------------------------

CWaitHeader* CWaitHeader::Instance()
{
	static CWaitHeader instance;

	return &instance;
}

void CWaitHeader::Enter(CLoginSocket *login)
{
}

void CWaitHeader::Exit(CLoginSocket *login)
{
}

void CWaitHeader::Execute(CLoginSocket *login)
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

//-------------------------------------------------

CWaitLoginBody* CWaitLoginBody::Instance()
{
	static CWaitLoginBody instance;

	return &instance;
}

void CWaitLoginBody::Enter(CLoginSocket *login)
{
}

void CWaitLoginBody::Exit(CLoginSocket *login)
{
}

void CWaitLoginBody::Execute(CLoginSocket *login)
{
}

//-----------------------------------------------------

CWaitCreateAccountBody* CWaitCreateAccountBody::Instance()
{
	static CWaitCreateAccountBody instance;

	return &instance;
}

void CWaitCreateAccountBody::Enter(CLoginSocket *login)
{
}

void CWaitCreateAccountBody::Exit(CLoginSocket *login)
{
}

void CWaitCreateAccountBody::Execute(CLoginSocket *login)
{
}