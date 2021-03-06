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
			std::string resultPassword, resultId;

			//------------------------------

			CLoginSocket &loginSock = *dbHandle->loginSock;

			header.set_type(protocol::PacketType::LSC_LOGIN_RESULT);

			if (NULL == row)
			{
				loginResult.set_failsignal(protocol::FailSignal::NO_EXIST);
				MYPRINTF("The id of your login request is a wrong id !");
				mysql_free_result(tmpRes);
			}
			else
			{
				resultPassword = row[1];
				resultId = row[0];
				mysql_free_result(tmpRes);
				if (resultId == loginSock.loginRequest.id())
				{
					if (resultPassword == loginSock.loginRequest.password())
					{
						MYSQL_ROW midRow;

						MYSQL_RES *tmpRes2;
						unsigned int numFields;
						unsigned int numRows;

						std::string tmpStr = "select * from " + globalManager.dbStatisticTableName + " where id = '" + resultId + "'";

						if (mysql_query(realDBHandle, tmpStr.c_str()))
						{
							MYDBERRORPRINTF(dbHandle->connTmp, "mysql_query");
							return false;
						}
						else
						{
							tmpRes2 = mysql_store_result(realDBHandle);
							if (tmpRes2)
							{
								// There is some result : select

								if (tmpRes2->row_count > 1)
								{
									MYPRINTF("There is some duplicated id");
									return false;
								}

								if (tmpRes2->field_count != 3)
								{
									MYPRINTF("Your Query is not a select query, but your query want to get a result");
									return false;
								}

								midRow = mysql_fetch_row(tmpRes2);
							}
							else
							{
								MYDBERRORPRINTF(dbHandle->connTmp, "mysql_fetch_row");
								return false;
							}

							mysql_free_result(tmpRes2);
						}
						loginResult.set_failsignal(protocol::FailSignal::UNKNOWN);
						loginResult.set_ip(globalManager.dbServerIp);
						loginResult.set_port(globalManager.clientPort);
						loginResult.set_securitycode("1");
						loginResult.set_wincnt(atoi(midRow[1]));
						loginResult.set_losecnt(atoi(midRow[2]));
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

			// Send The payload
			loginSock.Send(loginSock.sendBuf, bufSize);

			if (NULL != row && resultId == loginSock.loginRequest.id()
				&& resultPassword == loginSock.loginRequest.password())
			{
				loginSock.Disconnect();
				MYPRINTF("Your login request are successfully accepted !");
				return true;
			}
			else
			{
				// You must change the state before receive the header !!!
				loginSock.stateMachine.ChangeState(CWaitHeader::Instance());
				loginSock.Recv(loginSock.recvBuf, HEADER_SIZE);
			}
			//-------------------------------
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