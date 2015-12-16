#pragma once

struct CConnector : public CActor
{
public:
	CConnector();
	~CConnector();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer(CProactor *proactor);
};
