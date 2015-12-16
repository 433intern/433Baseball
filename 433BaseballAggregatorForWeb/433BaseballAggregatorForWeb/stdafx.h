#pragma once

#include "targetver.h"

#include <mysql.h>

#include <Windows.h>
#include <winsvc.h>

#include <stdio.h>
#include <tchar.h>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/uri.h>
#include <cpprest/ws_client.h>
#include <cpprest/containerstream.h>
#include <cpprest/interopstream.h>
#include <cpprest/rawptrstream.h>
#include <cpprest/producerconsumerstream.h>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

using namespace web::http::experimental::listener;
using namespace web::experimental::web_sockets::client;
using namespace web::json;

class CAggregator;
class CGlobalManager;

#include "Aggregator.h"
#include "GlobalManager.h"
