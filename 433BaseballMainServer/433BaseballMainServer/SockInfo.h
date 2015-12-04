#pragma once

typedef struct CSockInfo
{
	SOCKET			sock;
	SOCKADDR_IN		addr;

	CSockInfo();
	~CSockInfo();
}CSockInfo;

