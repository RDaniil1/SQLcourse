#ifndef DELETEENTRYVEHICLE_H
#define DELETEENTRYVEHICLE_H

#include <QDialog>

namespace Ui {
class DeleteEntryVehicle;
}

class DeleteEntryVehicle : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteEntryVehicle(QWidget *parent = nullptr);
    ~DeleteEntryVehicle();

    void CopyValues(QString &idVehicle);

private:
    Ui::DeleteEntryVehicle *ui;
};

#endif // DELETEENTRYVEHICLE_H
