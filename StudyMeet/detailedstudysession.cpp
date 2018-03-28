#include "detailedstudysession.h"
#include "viewsessions.h"

//DetailedStudySession* DetailedStudySession::instance = NULL; 

DetailedStudySession::DetailedStudySession(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	populate_fields();
}

DetailedStudySession::~DetailedStudySession()
{

}
/*
DetailedStudySession * DetailedStudySession::Instance()
{
	
	if (instance == NULL)
		instance = new DetailedStudySession();
	DetailedStudySession::populate_fields();
	return instance; 
}
*/
void DetailedStudySession::populate_fields()
{
	ViewSessions *vs = ViewSessions::Instance();
	Session se = vs->get_selected_session();

	hostEdit->setText(QString::number(se.get_hostId()));
	subjectEdit->setText(QString::fromStdString(se.get_subject()));
	timeEdit->setText(QString::fromStdString(se.get_timestart()));
	locationEdit->setText(QString::fromStdString(se.get_location()));
	sizeEdit->setText(QString::number(se.get_currentnumberofpeopleinsession()));
	limitEdit->setText(QString::number(se.get_maximumcapacityofpeopleinsession()));
	descriptionEdit->setText(QString::fromStdString(se.get_description()));
}
