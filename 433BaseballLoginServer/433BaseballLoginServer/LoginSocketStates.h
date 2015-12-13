#pragma once

class CWaitCreateAccountResponse : public State<CLoginSocket>
{
private:
	CWaitCreateAccountResponse(){}
	CWaitCreateAccountResponse(const CWaitCreateAccountResponse&);
	CWaitCreateAccountResponse& operator=(const CWaitCreateAccountResponse&);
public:
	static CWaitCreateAccountResponse* Instance();
	virtual void Enter(CLoginSocket *login);
	virtual void Exit(CLoginSocket *login);
	virtual void Execute(CLoginSocket *login);
};

class CWaitLoginResponse : public State<CLoginSocket>
{
private:
	CWaitLoginResponse(){}
	CWaitLoginResponse(const CWaitLoginResponse&);
	CWaitLoginResponse& operator=(const CWaitLoginResponse&);
public:
	static CWaitLoginResponse* Instance();
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

class CDisconnected : public State<CLoginSocket>
{
private:
	CDisconnected(){}
	CDisconnected(const CDisconnected&);
	CDisconnected& operator=(const CDisconnected&);
public:
	static CDisconnected* Instance();
	virtual void Enter(CLoginSocket *login);
	virtual void Exit(CLoginSocket *login);
	virtual void Execute(CLoginSocket *login);
};