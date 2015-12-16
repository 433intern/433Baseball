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
#define SERVERPORT 8000
#define BUFSIZE    1024
#define HEADERSIZE 10

enum PLAYER_STATE
{
	LOBBY,
	INROOM,
	INGAME
};

class CGlobalManager;

void ShowAllCurrentRooms(const protocol::SC_total_room_info &roomInfo);
bool ReceivingMessage(SOCKET &sock, int byteSize, protobuf::Message &message);
bool SendingMessage(SOCKET &sock, int byteSize, protocol::PacketType type, protobuf::Message &messageToSend);
bool PingPongMsg(SOCKET &sock, int sentBytes, const protocol::PacketType &type, protocol::PacketHeader &header, protobuf::Message *messageToSend, protobuf::Message &resultMessage);
bool interpretFailSignal(const protocol::FailSignal &fail);

bool InLobby();
bool InRoom();
bool InGame();

void err_quit(char *msg);
void err_display(char *msg);

int recvn(SOCKET s, char *buf, int len, int flags);

#include "GlobalManager.h"