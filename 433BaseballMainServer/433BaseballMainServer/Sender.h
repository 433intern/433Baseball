#pragma once
class CSender : public CActor
{
public:
	CSender();
	~CSender();

	bool EventProc(DWORD receivedBytes);
	bool ErrorProc(DWORD error);

	bool Initializer();
};