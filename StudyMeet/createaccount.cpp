#include "createaccount.h"

CreateAccount::CreateAccount(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

CreateAccount::~CreateAccount()
{

}

void CreateAccount::on_enterButton_clicked()
{
	QString username = emailEdit->text();
	QString password = passwordEdit->text();
	QByteArray hpassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha1);
	QString hstring(hpassword.toHex());

	if (!username.isEmpty() && !hstring.isEmpty())
	{
		add_account(username, hstring);
	}
	close();
}

void CreateAccount::add_account(QString user, QString pw)
{
	DatabaseHandler db;
	ErrorHandler err;

	if (!db.open())
		return;
	
	QSqlQuery query(db.get_db());
	query.prepare("INSERT INTO users (username, password_hash) "
		"VALUES (?, ?)");
	query.addBindValue(user);
	query.addBindValue(pw);

	if (!query.exec())
		err.display_error(query.lastError().text());
}