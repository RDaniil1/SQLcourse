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

void EditEntryRouteSheet::CopyValues(QString &organisation, QString &reason, QString &timeStamp)
{
    organisation = ui->organisationEdit->text();
    reason = ui->reasonEdit->text();
    timeStamp = ui->timeStampEdit->text();
}
