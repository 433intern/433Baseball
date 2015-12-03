#pragma once
class CActor
{
public:
	CActor();
	~CActor();

	CProactor		*proactor;

	virtual bool EventProc(CAct *act, DWORD receivedBytes) = 0;
	virtual bool ErrorProc(CAct *act, DWORD error) = 0;
};