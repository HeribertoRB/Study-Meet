#include "studymeet.h"


StudyMeet::StudyMeet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	DatabaseHandler *db = DatabaseHandler::get_instance();
	db->connect();
	db->is_open();
}

StudyMeet::~StudyMeet()
{
	
}

void StudyMeet::on_toVSWButton_clicked()
{
	ViewSessions *vs = new ViewSessions;
	vs->show();
	this->close();
}

void StudyMeet::on_toDSWButton_clicked()
{
	DatabaseHandler *db = DatabaseHandler::get_instance();
	db->is_open();


	DetailedStudySession *ds = new DetailedStudySession;
	ds->show();
	this->close();
}