#pragma once

typedef struct CAct : public OVERLAPPED
{
	CActor *actor;

	CAct();
	~CAct();

	bool Initializer(CActor *actors);

	virtual bool Complete(DWORD bytes_transferred) = 0;
	virtual bool Error(DWORD error) = 0;
}CAct;

