#include "deleteentryvehicle.h"
#include "ui_deleteentryvehicle.h"

DeleteEntryVehicle::DeleteEntryVehicle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteEntryVehicle)
{
    ui->setupUi(this);
}

DeleteEntryVehicle::~DeleteEntryVehicle()
{
    delete ui;
}

void DeleteEntryVehicle::CopyValues(QString &idVehicle)
{
    idVehicle = ui->idVehicleEdit->text();
}
