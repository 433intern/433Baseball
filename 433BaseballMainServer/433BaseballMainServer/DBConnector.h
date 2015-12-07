#pragma once

typedef struct CDBConnector : public CActor
{
	CDBConnector();
	~CDBConnector();

	bool EventProc(CAct *act, DWORD receivedBytes);
	bool ErrorProc(CAct *act, DWORD error);

	bool Initializer(CProactor *proactor);
}CDBConnector;

