#include "stdafx.h"

CReceiver::CReceiver()
{
}

CReceiver::~CReceiver()
{
}

bool CReceiver::EventProc(CAct *act, DWORD receivedBytes)
{
	CLoginAct &tmpAct = *(CLoginAct*)act;

	CLoginSocket &tmpSocket = *tmpAct.loginSocket;

	CLoginManager &loginManager = CLoginManager::GetInstance();

	protocol::PacketHeader header;

	//------------------------------

	if (CWaitHeader::Instance() == tmpSocket.stateMachine.CurrentState())
	{
		protocol::PacketHeader header;
		header.ParseFromArray(tmpSocket.recvBuf, HEADER_SIZE);

		tmpSocket.header = header;

		unsigned int tmpUint = header.size();

		switch (header.type())
		{
			case protocol::PacketType::CLS_LOGIN_REQUEST:
				// You must change the state before receive the body !!!
				tmpSocket.stateMachine.ChangeState(CWaitLoginBody::Instance());
				tmpSocket.Recv(tmpSocket.recvBuf, tmpUint);
				break;
			case protocol::PacketType::CLS_ACCOUNT_CREATE:
				// You must change the state before receive the body !!!
				tmpSocket.stateMachine.ChangeState(CWaitCreateAccountBody::Instance());
				tmpSocket.Recv(tmpSocket.recvBuf, tmpUint);
				break;
			default:
				MYERRORPRINTF("Invalid Header!!! in Receiver");
				return false;
		}
	}
	else if (CWaitCreateAccountBody::Instance() == tmpSocket.stateMachine.CurrentState())
	{
		protocol::CLS_account_create accountCreate;
		accountCreate.ParseFromArray(tmpSocket.recvBuf, tmpSocket.header.size());

		tmpSocket.header.Clear();

		// logic to somthing with body
		std::string textFormat = accountCreate.DebugString();
		MYPRINTF(textFormat.c_str());

		// You must change the state before send the response !!!
		tmpSocket.stateMachine.ChangeState(CToSendCreateAccountResponse::Instance());

		//---------------------------------------------
		// Invalidation check and save to my DB

		CDBManager &dbManager = CDBManager::GetInstance();
		CGlobalManager &globalManager = CGlobalManager::GetInstance();

		std::string tmpStr = "insert into " + globalManager.dbSecurityTableName + " values('" + accountCreate.id() + "','" + accountCreate.password() + "')";

		if (!dbManager.QueryEx(tmpStr, tmpSocket))
		{
			MYERRORPRINTF("QueryEx");
		}
		//---------------------------------------------

		protocol::PacketHeader header;

		protocol::LSC_account_create_result createAccountResult;
		createAccountResult.set_failsignal(protocol::FailSignal::UNKNOWN);

		tmpSocket.accountCreateResult = createAccountResult;

		header.set_type(protocol::PacketType::LSC_ACCOUNT_CREATE_RESULT);
		header.set_size(createAccountResult.ByteSize());

		int bufSize = header.ByteSize();

		header.SerializeToArray(tmpSocket.sendBuf, bufSize);

		tmpSocket.Send(tmpSocket.sendBuf, bufSize);
	}
	else if (CWaitLoginBody::Instance() == tmpSocket.stateMachine.CurrentState())
	{
		protocol::CLS_login_request loginRequest;
		loginRequest.ParseFromArray(tmpSocket.recvBuf, tmpSocket.header.size());

		tmpSocket.loginRequest = loginRequest;

		tmpSocket.header.Clear();

		// logic to somthing with body
		std::string textFormat = loginRequest.DebugString();
		MYPRINTF(textFormat.c_str());

		//---------------------------------------------
		// Invalidation check from DB
		CDBManager &dbManager = CDBManager::GetInstance();
		CGlobalManager &globalManager = CGlobalManager::GetInstance();

		std::string tmpStr = "select * from " + globalManager.dbSecurityTableName + " where id = '" + loginRequest.id() + "'";

		if (!dbManager.QueryEx(tmpStr, tmpSocket))
		{
			MYERRORPRINTF("QueryEx");
		}
		//---------------------------------------------
	}
	return true;
}

bool CReceiver::ErrorProc(CAct *act, DWORD error)
{
	return true;
}

bool CReceiver::Initializer()
{
	return true;
}