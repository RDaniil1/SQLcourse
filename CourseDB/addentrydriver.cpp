#include "addentrydriver.h"
#include "ui_addentrydriver.h"

AddEntryDriver::AddEntryDriver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntryDriver)
{
    ui->setupUi(this);
}

AddEntryDriver::~AddEntryDriver()
{
    delete ui;
}

void AddEntryDriver::CopyValues(QString &idDriver, QString &firstLast,
                                QString &passportNum, QString &driverDocument, QString &category)
{
    idDriver = ui->idDriverEdit->text();
    firstLast = ui->firstLastEdit->text();
    passportNum = ui->passportNumEdit->text();
    driverDocument = ui->driverDocumentEdit->text();
    category = ui->categoryEdit->text();
}
