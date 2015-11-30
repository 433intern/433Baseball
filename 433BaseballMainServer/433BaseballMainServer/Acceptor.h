#pragma once

class CAcceptor : public CActor
{
public:
	CAcceptor();
	~CAcceptor();

	bool EventProc(DWORD receivedBytes);
	bool ErrorProc(DWORD error);

	bool Initializer();
};

