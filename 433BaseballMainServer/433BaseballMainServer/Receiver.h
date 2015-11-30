#pragma once
class CReceiver : public CActor
{
public:
	CReceiver();
	~CReceiver();

	bool EventProc(DWORD receivedBytes);
	bool ErrorProc(DWORD error);

	bool Initializer();
};

