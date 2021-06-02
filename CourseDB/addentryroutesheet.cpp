#include "addentryroutesheet.h"
#include "ui_addentryroutesheet.h"

AddEntryRouteSheet::AddEntryRouteSheet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntryRouteSheet)
{
    ui->setupUi(this);
}

AddEntryRouteSheet::~AddEntryRouteSheet()
{
    delete ui;
}

void AddEntryRouteSheet::CopyValues(QString &idRouteSheet, QString &idVehicle, QString &idDestination,
                                    QString &organisation, QString &reason, QString &timeStamp)
{
    idRouteSheet = ui->idRouteSheetEdit->text();
    idVehicle = ui->idVehicleEdit->text();
    idDestination = ui->idDestinationEdit->text();
    organisation = ui->organisationEdit->text();
    reason = ui->reasonEdit->text();
    timeStamp = ui->timeStampEdit->text();
}
