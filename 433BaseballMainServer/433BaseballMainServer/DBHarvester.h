#pragma once
struct CDBHarvester : public CActor
{
	CDBHarvester();
	~CDBHarvester();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer();
};

