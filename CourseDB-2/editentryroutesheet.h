#ifndef EDITENTRYROUTESHEET_H
#define EDITENTRYROUTESHEET_H

#include <QDialog>

namespace Ui {
class EditEntryRouteSheet;
}

class EditEntryRouteSheet : public QDialog
{
    Q_OBJECT

public:
    explicit EditEntryRouteSheet(QWidget *parent = nullptr);
    ~EditEntryRouteSheet();

    void CopyValues(QString &organisation, QString &reason, QString &timeStamp);

private:
    Ui::EditEntryRouteSheet *ui;
};

#endif // EDITENTRYROUTESHEET_H
