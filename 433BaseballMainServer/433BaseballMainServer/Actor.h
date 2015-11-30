#pragma once
class CActor
{
public:
	CActor();
	~CActor();

	virtual bool EventProc(DWORD receivedBytes) = 0;
	virtual bool ErrorProc(DWORD error) = 0;
};