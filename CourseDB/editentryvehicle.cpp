#include "editentryvehicle.h"
#include "ui_editentryvehicle.h"

EditEntryVehicle::EditEntryVehicle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEntryVehicle)
{
    ui->setupUi(this);
}

EditEntryVehicle::~EditEntryVehicle()
{
    delete ui;
}

void EditEntryVehicle::CopyValues(QString &idVehicle, QString &idDriver, QString &vehicleAmount, QString &releaseTime, QString &stateNum, QString &vin)
{
    idVehicle = ui->idVehicleEdit->text();
    idDriver = ui->idDriverEdit->text();
    vehicleAmount = ui->vehicleAmountEdit->text();
    releaseTime = ui->releaseTimeEdit->text();
    stateNum = ui->stateNumEdit->text();
    vin = ui->vinEdit->text();
}
