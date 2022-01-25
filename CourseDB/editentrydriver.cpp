#include "editentrydriver.h"
#include "ui_editentrydriver.h"

EditEntryDriver::EditEntryDriver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEntryDriver)
{
    ui->setupUi(this);
}

EditEntryDriver::~EditEntryDriver()
{
    delete ui;
}

void EditEntryDriver::CopyValues(QString &firstLast, QString &passportNum, QString &driverDocument, QString &category)
{
    firstLast = ui->firstLastEdit->text();
    passportNum = ui->passportNumEdit->text();
    driverDocument = ui->driverDocumentEdit->text();
    category = ui->categoryEdit->text();
}
