#ifndef DETAILEDSTUDYSESSION_H
#define DETAILEDSTUDYSESSION_H

#include <QWidget>
#include "ui_detailedstudysession.h"
#include "DatabaseHandler.h"
#include "ErrorHandler.h"
#include "AccountSingleton.h"

class DetailedStudySession : public QWidget, public Ui::DetailedStudySession
{
	Q_OBJECT

public:
	DetailedStudySession(QWidget *parent = 0);
	~DetailedStudySession();
	void populate_fields();
protected:

public slots :
	void on_leaveButton_clicked();
	void on_deleteButton_clicked();
	void on_joinButton_clicked();
	
private:
	DatabaseHandler *db;
	ErrorHandler *er;
	AccountSingleton *ac;
};

#endif // DETAILEDSTUDYSESSION_H
