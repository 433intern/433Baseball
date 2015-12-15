#include "stdafx.h"

CSender::CSender()
{
}

CSender::~CSender()
{
}

bool CSender::EventProc(CAct *act, DWORD receivedBytes)
{
	CLoginAct &tmpAct = *(CLoginAct*)act;

	CLoginSocket &tmpSocket = *tmpAct.loginSocket;

	CLoginManager &loginManager = CLoginManager::GetInstance();

	protocol::PacketHeader header;

	MYPRINTF("EventProc of CSender !");

	//------------------------------

	if(CToSendCreateAccountResponse::Instance() == tmpSocket.stateMachine.CurrentState())
	{
		protocol::LSC_account_create_result &tmpResult = tmpSocket.accountCreateResult;
		int bufSize = tmpResult.ByteSize();

		tmpResult.SerializeToArray(tmpSocket.sendBuf, bufSize);

		tmpSocket.stateMachine.ChangeState(CSentCreateAccountResponse::Instance());
		tmpSocket.Send(tmpSocket.sendBuf, bufSize);
	}
	else if (CSentCreateAccountResponse::Instance() == tmpSocket.stateMachine.CurrentState())
	{
		// You must change the state before receive the header !!!
		tmpSocket.stateMachine.ChangeState(CWaitHeader::Instance());
	}
	else if (CSentLoginResponse::Instance() == tmpSocket.stateMachine.CurrentState())
	{
		tmpSocket.Disconnect();
	}

	return true;
}

bool CSender::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CSender::Initializer()
{
	return true;
} 