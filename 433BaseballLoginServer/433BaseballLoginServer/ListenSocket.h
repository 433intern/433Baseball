#pragma once

struct CListenSocket : public CSockInfo
{
	int backlogSize;
	
	CListenSocket();
	~CListenSocket();

	bool Init(WORD port, int backlogSizeParam = 0);
	bool Listen(CProactor& proactor);
};