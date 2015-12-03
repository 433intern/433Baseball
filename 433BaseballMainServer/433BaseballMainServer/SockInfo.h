#pragma once

typedef struct CSockInfo
{
	SOCKET			socket;
	SOCKADDR_IN		addr;

	CSockInfo();
	~CSockInfo();
}CSockInfo;

