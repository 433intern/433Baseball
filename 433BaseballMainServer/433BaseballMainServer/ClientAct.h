#pragma once

typedef struct CClientAct : public CAct
{
	CClientSocket *clientSocket;

	CClientAct();
	~CClientAct();

	bool Initializer(CActor *actorParam, CClientSocket *sock);

	bool Complete(DWORD bytes_transferred);

	bool Error(DWORD error);
}CClientAct;