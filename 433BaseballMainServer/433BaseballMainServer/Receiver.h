#pragma once
typedef struct CReceiver : public CActor
{
	CReceiver();
	~CReceiver();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer(CProactor *proactor);
}CReceiver;

