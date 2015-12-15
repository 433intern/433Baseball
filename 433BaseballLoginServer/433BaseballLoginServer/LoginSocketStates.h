#pragma once

class CToSendCreateAccountResponse : public State<CLoginSocket>
{
private:
	CToSendCreateAccountResponse(){}
	CToSendCreateAccountResponse(const CToSendCreateAccountResponse&);
	CToSendCreateAccountResponse& operator=(const CToSendCreateAccountResponse&);
public:
	static CToSendCreateAccountResponse* Instance();
	virtual void Enter(CLoginSocket *login);
	virtual void Exit(CLoginSocket *login);
	virtual void Execute(CLoginSocket *login);
};

class CSentCreateAccountResponse : public State<CLoginSocket>
{
private:
	CSentCreateAccountResponse(){}
	CSentCreateAccountResponse(const CSentCreateAccountResponse&);
	CSentCreateAccountResponse& operator=(const CSentCreateAccountResponse&);
public:
	static CSentCreateAccountResponse* Instance();
	virtual void Enter(CLoginSocket *login);
	virtual void Exit(CLoginSocket *login);
	virtual void Execute(CLoginSocket *login);
};

class CWaitCreateAccountBody : public State<CLoginSocket>
{
private:
	CWaitCreateAccountBody(){}
	CWaitCreateAccountBody(const CWaitCreateAccountBody&);
	CWaitCreateAccountBody& operator=(const CWaitCreateAccountBody&);
public:
	static CWaitCreateAccountBody* Instance();
	virtual void Enter(CLoginSocket *login);
	virtual void Exit(CLoginSocket *login);
	virtual void Execute(CLoginSocket *login);
};

class CWaitLoginBody : public State<CLoginSocket>
{
private:
	CWaitLoginBody(){}
	CWaitLoginBody(const CWaitLoginBody&);
	CWaitLoginBody& operator=(const CWaitLoginBody&);
public:
	static CWaitLoginBody* Instance();
	virtual void Enter(CLoginSocket *login);
	virtual void Exit(CLoginSocket *login);
	virtual void Execute(CLoginSocket *login);
};

class CWaitHeader : public State<CLoginSocket>
{
private:
	CWaitHeader(){}
	CWaitHeader(const CWaitHeader&);
	CWaitHeader& operator=(const CWaitHeader&);
public:
	static CWaitHeader* Instance();
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