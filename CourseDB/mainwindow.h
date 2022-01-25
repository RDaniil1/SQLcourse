#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QSqlQuery>
#include <QtSql>
#include <QItemSelectionModel>
#include <QModelIndex>

#include "login.h"

#include "addentrydriver.h"
#include "addentryvehicle.h"
#include "addentryroutesheet.h"
#include "addentrydestination.h"

#include "editentrydriver.h"
#include "editentrydestination.h"
#include "editentryvehicle.h"
#include "editentryroutesheet.h"

#include "entry1dialog.h"
#include "entry2dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum TableState
{
    driverTableChoosed,
    vehicleTableChoosed,
    routeSheetTableChoosed,
    destinationTableChoosed
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_driverAction_triggered();

    void on_vehicleAction_triggered();

    void on_route_sheetAction_triggered();

    void on_destinationAction_triggered();

    void on_entryAction1_triggered();

    void on_entryAction2_triggered();

    void on_entryAction3_triggered();

    void on_entryAction4_triggered();

    void on_entryAction5_triggered();

private:
    QSqlDatabase db;
    QString _user;
    QString _pass;

    Login *login;
    AddEntryDriver *addEntryDriver;
    AddEntryVehicle *addEntryVehicle;
    AddEntryRouteSheet *addEntryRouteSheet;
    AddEntryDestination *addEntryDestiantion;

    EditEntryDriver *editEntryDriver;
    EditEntryDestination *editEntryDestination;
    EditEntryVehicle *editEntryVehicle;
    EditEntryRouteSheet *editEntryRouteSheet;

    Entry1Dialog *entry1Dialog;
    Entry2Dialog *entry2Dialog;

    TableState tableState;
    QStandardItemModel* qStandardItemModel;
    QItemSelectionModel *select;
    Ui::MainWindow *ui;

    void PrintDriverTable();
    void PrintVehicleTable();
    void PrintRouteSheetTable();
    void PrintDestinationTable();

    void AddDriverEntry();
    void AddVehicleEntry();
    void AddRouteSheetEntry();
    void AddDestinationEntry();

    void DeleteDriverEntry();
    void DeleteVehicleEntry();
    void DeleteRouteSheetEntry();
    void DeleteDestinationEntry();

    void EditDriverEntry();
    void EditVehicleEntry();
    void EditRouteSheetEntry();
    void EditDestinationEntry();

    void PrintEntry1Table(QSqlQuery query, QString str);
    void PrintEntry2Table(QSqlQuery query, QString str);
    void PrintEntry3Table(QSqlQuery query, QString str);
    void PrintEntry4Table(QSqlQuery query, QString str);
    void PrintEntry5Table(QSqlQuery query, QString str);
};
#endif // MAINWINDOW_H
