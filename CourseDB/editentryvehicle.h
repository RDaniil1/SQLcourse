#ifndef EDITENTRYVEHICLE_H
#define EDITENTRYVEHICLE_H

#include <QDialog>

namespace Ui {
class EditEntryVehicle;
}

class EditEntryVehicle : public QDialog
{
    Q_OBJECT

public:
    explicit EditEntryVehicle(QWidget *parent = nullptr);
    ~EditEntryVehicle();

    void CopyValues(QString &vehicleAmount, QString &releaseTime,
                    QString &stateNum, QString &vin);

private:
    Ui::EditEntryVehicle *ui;
};

#endif // EDITENTRYVEHICLE_H
