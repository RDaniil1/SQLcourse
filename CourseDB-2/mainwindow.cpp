#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Главное окно");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    login = new Login(this);
    login->setWindowTitle("Вход под существующим пользователем");
    if(login->exec() == QDialog::Accepted)
    {
        login->CopyValues(_user, _pass);
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setDatabaseName("test");
        if(db.open(_user, _pass) == false)
        {
            _user.clear();
            _pass.clear();
            QMessageBox::critical(this, "Ошибка", "Введите существующий логин и/или пароль");
        }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false && tableState >= 0 && tableState <= 4
            && _user != "_user")
    {
        switch (tableState)
        {
        case driverTableChoosed:
            DeleteDriverEntry();
            break;
        case vehicleTableChoosed:
            DeleteVehicleEntry();
            break;
        case routeSheetTableChoosed:
            DeleteRouteSheetEntry();
            break;
        case destinationTableChoosed:
            DeleteDestinationEntry();
            break;
        }
    }
    else if(_user.isEmpty() == true && _pass.isEmpty() == true)
        QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
    else if(tableState < 0 || tableState > 4)
        QMessageBox::critical(this, "Ошибка", "Выберите таблицу");
    else if(_user == "_user")
        QMessageBox::critical(this, "Ошибка", "У пользователя _user нет прав на этот запрос");
}

void MainWindow::on_addButton_clicked()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false && tableState >= 0 && tableState <= 4)
    {
        switch (tableState)
        {
        case driverTableChoosed:
            AddDriverEntry();
            break;
        case vehicleTableChoosed:
            AddVehicleEntry();
            break;
        case routeSheetTableChoosed:
            AddRouteSheetEntry();
            break;
        case destinationTableChoosed:
            AddDestinationEntry();
            break;
        }
    }
    else if(_user.isEmpty() == true && _pass.isEmpty() == true)
        QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
    else if(tableState < 0 || tableState > 4)
        QMessageBox::critical(this, "Ошибка", "Выберите таблицу");
}

void MainWindow::on_editButton_clicked()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false && tableState >= 0 && tableState <= 4
            && _user != "_user")
    {
        switch (tableState)
        {
        case driverTableChoosed:
            EditDriverEntry();
            break;
        case vehicleTableChoosed:
            EditVehicleEntry();
            break;
        case routeSheetTableChoosed:
            EditRouteSheetEntry();
            break;
        case destinationTableChoosed:
            EditDestinationEntry();
            break;
        }
    }
    else if(_user.isEmpty() == true && _pass.isEmpty() == true)
        QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
    else if(tableState < 0 || tableState > 4)
        QMessageBox::critical(this, "Ошибка", "Выберите таблицу");
    else if(_user == "_user")
        QMessageBox::critical(this, "Ошибка", "У пользователя _user нет прав на этот запрос");
}

void MainWindow::on_driverAction_triggered()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false)
    {
        tableState = driverTableChoosed;
        ui->label->setText("Номер водителя:");
        PrintDriverTable();
    }
    else QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
}

void MainWindow::on_vehicleAction_triggered()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false)
    {
        tableState = vehicleTableChoosed;
        ui->label->setText("Номер машины:");
        PrintVehicleTable();
    }
    else QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
}

void MainWindow::on_route_sheetAction_triggered()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false)
    {
        tableState = routeSheetTableChoosed;
        ui->label->setText("Номер маршрутного листа:");
        PrintRouteSheetTable();
    }
    else QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
}

void MainWindow::on_destinationAction_triggered()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false)
    {
        tableState = destinationTableChoosed;
        ui->label->setText("Номер получателя:");
        PrintDestinationTable();
    }
    else QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
}

void MainWindow::PrintDriverTable()
{
    QSqlQuery query;
       if (query.exec("select * from driver order by id_driver;"))
       {
           qStandardItemModel = new QStandardItemModel();
           qStandardItemModel->setHorizontalHeaderLabels(QStringList()<< "Имя, фамилия" << "Номер паспорта" << "Номер документа водителя" << "Категория" << "Сумма информации");

           QSqlRecord rec = query.record();
           QString idDriver, firstlast, passport_num, driver_document, category, summing_data;
           ui->listWidget->clear();
           while (query.next())
           {
               idDriver = query.value(rec.indexOf("id_driver")).toString();
               firstlast = query.value(rec.indexOf("firstlast")).toString();
               passport_num = query.value(rec.indexOf("passport_num")).toString();
               driver_document = query.value(rec.indexOf("driver_document")).toString();
               category = query.value(rec.indexOf("category")).toString();
               summing_data = query.value(rec.indexOf("summing_data")).toString();

               QStandardItem* itemCol1(new QStandardItem(firstlast));
               QStandardItem* itemCol2(new QStandardItem(passport_num));
               QStandardItem* itemCol3(new QStandardItem(driver_document));
               QStandardItem* itemCol4(new QStandardItem(category));
               QStandardItem* itemCol5(new QStandardItem(summing_data));

               qStandardItemModel->appendRow(QList<QStandardItem*>()<< itemCol1 << itemCol2
                                             << itemCol3 << itemCol4 << itemCol5);

               ui->listWidget->addItem(idDriver);
           }
           ui->tableView->setModel(qStandardItemModel);

       }
}

void MainWindow::PrintVehicleTable()
{
    QSqlQuery query;
       if (query.exec("select * from vehicle order by id_vehicle;"))
       {
           qStandardItemModel = new QStandardItemModel();
           qStandardItemModel->setHorizontalHeaderLabels(QStringList()<< "Количесто машин" << "Время выпуска" << "Гос. номер" << "ВИН-номер");

           QSqlRecord rec = query.record();
           QString idVehicle, vehicle_amount, release_time, state_num, vin;

           ui->listWidget->clear();
           while (query.next())
           {
               idVehicle = query.value(rec.indexOf("id_vehicle")).toString();
               vehicle_amount = query.value(rec.indexOf("vehicle_amount")).toString();
               release_time = query.value(rec.indexOf("release_time")).toString();
               state_num = query.value(rec.indexOf("state_num")).toString();
               vin = query.value(rec.indexOf("vin")).toString();

               QStandardItem* itemCol1(new QStandardItem(vehicle_amount));
               QStandardItem* itemCol2(new QStandardItem(release_time));
               QStandardItem* itemCol3(new QStandardItem(state_num));
               QStandardItem* itemCol4(new QStandardItem(vin));

               qStandardItemModel->appendRow(QList<QStandardItem*>()<<itemCol1<<itemCol2<<itemCol3 << itemCol4);
               ui->listWidget->addItem(idVehicle);
           }
           ui->tableView->setModel(qStandardItemModel);
       }
}

void MainWindow::PrintRouteSheetTable()
{
    QSqlQuery query;
       if (query.exec("select * from route_sheet order by id_routesheet;"))
       {
           qStandardItemModel = new QStandardItemModel();
           qStandardItemModel->setHorizontalHeaderLabels(QStringList()<< "Организация" << "Причина" << "Время");

           QSqlRecord rec = query.record();
           QString idRouteSheet, organisation, reason, timeStamp;

           ui->listWidget->clear();
           while (query.next())
           {
               idRouteSheet = query.value(rec.indexOf("id_routesheet")).toString();
               organisation = query.value(rec.indexOf("organisation")).toString();
               reason = query.value(rec.indexOf("reason")).toString();
               timeStamp = query.value(rec.indexOf("time_stamp")).toString();

               QStandardItem* itemCol1(new QStandardItem(organisation));
               QStandardItem* itemCol2(new QStandardItem(reason));
               QStandardItem* itemCol3(new QStandardItem(timeStamp));

               qStandardItemModel->appendRow(QList<QStandardItem*>()<<itemCol1<<itemCol2<<itemCol3);

               ui->listWidget->addItem(idRouteSheet);
           }
           ui->tableView->setModel(qStandardItemModel);
       }
}

void MainWindow::PrintDestinationTable()
{
    QSqlQuery query;
       if (query.exec("select * from destination order by id_destination;"))
       {
           qStandardItemModel = new QStandardItemModel();
           qStandardItemModel->setHorizontalHeaderLabels(QStringList()<< "Имя, фамилия получателя" << "Номер телефона" << "Тип документа" << "Сумма товара");

           QSqlRecord rec = query.record();
           QString idDestination, firstlast_dst, phone_number, document_type, product_sum;

           ui->listWidget->clear();
           while (query.next())
           {
               idDestination = query.value(rec.indexOf("id_destination")).toString();
               firstlast_dst = query.value(rec.indexOf("firstlast_dst")).toString();
               phone_number = query.value(rec.indexOf("phone_number")).toString();
               document_type = query.value(rec.indexOf("document_type")).toString();
               product_sum = query.value(rec.indexOf("product_sum")).toString();

               QStandardItem* itemCol1(new QStandardItem(firstlast_dst));
               QStandardItem* itemCol2(new QStandardItem(phone_number));
               QStandardItem* itemCol3(new QStandardItem(document_type));
               QStandardItem* itemCol4(new QStandardItem(product_sum));

               qStandardItemModel->appendRow(QList<QStandardItem*>()<<itemCol1<<itemCol2<<itemCol3 << itemCol4);

               ui->listWidget->addItem(idDestination);
           }
           ui->tableView->setModel(qStandardItemModel);
       }
}

void MainWindow::AddDriverEntry()
{
    addEntryDriver = new AddEntryDriver(this);
    addEntryDriver->setWindowTitle("Добавить запись в таблицу Водители");
    if(addEntryDriver->exec() == QDialog::Accepted)
    {
        QString firstLast, passportNum, driverDocument, category;
        addEntryDriver->CopyValues(firstLast, passportNum, driverDocument, category);
        QSqlQuery query;

        QString str_insert = "select max(id_driver) + 1 as next_driv_id from driver;";
        query.exec(str_insert);
        QSqlRecord rec = query.record();
        query.next();
        QString nextDrivId = query.value(rec.indexOf("next_driv_id")).toString();

        str_insert = "CALL insert_driver('%1', '%2', '%3', '%4', '%5');";
        QString row = str_insert.arg(nextDrivId, firstLast, passportNum, driverDocument, category);
        query.exec(row);
        PrintDriverTable();
    }
}

void MainWindow::AddVehicleEntry()
{
    addEntryVehicle = new AddEntryVehicle(this);
    addEntryVehicle->setWindowTitle("Добавить запись в таблицу Машины");
    if(addEntryVehicle->exec() == QDialog::Accepted)
    {
        QString idDriver,vehicleAmount, releaseTime, stateNum, vin;
        addEntryVehicle->CopyValues(vehicleAmount, releaseTime, stateNum, vin);
        QSqlQuery query;

        QString str_insert = "select max(id_vehicle) + 1 as next_vehi_id from vehicle;";
        query.exec(str_insert);
        QSqlRecord rec = query.record();
        query.next();
        QString nextVehiId = query.value(rec.indexOf("next_vehi_id")).toString();

        str_insert = "select max(id_driver) as next_driv_id from vehicle;";
        query.exec(str_insert);
        rec = query.record();
        query.next();
        QString nextDrivId = query.value(rec.indexOf("next_driv_id")).toString();

        str_insert = "CALL insert_vehicle('%1', '%2', '%3', '%4', '%5', '%6');";
        QString row = str_insert.arg(nextVehiId, nextDrivId,vehicleAmount, releaseTime, stateNum, vin);
        query.exec(row);
        PrintVehicleTable();

    }
}

void MainWindow::AddRouteSheetEntry()
{
    addEntryRouteSheet = new AddEntryRouteSheet(this);
    addEntryRouteSheet->setWindowTitle("Добавить запись в таблицу Маршрутный лист");
    if(addEntryRouteSheet->exec() == QDialog::Accepted)
    {
        QString  organisation, reason, timeStamp;
        addEntryRouteSheet->CopyValues(organisation, reason, timeStamp);
        QSqlQuery query;

        QString str_insert = "select max(id_routesheet) + 1 as next_rosh_id from route_sheet;";
        query.exec(str_insert);
        QSqlRecord rec = query.record();
        query.next();
        QString nextRoShId = query.value(rec.indexOf("next_rosh_id")).toString();

        str_insert = "select max(id_vehicle) as next_vehi_id from route_sheet;";
        query.exec(str_insert);
        rec = query.record();
        query.next();
        QString nextVehiId = query.value(rec.indexOf("next_vehi_id")).toString();

        str_insert = "select max(id_destination) as next_dst_id from route_sheet;";
        query.exec(str_insert);
        rec = query.record();
        query.next();
        QString nextDstId = query.value(rec.indexOf("next_dst_id")).toString();

        str_insert = "CALL insert_routesheet('%1', '%2', '%3', '%4', '%5', '%6');";
        QString row = str_insert.arg(nextRoShId, nextVehiId, nextDstId, organisation, reason, timeStamp);
        query.exec(row);
        PrintRouteSheetTable();
    }
}

void MainWindow::AddDestinationEntry()
{
    addEntryDestiantion = new AddEntryDestination(this);
    addEntryDestiantion->setWindowTitle("Добавить запись в таблицу Получатель");
    if(addEntryDestiantion->exec() == QDialog::Accepted)
    {
        QString firstLastDst, phoneNumber, documentType, productSum;
        addEntryDestiantion->CopyValues(firstLastDst, phoneNumber, documentType, productSum);
        QSqlQuery query;

        QString str_insert = "select max(id_destination) + 1 as next_dst_id from destination;";
        query.exec(str_insert);
        QSqlRecord rec = query.record();
        query.next();
        QString nextDstId = query.value(rec.indexOf("next_dst_id")).toString();

        str_insert = "select max(id_dealagreement) + 1 as next_deal_id from destination;";
        query.exec(str_insert);
        rec = query.record();
        query.next();
        QString nextDealId = query.value(rec.indexOf("next_deal_id")).toString();

        str_insert = "CALL insert_destination('%1', '%2', '%3', '%4', '%5', '%6');";
        QString row = str_insert.arg(nextDstId, firstLastDst, phoneNumber,
                                     nextDealId, documentType, productSum);
        query.exec(row);
        PrintDestinationTable();
    }
}

void MainWindow::DeleteDriverEntry()
{
    QSqlQuery query;

    int selectedIndex = ui->listWidget->currentItem()->text().toInt();

    QString str_insert = "CALL del_driver('%1');";
    QString row = str_insert.arg(QString::number(selectedIndex));
    query.exec(row);
    PrintDriverTable();
}

void MainWindow::DeleteVehicleEntry()
{
    QSqlQuery query;

    int selectedIndex = ui->listWidget->currentItem()->text().toInt();

    QString str_insert = "CALL del_vehicle('%1');";
    QString row = str_insert.arg(QString::number(selectedIndex));
    query.exec(row);
    PrintVehicleTable();
}

void MainWindow::DeleteRouteSheetEntry()
{
    QSqlQuery query;

    int selectedIndex = ui->listWidget->currentItem()->text().toInt();

    QString str_insert = "CALL del_routesheet('%1');";
    QString row = str_insert.arg(QString::number(selectedIndex));
    query.exec(row);
    PrintRouteSheetTable();
}

void MainWindow::DeleteDestinationEntry()
{
    QSqlQuery query;

    int selectedIndex = ui->listWidget->currentItem()->text().toInt();

    QString str_insert = "CALL del_destination('%1');";
    QString row = str_insert.arg(QString::number(selectedIndex));
    query.exec(row);
    PrintDestinationTable();
}

void MainWindow::EditDriverEntry()
{
    editEntryDriver = new EditEntryDriver (this);
    editEntryDriver->setWindowTitle("Изменить запись в таблице Водитель");
    if(editEntryDriver->exec() == QDialog::Accepted)
    {
        QString firstLast, passportNum, driverDocument, category;
        editEntryDriver->CopyValues(firstLast, passportNum, driverDocument, category);
        QSqlQuery query;

        int selectedIndex = ui->listWidget->currentItem()->text().toInt();

        QString str_insert = "CALL update_driver('%1', '%2', '%3', '%4', '%5');";
        QString row = str_insert.arg(QString::number(selectedIndex), firstLast,
                                     passportNum, driverDocument, category);
        query.exec(row);
        PrintDriverTable();
    }
}

void MainWindow::EditVehicleEntry()
{
    editEntryVehicle = new EditEntryVehicle(this);
    editEntryVehicle->setWindowTitle("Изменить запись в таблице Машины");
    if(editEntryVehicle->exec() == QDialog::Accepted)
    {
        QString vehicleAmount, releaseTime, stateNum, vin;
        editEntryVehicle->CopyValues(vehicleAmount, releaseTime, stateNum, vin);
        QSqlQuery query;

        int selectedIndex = ui->listWidget->currentItem()->text().toInt();

        QString str_insert = "CALL update_vehicle('%1', '%2', '%3', '%4', '%5');";
        QString row = str_insert.arg(QString::number(selectedIndex), vehicleAmount, releaseTime, stateNum, vin);
        query.exec(row);
        PrintVehicleTable();
    }
}

void MainWindow::EditRouteSheetEntry()
{
    editEntryRouteSheet = new EditEntryRouteSheet(this);
    editEntryRouteSheet->setWindowTitle("Изменить запись в таблице Маршрутный лист");
    if(editEntryRouteSheet->exec() == QDialog::Accepted)
    {
        QString organisation, reason, timeStamp;
        editEntryRouteSheet->CopyValues(organisation, reason, timeStamp);
        QSqlQuery query;

        int selectedIndex = ui->listWidget->currentItem()->text().toInt();

        QString str_insert = "CALL update_routesheet('%1', '%2', '%3', '%4');";
        QString row = str_insert.arg(QString::number(selectedIndex), organisation, reason, timeStamp);
        query.exec(row);
        PrintRouteSheetTable();
    }
}

void MainWindow::EditDestinationEntry()
{
    editEntryDestination = new EditEntryDestination(this);
    editEntryDestination->setWindowTitle("Изменить запись в таблице Получатель");
    if(editEntryDestination->exec() == QDialog::Accepted)
    {
        QString firstLastDst, phoneNumber, documentType, productSum;
        editEntryDestination->CopyValues(firstLastDst, phoneNumber, documentType, productSum);
        QSqlQuery query;

        int selectedIndex = ui->listWidget->currentItem()->text().toInt();

        QString str_insert = "CALL update_destination('%1', '%2', '%3', '%4', '%5', '%6');";
        QString row = str_insert.arg(QString::number(selectedIndex), firstLastDst, phoneNumber,
                                     QString::number(selectedIndex), documentType, productSum);
        query.exec(row);
        PrintDestinationTable();
    }
}

void MainWindow::PrintEntry1Table(QSqlQuery query, QString str)
{
    if (query.exec(str))
       {
           qStandardItemModel = new QStandardItemModel();
           qStandardItemModel->setHorizontalHeaderLabels(QStringList()<< "Количесто машин" << "Результат сравнения" << "Категория");

           QSqlRecord rec = query.record();
           QString vehicle_amount, comparsion_result, category;

           while (query.next())
           {
               vehicle_amount = query.value(rec.indexOf("vehicle_amount")).toString();
               comparsion_result = query.value(rec.indexOf("comparsion_result")).toString();
               category = query.value(rec.indexOf("category")).toString();

               QStandardItem* itemCol1(new QStandardItem(vehicle_amount));
               QStandardItem* itemCol2(new QStandardItem(comparsion_result));
               QStandardItem* itemCol3(new QStandardItem(category));

               qStandardItemModel->appendRow(QList<QStandardItem*>()<<itemCol1<<itemCol2<<itemCol3);
           }
           ui->tableView->setModel(qStandardItemModel);
    }
}

void MainWindow::PrintEntry2Table(QSqlQuery query, QString str)
{
    if (query.exec(str))
       {
           qStandardItemModel = new QStandardItemModel();
           qStandardItemModel->setHorizontalHeaderLabels(QStringList()<< "Организация" << "Гос. номер");

           QSqlRecord rec = query.record();
           QString organisation, state_num;

           while (query.next())
           {
               organisation = query.value(rec.indexOf("organisation")).toString();
               state_num = query.value(rec.indexOf("state_num")).toString();

               QStandardItem* itemCol1(new QStandardItem(organisation));
               QStandardItem* itemCol2(new QStandardItem(state_num));

               qStandardItemModel->appendRow(QList<QStandardItem*>()<<itemCol1<<itemCol2);
           }
           ui->tableView->setModel(qStandardItemModel);
    }
}

void MainWindow::PrintEntry3Table(QSqlQuery query, QString str)
{
    if (query.exec(str))
       {
           qStandardItemModel = new QStandardItemModel();
           qStandardItemModel->setHorizontalHeaderLabels(QStringList()<< "Среднее кол-во продуктов" << "Сумма водителей");

           QSqlRecord rec = query.record();
           QString average_prod, driver_count;

           while (query.next())
           {
               average_prod = query.value(rec.indexOf("average_prod")).toString();
               driver_count = query.value(rec.indexOf("driver_count")).toString();

               QStandardItem* itemCol1(new QStandardItem(average_prod));
               QStandardItem* itemCol2(new QStandardItem(driver_count));

               qStandardItemModel->appendRow(QList<QStandardItem*>()<<itemCol1<<itemCol2);
           }
           ui->tableView->setModel(qStandardItemModel);
    }
}

void MainWindow::PrintEntry4Table(QSqlQuery query, QString str)
{
    if (query.exec(str))
       {
           qStandardItemModel = new QStandardItemModel();
           qStandardItemModel->setHorizontalHeaderLabels(QStringList()<< "Сумма машин" << "Организация" << "Документ водителя");

           QSqlRecord rec = query.record();
           QString vehicle_sum, organisation, driver_document;

           while (query.next())
           {
               vehicle_sum = query.value(rec.indexOf("vehicle_sum")).toString();
               organisation = query.value(rec.indexOf("organisation")).toString();
               driver_document = query.value(rec.indexOf("driver_document")).toString();

               QStandardItem* itemCol1(new QStandardItem(vehicle_sum));
               QStandardItem* itemCol2(new QStandardItem(organisation));
               QStandardItem* itemCol3(new QStandardItem(driver_document));

               qStandardItemModel->appendRow(QList<QStandardItem*>()<<itemCol1<<itemCol2 << itemCol3);
           }
           ui->tableView->setModel(qStandardItemModel);
    }
}

void MainWindow::PrintEntry5Table(QSqlQuery query, QString str)
{
    if (query.exec(str))
       {
           qStandardItemModel = new QStandardItemModel();
           qStandardItemModel->setHorizontalHeaderLabels(QStringList()<< "Организация" << "Имя, фамилия получателя");

           QSqlRecord rec = query.record();
           QString organisation, firstlast_dst;

           while (query.next())
           {
               organisation = query.value(rec.indexOf("organisation")).toString();
               firstlast_dst = query.value(rec.indexOf("firstlast_dst")).toString();

               QStandardItem* itemCol1(new QStandardItem(organisation));
               QStandardItem* itemCol2(new QStandardItem(firstlast_dst));

               qStandardItemModel->appendRow(QList<QStandardItem*>()<<itemCol1<<itemCol2);
           }
           ui->tableView->setModel(qStandardItemModel);
    }
}

void MainWindow::on_entryAction1_triggered()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false && tableState >= 0 && tableState <= 4
            && tableState == vehicleTableChoosed)
    {
        entry1Dialog = new Entry1Dialog(this);
        entry1Dialog->setWindowTitle("Ввод данных для пользовательского запроса 1");
        if(entry1Dialog->exec() == QDialog::Accepted)
        {
            QString comparsionValue;
            entry1Dialog->CopyValues(comparsionValue);
            QSqlQuery query;
            QString str_insert = "select v.id_vehicle, v.vehicle_amount, case "
"when vehicle_amount >= '%1' then 'ok' when vehicle_amount <= '%1' "
"then 'not ok' end as comparsion_result, d.id_driver, d.category FROM driver d INNER JOIN vehicle v on v.id_driver=d.id_driver;";
            QString row = str_insert.arg(comparsionValue);
            PrintEntry1Table(query, row);
        }

    }
    else if(_user.isEmpty() == true && _pass.isEmpty() == true)
        QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
    else if(tableState < 0 || tableState > 4)
        QMessageBox::critical(this, "Ошибка", "Выберите таблицу");
}

void MainWindow::on_entryAction2_triggered()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false && tableState >= 0 && tableState <= 4)
    {
        entry2Dialog = new Entry2Dialog(this);
        entry2Dialog->setWindowTitle("Ввод данных для пользовательского запроса 2");
        if(entry2Dialog->exec() == QDialog::Accepted)
        {
            QString criteriaValue;
            entry2Dialog->CopyValues(criteriaValue);
            QSqlQuery query;
            QString str_insert = "select * from driver_dstFI_view order by %1;";
            QString row = str_insert.arg(criteriaValue);
            query.exec(row);
            PrintEntry2Table(query, row);
        }
    }
    else if(_user.isEmpty() == true && _pass.isEmpty() == true)
        QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
    else if(tableState < 0 || tableState > 4)
        QMessageBox::critical(this, "Ошибка", "Выберите таблицу");
}

void MainWindow::on_entryAction3_triggered()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false && tableState >= 0 && tableState <= 4)
    {
        QSqlQuery query;
        QString str_insert = "select (select avg(dst.product_sum) from destination dst) as average_prod, (select count(dr.id_driver) from driver dr) as driver_count from (select v.id_driver, v.vehicle_amount from vehicle v) as vi_amount inner join driver dr on dr.id_driver=vi_amount.id_driver where (select avg(amount.vehicle_amount) from (select v.vehicle_amount from vehicle v where dr.id_driver=v.id_driver) as amount) > 220;";
        query.exec(str_insert);
        PrintEntry3Table(query, str_insert);
    }
    else if(_user.isEmpty() == true && _pass.isEmpty() == true)
        QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
    else if(tableState < 0 || tableState > 4)
        QMessageBox::critical(this, "Ошибка", "Выберите таблицу");
}

void MainWindow::on_entryAction4_triggered()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false && tableState >= 0 && tableState <= 4)
    {
        QSqlQuery query;
        QString str_insert = "select v.id_vehicle, sum(v.vehicle_amount) as vehicle_sum, ro.id_routesheet, ro.organisation, dr.id_driver, dr.driver_document from route_sheet ro inner join vehicle v on ro.id_vehicle=v.id_vehicle inner join driver dr on v.id_driver=dr.id_driver group by dr.driver_document, ro.organisation, v.id_vehicle,  ro.id_routesheet, dr.id_driver having sum(dr.driver_document)>20000;";
        query.exec(str_insert);
        PrintEntry4Table(query, str_insert);
    }
    else if(_user.isEmpty() == true && _pass.isEmpty() == true)
        QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
    else if(tableState < 0 || tableState > 4)
        QMessageBox::critical(this, "Ошибка", "Выберите таблицу");
}

void MainWindow::on_entryAction5_triggered()
{
    if(_user.isEmpty() == false && _pass.isEmpty() == false && tableState >= 0 && tableState <= 4)
    {
        QSqlQuery query;
        QString str_insert = "select ro.organisation, d.firstLast_dst from route_sheet ro inner join destination d on ro.id_destination=d.id_destination where  d.product_sum > all(select dr.driver_document from driver dr where dr.driver_document < 10);";
        query.exec(str_insert);
        PrintEntry5Table(query, str_insert);
    }
    else if(_user.isEmpty() == true && _pass.isEmpty() == true)
        QMessageBox::critical(this, "Ошибка", "Вы должны зайти под своим пользователем");
    else if(tableState < 0 || tableState > 4)
        QMessageBox::critical(this, "Ошибка", "Выберите таблицу");
}

