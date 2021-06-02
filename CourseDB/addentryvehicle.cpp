#include "addentryvehicle.h"
#include "ui_addentryvehicle.h"

AddEntryVehicle::AddEntryVehicle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntryVehicle)
{
    ui->setupUi(this);
}

AddEntryVehicle::~AddEntryVehicle()
{
    delete ui;
}

void AddEntryVehicle::CopyValues(QString &idVehicle, QString &idDriver, QString &vehicleAmount, QString &releaseTime, QString &stateNum, QString &vin)
{
    idVehicle = ui->idVehicleEdit->text();
    idDriver = ui->idDriverEdit->text();
    vehicleAmount = ui->vehicleAmountEdit->text();
    releaseTime = ui->releaseTimeEdit->text();
    stateNum = ui->stateNumEdit->text();
    vin = ui->vinEdit->text();
}
