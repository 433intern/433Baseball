#include "stdafx.h"

CSockInfo::CSockInfo()
{
	sock = INVALID_SOCKET;
	memset(&addr, 0, sizeof(SOCKADDR_IN));
}

CSockInfo::~CSockInfo()
{
}
