#ifndef ADDENTRYDRIVER_H
#define ADDENTRYDRIVER_H

#include <QDialog>

namespace Ui {
class AddEntryDriver;
}

class AddEntryDriver : public QDialog
{
    Q_OBJECT

public:
    explicit AddEntryDriver(QWidget *parent = nullptr);
    ~AddEntryDriver();
    void CopyValues(QString &firstLast,
                    QString &passportNum, QString &driverDocument, QString &category);

private:
    Ui::AddEntryDriver *ui;
};

#endif // ADDENTRYDRIVER_H
