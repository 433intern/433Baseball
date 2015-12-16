#pragma once

class CDBClosed : public State<CDBHandle>
{
private:
	CDBClosed(){}
	CDBClosed(const CDBClosed&);
	CDBClosed& operator=(const CDBClosed&);
public:
	static CDBClosed* Instance();
	virtual void Enter(CDBHandle *dbHandle);
	virtual void Exit(CDBHandle *dbHandle);
	virtual void Execute(CDBHandle *dbHandle);
};

class CDBIdle : public State<CDBHandle>
{
private:
	CDBIdle(){}
	CDBIdle(const CDBIdle&);
	CDBIdle& operator=(const CDBIdle&);
public:
	static CDBIdle* Instance();
	virtual void Enter(CDBHandle *dbHandle);
	virtual void Exit(CDBHandle *dbHandle);
	virtual void Execute(CDBHandle *dbHandle);
};

class CDBWaitResult : public State<CDBHandle>
{
private:
	CDBWaitResult(){}
	CDBWaitResult(const CDBWaitResult&);
	CDBWaitResult& operator=(const CDBWaitResult&);
public:
	static CDBWaitResult* Instance();
	virtual void Enter(CDBHandle *dbHandle);
	virtual void Exit(CDBHandle *dbHandle);
	virtual void Execute(CDBHandle *dbHandle);
};