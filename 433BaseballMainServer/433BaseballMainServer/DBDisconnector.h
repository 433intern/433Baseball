#pragma once
struct CDBDisconnector : public CActor
{
	CDBDisconnector();
	~CDBDisconnector();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer();
};

