#include "dblogger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mariadb/mysql.h>

static MYSQL *conn = NULL;

static void log_error(const char *msg)
{
  FILE *logf = fopen("../logs/logger.log", "a");
  if (logf)
  {
    fprintf(logf, "%s\n", msg);
    fclose(logf);
  }
}

#define CHECK_DB(expr)            \
  if ((expr))                     \
  {                               \
    log_error(mysql_error(conn)); \
    return 0;                     \
  }

int DB_Init(const char *host, const char *user, const char *pass, const char *dbname)
{
  conn = mysql_init(NULL);
  if (!conn)
  {
    log_error("mysql_init() failed");
    return 0;
  }
  if (!mysql_real_connect(conn, host, user, pass, NULL, 0, NULL, 0))
  {
    log_error(mysql_error(conn));
    return 0;
  }
  char query[256];
  snprintf(query, sizeof(query), "CREATE DATABASE IF NOT EXISTS %s", dbname);
  CHECK_DB(mysql_query(conn, query));
  CHECK_DB(mysql_select_db(conn, dbname));
  return 1;
}

int DB_GPIOLog(const char *table, int pin, int value)
{
  if (!conn)
    return 0;
  char query[256];
  snprintf(query, sizeof(query),
           "CREATE TABLE IF NOT EXISTS %s ("
           "id INT AUTO_INCREMENT PRIMARY KEY,"
           "datetime DATETIME DEFAULT CURRENT_TIMESTAMP,"
           "pin INT NOT NULL,"
           "value INT NOT NULL"
           ")",
           table);
  CHECK_DB(mysql_query(conn, query));
  snprintf(query, sizeof(query),
           "INSERT INTO %s (pin, value) VALUES (%d, %d)", table, pin, value);
  CHECK_DB(mysql_query(conn, query));
  return 1;
}

void DB_Close()
{
  if (conn)
  {
    mysql_close(conn);
    conn = NULL;
  }
}