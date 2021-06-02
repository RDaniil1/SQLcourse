#include "entry1dialog.h"
#include "ui_entry1dialog.h"

Entry1Dialog::Entry1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entry1Dialog)
{
    ui->setupUi(this);
}

Entry1Dialog::~Entry1Dialog()
{
    delete ui;
}

void Entry1Dialog::CopyValues(QString &comparsionValue)
{
    comparsionValue = ui->comparsionEdit->text();
}
