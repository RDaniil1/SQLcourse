#include "deleteentryroutesheet.h"
#include "ui_deleteentryroutesheet.h"

DeleteEntryRouteSheet::DeleteEntryRouteSheet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteEntryRouteSheet)
{
    ui->setupUi(this);
}

DeleteEntryRouteSheet::~DeleteEntryRouteSheet()
{
    delete ui;
}

void DeleteEntryRouteSheet::CopyValues(QString &idRouteSheet)
{
    idRouteSheet = ui->idRouteSheetEdit->text();
}
