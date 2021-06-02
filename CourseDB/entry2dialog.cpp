#include "entry2dialog.h"
#include "ui_entry2dialog.h"

Entry2Dialog::Entry2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entry2Dialog)
{
    ui->setupUi(this);
}

Entry2Dialog::~Entry2Dialog()
{
    delete ui;
}

void Entry2Dialog::CopyValues(QString &criteriaValue)
{
    if(ui->criteriaBox->currentText() == "Номер маршрутного листа")
    {
        criteriaValue = "id_routesheet";
    }
    else if(ui->criteriaBox->currentText() == "Организация")
    {
        criteriaValue = "organisation";
    }
    else if(ui->criteriaBox->currentText() == "Номер машины")
    {
        criteriaValue = "id_vehicle";
    }
    else if(ui->criteriaBox->currentText() == "Гос. номер")
    {
        criteriaValue = "state_num";
    }
}
