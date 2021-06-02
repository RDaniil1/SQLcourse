#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void CopyValues(QString &username, QString &password);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
