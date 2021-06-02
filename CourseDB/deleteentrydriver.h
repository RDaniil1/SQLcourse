#ifndef DELETEENTRYDRIVER_H
#define DELETEENTRYDRIVER_H

#include <QDialog>

namespace Ui {
class DeleteEntryDriver;
}

class DeleteEntryDriver : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteEntryDriver(QWidget *parent = nullptr);
    ~DeleteEntryDriver();

    void CopyValues(QString &idDriver);

private:
    Ui::DeleteEntryDriver *ui;
};

#endif // DELETEENTRYDRIVER_H
