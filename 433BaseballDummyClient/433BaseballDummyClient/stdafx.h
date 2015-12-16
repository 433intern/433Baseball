#pragma once

#include "targetver.h"

#pragma comment(lib, "ws2_32")

#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <tchar.h>

#include "GamePacketEnumeration.pb.h"
#include "IngamePacket.pb.h"
#include "RoomPacket.pb.h"

using namespace std;
using namespace google;

#define SERVERIP   "127.0.0.1"
#define SERVERPORT 9001
#define BUFSIZE    1024