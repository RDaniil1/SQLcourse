#ifndef EDITENTRYDRIVER_H
#define EDITENTRYDRIVER_H

#include <QDialog>

namespace Ui {
class EditEntryDriver;
}

class EditEntryDriver : public QDialog
{
    Q_OBJECT

public:
    explicit EditEntryDriver(QWidget *parent = nullptr);
    ~EditEntryDriver();

    void CopyValues(QString &idDriver, QString &firstLast,
                    QString &passportNum, QString &driverDocument, QString &category);


private:
    Ui::EditEntryDriver *ui;
};

#endif // EDITENTRYDRIVER_H
