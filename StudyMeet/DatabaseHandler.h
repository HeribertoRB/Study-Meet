#pragma once

#include <QtSql>
#include <list>
#include "ErrorHandler.h"
#include "Account.h"
#include "Session.h"
#include "AccountSingleton.h"

class DatabaseHandler
{
private:
	QSqlDatabase db;
	ErrorHandler *error_window;
	QSqlQuery query;
	int connection_status;

	DatabaseHandler();
	int connect();
	int is_open();
public:
	static DatabaseHandler* get_instance();
	~DatabaseHandler();
	int get_connection_status() const { return connection_status; }
	int add_to_database(Session);
	int add_to_database(Account);
	int update_session(Session);
	int update_account(AccountSingleton*);
	int remove_session(Session);
	int is_host(Session);
	int is_in_session(Account);
	int load_all_sessions(std::list<Session>&);
	int validate_account(std::string, std::string);
	int validate_account(int);
	int validate_account(std::string);
	Account get_account(std::string username, std::string pass);
	Account get_account(int);
	int validate_session(int);
	int join_session(int, std::string);
	int leave_session(int, std::string);

protected:
	static DatabaseHandler *inst;
};

