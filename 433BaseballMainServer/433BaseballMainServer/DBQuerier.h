#pragma once
struct CDBQuerier : public CActor
{
	CDBQuerier();
	~CDBQuerier();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer(CProactor *proactor);
};