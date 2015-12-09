#pragma once

#pragma warning(disable : 4002)

#include "targetver.h"

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")

#include <stdio.h>
#include <tchar.h>
#include <string>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <MSWSock.h>

#include <Windows.h>

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <process.h>

#include <mysql.h>

//----------------------------------------------------

#define SERVERPORT					9000
#define DB_PORT						3306
#define BUFSIZE						1024
#define SOCKET_POOL_SIZE			3000
#define HEADER_SIZE					2
#define WAIT_AVAILABLE_HANDLE_TIME	100

//----------------------------------------------------

struct CGlobalManager;

class CLogWriter;

template <class entity_type>
class State;
template <class entity_type>
class StateMachine;

class CWaitResponse;
class CWaitMessage;

class CDBClosed;
class CDBIdle;
class CDBWaitResult;

class CDBManager;
class CClientManager;

class CActor;

struct CConnector;
struct CDisconnector;
struct CReceiver;
struct CSender;
struct CAcceptor;

struct CDBConnector;
struct CDBDisconnector;
struct CDBQuerier;
struct CDBHarvester;

struct CProactor;

struct CSockInfo;
struct CClientSocket;

struct CDBHandle;

struct CAct;

struct CClientAct;
struct CDBAct;

#define MYPRINTF(A) CGlobalManager::GetInstance().logWriter.MyPrintf(A)

#include "LogWriter.h"

#include "GlobalManager.h"

#include "Act.h"
#include "ClientAct.h"
#include "DBAct.h"

#include "State.h"
#include "StateMachine.h"

#include "SockInfo.h"
#include "ClientSocket.h"
#include "ListenSocket.h"

#include "DBHandle.h"

#include "Actor.h"

#include "Connector.h"
#include "Disconnector.h"
#include "Sender.h"
#include "Receiver.h"
#include "Acceptor.h"

#include "DBConnector.h"
#include "DBDisconnector.h"
#include "DBQuerier.h"
#include "DBHarvester.h"

#include "Proactor.h"

#include "DBManager.h"
#include "ClientManager.h"

#include "ClientSocketStates.h"
#include "DBHandleStates.h"