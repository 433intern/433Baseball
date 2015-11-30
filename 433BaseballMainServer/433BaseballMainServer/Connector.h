#pragma once
class CConnector : public CActor
{
public:
	CConnector();
	~CConnector();

	bool EventProc(DWORD receivedBytes);
	bool ErrorProc(DWORD error);

	bool Initializer();
};

