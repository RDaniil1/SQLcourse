#ifndef ADDENTRYVEHICLE_H
#define ADDENTRYVEHICLE_H

#include <QDialog>

namespace Ui {
class AddEntryVehicle;
}

class AddEntryVehicle : public QDialog
{
    Q_OBJECT

public:
    explicit AddEntryVehicle(QWidget *parent = nullptr);
    ~AddEntryVehicle();

    void CopyValues(QString &idVehicle, QString &idDriver,
                    QString &vehicleAmount, QString &releaseTime,
                    QString &stateNum, QString &vin);

private:
    Ui::AddEntryVehicle *ui;
};

#endif // ADDENTRYVEHICLE_H
