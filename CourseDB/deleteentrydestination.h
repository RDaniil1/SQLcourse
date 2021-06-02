#ifndef DELETEENTRYDESTINATION_H
#define DELETEENTRYDESTINATION_H

#include <QDialog>

namespace Ui {
class DeleteEntryDestination;
}

class DeleteEntryDestination : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteEntryDestination(QWidget *parent = nullptr);
    ~DeleteEntryDestination();

    void CopyValues(QString &idDestination);

private:
    Ui::DeleteEntryDestination *ui;
};

#endif // DELETEENTRYDESTINATION_H
