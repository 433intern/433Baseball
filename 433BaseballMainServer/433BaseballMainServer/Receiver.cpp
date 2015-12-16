#include "stdafx.h"

CReceiver::CReceiver()
{
}

CReceiver::~CReceiver()
{
}

bool CReceiver::EventProc(CAct *act, DWORD receivedBytes)
{
	assert(dynamic_cast<CClientAct*>(act));

	CClientAct& clientAct = *dynamic_cast<CClientAct*>(act);

	assert(clientAct.clientSocket);

	CClientSocket& clientSocket = *clientAct.clientSocket;

	//PRINTF("...俊矾贸府 Receiver s(%d) err(%d)\n", tcpsocket.GetSocket(), error );

	clientSocket.RecvProcess(false, act, receivedBytes);

	return true;

}

bool CReceiver::ErrorProc(CAct *act, DWORD error)
{
	assert(dynamic_cast<CClientAct*>(act));

	CClientAct& clientAct = *dynamic_cast<CClientAct*>(act);

	assert(clientAct.clientSocket);

	CClientSocket& clientSocket = *clientAct.clientSocket;

	//PRINTF("...俊矾贸府 Receiver s(%d) err(%d)\n", tcpsocket.GetSocket(), error );

	clientSocket.RecvProcess(true, act, 0);


	return true;
}

bool CReceiver::Initializer()
{
	return true;
}