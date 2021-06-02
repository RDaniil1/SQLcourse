#include "editentrydestination.h"
#include "ui_editentrydestination.h"

EditEntryDestination::EditEntryDestination(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEntryDestination)
{
    ui->setupUi(this);
}

EditEntryDestination::~EditEntryDestination()
{
    delete ui;
}

void EditEntryDestination::CopyValues(QString &firstLastDst, QString &phoneNumber, QString &documentType, QString &productSum)
{
    firstLastDst = ui->firstLastDstEdit->text();
    phoneNumber = ui->phoneNumberEdit->text();
    documentType = ui->documentTypeEdit->text();
    productSum = ui->productSumEdit->text();
}
