#ifndef ADDENTRYDESTINATION_H
#define ADDENTRYDESTINATION_H

#include <QDialog>

namespace Ui {
class AddEntryDestination;
}

class AddEntryDestination : public QDialog
{
    Q_OBJECT

public:
    explicit AddEntryDestination(QWidget *parent = nullptr);
    ~AddEntryDestination();

    void CopyValues(QString &firstLastDst,
                    QString &phoneNumber,
                    QString &documentType, QString &productSum);
private:
    Ui::AddEntryDestination *ui;
};

#endif // ADDENTRYDESTINATION_H
