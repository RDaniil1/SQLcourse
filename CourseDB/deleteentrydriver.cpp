#include "deleteentrydriver.h"
#include "ui_deleteentrydriver.h"

DeleteEntryDriver::DeleteEntryDriver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteEntryDriver)
{
    ui->setupUi(this);
}

DeleteEntryDriver::~DeleteEntryDriver()
{
    delete ui;
}

void DeleteEntryDriver::CopyValues(QString &idDriver)
{
    idDriver = ui->idDriverEdit->text();
}
