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

void AddEntryRouteSheet::CopyValues(QString &organisation, QString &reason, QString &timeStamp)
{
    organisation = ui->organisationEdit->text();
    reason = ui->reasonEdit->text();
    timeStamp = ui->timeStampEdit->text();
}
