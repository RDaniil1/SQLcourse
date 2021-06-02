#include "deleteentrydestination.h"
#include "ui_deleteentrydestination.h"

DeleteEntryDestination::DeleteEntryDestination(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteEntryDestination)
{
    ui->setupUi(this);
}

DeleteEntryDestination::~DeleteEntryDestination()
{
    delete ui;
}

void DeleteEntryDestination::CopyValues(QString &idDestination)
{
    idDestination = ui->idDestinationEdit->text();
}
