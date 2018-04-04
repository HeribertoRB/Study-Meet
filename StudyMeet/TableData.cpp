#include "TableData.h"


TableData* TableData::instance = 0;

Session TableData::find_session(string s)
{
	for (list<Session>::iterator it = listSessions.begin(); it != listSessions.end(); it++)
	{
		if (s == to_string(it->get_hostId()))
		{
			ErrorHandler * err = ErrorHandler::get_instance();
			err->display_error(QString::fromStdString((*it).get_location()));
			return *it;
		}
	}
	Session se("ERRORID", -1, "ERRORTIMESTART", -1, "ERRORTIMEEND","ERRORDATE", "ERRORSUBJECT", "ERRORLOCATION", 
		-1, "ERROR DESCRIPTION");
	return se;
}

TableData::TableData()
{
	DatabaseHandler* handler = DatabaseHandler::get_instance();
	handler->load_all_sessions(listSessions);
}

TableData* TableData::get_instance()
{
	if (instance == 0)
		instance = new TableData();

	return instance;
}

int TableData::add_to_list(Session s)
{
	listSessions.push_back(s);

	return 0;
}

TableData::~TableData()
{
}

