#pragma once
class CDisconnector : public CActor
{
public:
	CDisconnector();
	~CDisconnector();

	bool EventProc(DWORD receivedBytes);
	bool ErrorProc(DWORD error);

	bool Initializer();
};

