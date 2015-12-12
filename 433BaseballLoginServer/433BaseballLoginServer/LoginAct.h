#pragma once

struct CLoginAct : public CAct
{
	CLoginSocket *loginSocket;

	CLoginAct();
	~CLoginAct();

	bool Initializer(CActor *actorParam, CLoginSocket *sock);

	bool Complete(DWORD bytes_transferred);

	bool Error(DWORD error);
};