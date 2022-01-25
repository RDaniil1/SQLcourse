#include "addentrydestination.h"
#include "ui_addentrydestination.h"

AddEntryDestination::AddEntryDestination(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntryDestination)
{
    ui->setupUi(this);
}

AddEntryDestination::~AddEntryDestination()
{
    delete ui;
}

void AddEntryDestination::CopyValues(QString &firstLastDst, QString &phoneNumber,
                                     QString &documentType, QString &productSum)
{
    firstLastDst = ui->firstLastDstEdit->text();
    phoneNumber = ui->phoneNumberEdit->text();
    documentType = ui->documentTypeEdit->text();
    productSum = ui->productSumEdit->text();
}
