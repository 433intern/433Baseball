#pragma once

typedef struct CDBAct : public CAct
{
	CDBAct();
	~CDBAct();

	bool Complete(DWORD bytes_transferred);
	bool Error(DWORD error);
}CDBAct;