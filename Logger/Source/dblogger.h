#ifndef DBLOGGER_H
#define DBLOGGER_H

int DB_Init(const char *host, const char *user, const char *pass, const char *dbname);
int DB_GPIOLog(const char *table, int pin, int value);
void DB_Close();

#endif