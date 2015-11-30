#pragma once

typedef struct CClientAct : public CAct
{
	CClientSocket clientSocket;

	CClientAct();
	~CClientAct();

	bool Initializer(CActor *actor);

	bool Complete(DWORD bytes_transferred)
	{
		actor->EventProc(bytes_transferred);
	}

	bool Error(DWORD error)
	{
		actor->ErrorProc(error);
	}
}CClientAct;