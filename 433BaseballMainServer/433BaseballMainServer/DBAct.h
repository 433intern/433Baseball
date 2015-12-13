#pragma once

struct CDBAct : public CAct
{
	CDBHandle		*dbHandle;

	CDBAct();
	~CDBAct();

	bool Initializer(CActor *actorParam, CDBHandle *handleParam);
	bool Complete(DWORD bytes_transferred);
	bool Error(DWORD error);
};