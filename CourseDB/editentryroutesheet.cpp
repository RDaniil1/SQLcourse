#include "editentryroutesheet.h"
#include "ui_editentryroutesheet.h"

EditEntryRouteSheet::EditEntryRouteSheet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEntryRouteSheet)
{
    ui->setupUi(this);
}

EditEntryRouteSheet::~EditEntryRouteSheet()
{
    delete ui;
}

void EditEntryRouteSheet::CopyValues(QString &idRouteSheet, QString &idVehicle, QString &idDestination, QString &organisation, QString &reason, QString &timeStamp)
{
    idRouteSheet = ui->idRouteSheetEdit->text();
    idVehicle = ui->idVehicleEdit->text();
    idDestination = ui->idDestinationEdit->text();
    organisation = ui->organisationEdit->text();
    reason = ui->reasonEdit->text();
    timeStamp = ui->timeStampEdit->text();
}
