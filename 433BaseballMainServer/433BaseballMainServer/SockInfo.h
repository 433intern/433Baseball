#pragma once

struct CSockInfo
{
	SOCKET			sock;
	SOCKADDR_IN		addr;

	CSockInfo();
	~CSockInfo();
};

