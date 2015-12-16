#pragma once

class CWaitResponse : public State<CClientSocket>
{
private:
	CWaitResponse(){}
	CWaitResponse(const CWaitResponse&);
	CWaitResponse& operator=(const CWaitResponse&);
public:
	static CWaitResponse* Instance();
	virtual void Enter(CClientSocket *client);
	virtual void Exit(CClientSocket *client);
	virtual void Execute(CClientSocket *client);
};

class CWaitMessage : public State<CClientSocket>
{
private:
	CWaitMessage(){}
	CWaitMessage(const CWaitMessage&);
	CWaitMessage& operator=(const CWaitMessage&);
public:
	static CWaitMessage* Instance();
	virtual void Enter(CClientSocket *client);
	virtual void Exit(CClientSocket *client);
	virtual void Execute(CClientSocket *client);
};