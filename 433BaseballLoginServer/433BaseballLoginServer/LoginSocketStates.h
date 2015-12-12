#pragma once

class CWaitResponse : public State<CLoginSocket>
{
private:
	CWaitResponse(){}
	CWaitResponse(const CWaitResponse&);
	CWaitResponse& operator=(const CWaitResponse&);
public:
	static CWaitResponse* Instance();
	virtual void Enter(CLoginSocket *login);
	virtual void Exit(CLoginSocket *login);
	virtual void Execute(CLoginSocket *login);
};

class CWaitMessage : public State<CLoginSocket>
{
private:
	CWaitMessage(){}
	CWaitMessage(const CWaitMessage&);
	CWaitMessage& operator=(const CWaitMessage&);
public:
	static CWaitMessage* Instance();
	virtual void Enter(CLoginSocket *login);
	virtual void Exit(CLoginSocket *login);
	virtual void Execute(CLoginSocket *login);
};