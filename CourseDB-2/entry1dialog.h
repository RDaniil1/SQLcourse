#ifndef ENTRY1DIALOG_H
#define ENTRY1DIALOG_H

#include <QDialog>

namespace Ui {
class Entry1Dialog;
}

class Entry1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Entry1Dialog(QWidget *parent = nullptr);
    ~Entry1Dialog();

    void CopyValues(QString &comparsionValue);

private:
    Ui::Entry1Dialog *ui;
};

#endif // ENTRY1DIALOG_H
