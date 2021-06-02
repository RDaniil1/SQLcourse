#ifndef DELETEENTRYROUTESHEET_H
#define DELETEENTRYROUTESHEET_H

#include <QDialog>

namespace Ui {
class DeleteEntryRouteSheet;
}

class DeleteEntryRouteSheet : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteEntryRouteSheet(QWidget *parent = nullptr);
    ~DeleteEntryRouteSheet();

    void CopyValues(QString &idRouteSheet);

private:
    Ui::DeleteEntryRouteSheet *ui;
};

#endif // DELETEENTRYROUTESHEET_H
