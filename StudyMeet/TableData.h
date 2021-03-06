#pragma once

#include "DatabaseHandler.h"
#include <iterator>
#include <string>

class TableData
{
public:
	list<Session> listSessions;
	list<Session> displaySessions;

	Session find_session(string);
	Session find_session_sessid(string);

	int add_to_list(Session);
	int remove_from_list(string);
	int get_data();
	int amount_of_sessions() const { return listSessions.size(); }

	~TableData();
	static TableData* get_instance();
private:
	TableData();
protected:
	static TableData *instance;
};

