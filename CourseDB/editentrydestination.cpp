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

void EditEntryDestination::CopyValues(QString &idDestination, QString &firstLastDst, QString &phoneNumber,
                                      QString &idDealAgreement, QString &documentType, QString &productSum)
{
    idDestination = ui->idDestiantionEdit->text();
    firstLastDst = ui->firstLastDstEdit->text();
    phoneNumber = ui->phoneNumberEdit->text();
    idDealAgreement = ui->idDealAgreementEdit->text();
    documentType = ui->documentTypeEdit->text();
    productSum = ui->productSumEdit->text();
}
