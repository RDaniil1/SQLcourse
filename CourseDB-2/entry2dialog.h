#ifndef ENTRY2DIALOG_H
#define ENTRY2DIALOG_H

#include <QDialog>

namespace Ui {
class Entry2Dialog;
}

class Entry2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Entry2Dialog(QWidget *parent = nullptr);
    ~Entry2Dialog();

    void CopyValues(QString &criteriaValue);

private:
    Ui::Entry2Dialog *ui;
};

#endif // ENTRY2DIALOG_H
