#pragma once

struct CDisconnector : public CActor
{
	CDisconnector();
	~CDisconnector();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer();
};

