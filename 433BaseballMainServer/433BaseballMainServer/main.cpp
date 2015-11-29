#include "stdafx.h"

CGlobalManager *globalManager;

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "570104"
#define DB_NAME "player_statics"
int _tmain(int argc, _TCHAR* argv[])
{
	globalManager = new CGlobalManager();

	HANDLE dbHandle = NULL;

	CDBManager dbManager(dbHandle);

	MYSQL *connection = NULL, conn;
	MYSQL_RES *sql_result;
	MYSQL_ROW sql_row;
	int query_stat;

	//------------------------------------

	// DB initializing
	mysql_init(&conn);

	// DB connecting
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0);
	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}

	// For using Korean
	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	char *query = "CREATE TABLE test(id INT, label CHAR(1))";
	query_stat = mysql_query(connection, query);

	// Printing the result
	/*sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		printf("%2s %2s %s\n", sql_row[0], sql_row[1], sql_row[2]);
	}
	mysql_free_result(sql_result);*/

	// DB Closing
	mysql_close(connection);

	//------------------------------------

	Sleep(INFINITE);

	delete globalManager;

	return 0;
}

