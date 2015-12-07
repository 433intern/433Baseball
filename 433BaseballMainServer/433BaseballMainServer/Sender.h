#pragma once
struct CSender : public CActor
{
	CSender();
	~CSender();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer(CProactor *proactor);
};