#pragma once

struct CAcceptor : public CActor
{
	CListenSocket *listenSocket;
	LPFN_ACCEPTEX lpfnAcceptEx;

	CAcceptor();
	~CAcceptor();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer(CListenSocket &listenSockParam);

	bool Register(CLoginSocket &loginSocket, int size);
};