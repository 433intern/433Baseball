#pragma once

typedef struct CAcceptor : public CActor
{
	CListenSocket listenSocket;
public:
	CAcceptor();
	~CAcceptor();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer(CProactor *proactor);

	bool Register(CClientSocket &clientSocket, int size);
}CAcceptor;