#pragma once

#include "targetver.h"

#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>
#include <tchar.h>

#include <WinSock2.h>
#include <Windows.h>

#include <MSWSock.h>

#include <iostream>
#include <vector>
#include <fstream>
#include <process.h>

#include <mysql.h>

//----------------------------------------------------

#define SERVERPORT		9000
#define BUFSIZE			5012

//----------------------------------------------------

struct CGlobalManager;

class CLogWriter;

class CDBManager;
class CClientManager;

class CActor;

class CConnector;
class CDisconnector;
class CReceiver;
class CSender;
class CAcceptor;

struct CProactor;

struct CClientSocket;

struct CAct;

struct CClientAct;
struct CDBAct;

extern CGlobalManager *globalManager;

#define MYPRINTF(A) globalManager->logWriter.MyPrintf(A)

#include "LogWriter.h"

#include "GlobalManager.h"

#include "ClientSocket.h"

#include "Act.h"
#include "ClientAct.h"
#include "DBAct.h"

#include "Actor.h"

#include "Connector.h"
#include "Disconnector.h"
#include "Sender.h"
#include "Receiver.h"
#include "Acceptor.h"

#include "Proactor.h"

#include "DBManager.h"
#include "ClientManager.h"