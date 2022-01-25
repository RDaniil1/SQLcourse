#ifndef ADDENTRYROUTESHEET_H
#define ADDENTRYROUTESHEET_H

#include <QDialog>

namespace Ui {
class AddEntryRouteSheet;
}

class AddEntryRouteSheet : public QDialog
{
    Q_OBJECT

public:
    explicit AddEntryRouteSheet(QWidget *parent = nullptr);
    ~AddEntryRouteSheet();

    void CopyValues(QString &organisation,
                    QString &reason, QString &timeStamp);


private:
    Ui::AddEntryRouteSheet *ui;
};

#endif // ADDENTRYROUTESHEET_H
