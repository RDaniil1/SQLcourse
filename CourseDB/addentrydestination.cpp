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

void AddEntryDestination::CopyValues(QString &idDestination, QString &firstLastDst, QString &phoneNumber,
                                     QString &idDealAgreement, QString &documentType, QString &productSum)
{
    idDestination = ui->idDestiantionEdit->text();
    firstLastDst = ui->firstLastDstEdit->text();
    phoneNumber = ui->phoneNumberEdit->text();
    idDealAgreement = ui->idDealAgreementEdit->text();
    documentType = ui->documentTypeEdit->text();
    productSum = ui->productSumEdit->text();
}
