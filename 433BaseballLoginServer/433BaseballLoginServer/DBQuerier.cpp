#include "stdafx.h"

CDBQuerier::CDBQuerier()
{
}

CDBQuerier::~CDBQuerier()
{
}

bool CDBQuerier::EventProc(CAct *act, DWORD receivedBytes)
{
	CGlobalManager &globalManager = CGlobalManager::GetInstance();

	CDBAct *dbAct = (CDBAct*)act;

	CDBManager &dbManager = CDBManager::GetInstance();

	CDBHandle *dbHandle = dbAct->dbHandle;

	MYSQL *realDBHandle = dbHandle->dbConnection;

	//--------------------------------------

	if (NULL == realDBHandle)
	{
		MYPRINTF("Error on Query of CDBManager : Not connected to DB.\n");
		return false;
	}

	if (mysql_query(realDBHandle, dbHandle->queryStr.c_str()))
	{
		MYDBERRORPRINTF(dbHandle->connTmp,"mysql_query");
		return false;
	}
	else
	{
		MYSQL_RES *tmpRes;
		unsigned int numFields;
		unsigned int numRows;

		tmpRes = mysql_store_result(realDBHandle);
		if (tmpRes)
		{
			// There is some result : select

			if (tmpRes->row_count > 1)
			{
				MYPRINTF("There is some duplicated id");
				return false;
			}

			if (tmpRes->field_count != 2)
			{
				MYPRINTF("Your Query is not a select query, but your query want to get a result");
				return false;
			}

			MYSQL_ROW row = mysql_fetch_row(tmpRes);


			protocol::PacketHeader header;
			protocol::LSC_login_result loginResult;

			//------------------------------

			CLoginSocket &loginSock = *dbHandle->loginSock;

			header.set_type(protocol::PacketType::LSC_LOGIN_RESULT);

			if (NULL == row)
			{
				loginResult.set_failsignal(protocol::FailSignal::NO_EXIST);
				MYPRINTF("The id of your login request is a wrong id !");
			}
			else
			{
				std::string resultPassword = row[1];
				std::string resultId = row[0];
				if (resultId == loginSock.loginRequest.id())
				{
					if (resultPassword == loginSock.loginRequest.password())
					{
						loginResult.set_failsignal(protocol::FailSignal::UNKNOWN);
						loginResult.set_ip(globalManager.dbServerIp);
						loginResult.set_port(globalManager.clientPort);
						loginResult.set_securitycode("1");

						MYPRINTF("Your login request are successfully accepted !");
					}
					else
					{
						loginResult.set_failsignal(protocol::FailSignal::WRONG_PASSWORD);
						MYPRINTF("The password of your login request is a wrong password !");
					}
				}
				else
				{
					MYDBERRORPRINTF(dbHandle->connTmp, "mysql_fetch_row");
					return false;
				}
			}

			header.set_size(loginResult.ByteSize());
			int bufSize = header.ByteSize();
			header.SerializeToArray(loginSock.sendBuf, bufSize);

			// Send Header
			loginSock.Send(loginSock.sendBuf, bufSize);
			
			bufSize = loginResult.ByteSize();
			loginResult.SerializeToArray(loginSock.sendBuf, bufSize);

			loginSock.stateMachine.ChangeState(CSentLoginResponse::Instance());

			loginSock.Send(loginSock.sendBuf, bufSize);

			// Send The payload
			//-------------------------------

			mysql_free_result(tmpRes);
		}
		else
		{
			if (mysql_field_count(realDBHandle))
			{
				MYDBERRORPRINTF(dbHandle->connTmp, "mysql_query");
				return false;
			}
		}
	}
	dbHandle->stateMachine.ChangeState(CDBIdle::Instance());
	return true;
}

bool CDBQuerier::ErrorProc(CAct *act, DWORD error)
{
	MYERRORPRINTF("ErrorPorc");

	return true;
}

bool CDBQuerier::Initializer()
{
	return true;
}