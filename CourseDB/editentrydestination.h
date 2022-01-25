#ifndef EDITENTRYDESTINATION_H
#define EDITENTRYDESTINATION_H

#include <QDialog>

namespace Ui {
class EditEntryDestination;
}

class EditEntryDestination : public QDialog
{
    Q_OBJECT

public:
    explicit EditEntryDestination(QWidget *parent = nullptr);
    ~EditEntryDestination();

    void CopyValues(QString &firstLastDst,
                    QString &phoneNumber, QString &documentType, QString &productSum);

private:
    Ui::EditEntryDestination *ui;
};

#endif // EDITENTRYDESTINATION_H
