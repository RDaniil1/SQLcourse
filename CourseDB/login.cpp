#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::CopyValues(QString &username, QString &password)
{
    username = ui->usernameEdit->text();
    password = ui->passwordEdit->text();
}
