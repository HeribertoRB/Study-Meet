#include "studymeet.h"
#include <QtWidgets/QApplication>

//test comment
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	StudyMeet w;

	w.show();
	return a.exec();
}
