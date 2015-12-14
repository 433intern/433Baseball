#pragma once

#pragma warning(disable : 4002)
#pragma warning(disable : 4996)

#include "targetver.h"

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <wchar.h>
#include <stdlib.h>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <MSWSock.h>

#include <Windows.h>
#include <winsvc.h>

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <process.h>

#include <mysql.h>

//----------------------------------------------------

#define SERVERPORT					9001
#define DB_PORT						3306
#define BUFSIZE						1024
#define SOCKET_POOL_SIZE			3000
#define HEADER_SIZE					10
#define WAIT_AVAILABLE_HANDLE_TIME	100
#define WAIT_AVAILABLE_SOCKET_TIME	100
#define IP_ADDRESS					"127.0.0.1"

//----------------------------------------------------

struct CGlobalManager;

class CLogWriter;

template <class entity_type>
class State;
template <class entity_type>
class StateMachine;

class CToSendLoginResponse;
class CToSendCreateAccountResponse;
class CSentLoginResponse;
class CSentCreateAccountResponse;
class CWaitLoginBody	;
class CWaitCreateAccountBody;
class CWaitHeader;
class CDisconnected;

class CDBClosed;
class CDBIdle;
class CDBWaitResult;

class CDBManager;
class CLoginManager;

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
struct CLoginSocket;

struct CDBHandle;

struct CAct;

struct CLoginAct;
struct CDBAct;

#define MYERRORPRINTF(A) CGlobalManager::GetInstance().logWriter.MyErrorPrintf(A, typeid(this).name(), __FUNCTION__)
#define MYSERVICEERRORPRINTF(A) CGlobalManager::GetInstance().logWriter.MyServiceErrorPrintf(A, __FUNCTION__)
#define MYDBERRORPRINTF(A,B) CGlobalManager::GetInstance().logWriter.MyDBErrorPrintf(A,B, __FUNCTION__)
#define MYPRINTF(A) CGlobalManager::GetInstance().logWriter.MyPrintf(A)

#include "LoginMessage.PROTO.pb.h"

#include "Utils.h"

#include "LogWriter.h"

#include "GlobalManager.h"

#include "Act.h"
#include "LoginAct.h"
#include "DBAct.h"

#include "State.h"
#include "StateMachine.h"

#include "SockInfo.h"
#include "LoginSocket.h"
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
#include "LoginManager.h"

#include "LoginSocketStates.h"
#include "DBHandleStates.h"