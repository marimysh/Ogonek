#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paysponsor.h"
#include "pay.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ogonek");
    db.setPort(3050);
    db.setUserName("root");
    db.setPassword("nm.hbyu");
    bool ok = db.open();
    QStandardItem* item;

    QStringList horizontalHeader;
    horizontalHeader.append("id");
    horizontalHeader.append("Name");
    horizontalHeader.append("SName");
    horizontalHeader.append("LName");
    horizontalHeader.append("DateB");
    horizontalHeader.append("DateD");
    horizontalHeader.append("placeB");
    horizontalHeader.append("PlaceL");
    horizontalHeader.append("Sex");
    horizontalHeader.append("Work NITI");
    horizontalHeader.append("work Group");
    horizontalHeader.append("Phone");

    model->setHorizontalHeaderLabels(horizontalHeader);

    if (ok)
    {
        QSqlQuery query;
        query.exec("SELECT * from people");
        int i = 0;
        QString id, name, secondname, lastname, dateB, dateD,
            placeB, placeL, sex, workedNITI, workedGroup, phonenumb;
        while (query.next())
        {
            id = query.value(0).toString();
            name = query.value(1).toString();
            secondname = query.value(2).toString();
            lastname = query.value(3).toString();
            dateB = query.value(4).toString();
            dateD = query.value(5).toString();
            placeB = query.value(6).toString();
            placeL = query.value(7).toString();
            if (query.value(8).toInt() == 0)
                sex = "Female";
            else
                sex = "Male";
            if (query.value(9).toInt() == 0)
                workedNITI = "No";
            else
                workedNITI = "Yes";
            if (query.value(10).toInt() == 0)
                workedGroup = "No";
            else
                workedGroup = "Yes";
            phonenumb = query.value(11).toString();

            item = new QStandardItem(id);
            model->setItem(i,0, item);
            item = new QStandardItem(name);
            model->setItem(i,1, item);
            item = new QStandardItem(secondname);
            model->setItem(i,2, item);
            item = new QStandardItem(lastname);
            model->setItem(i,3, item);
            item = new QStandardItem(dateB);
            model->setItem(i,4, item);
            item = new QStandardItem(dateD);
            model->setItem(i,5, item);
            item = new QStandardItem(placeB);
            model->setItem(i,6, item);
            item = new QStandardItem(placeL);
            model->setItem(i,7, item);
            item = new QStandardItem(sex);
            model->setItem(i,8, item);
            item = new QStandardItem(workedNITI);
            model->setItem(i,9, item);
            item = new QStandardItem(workedGroup);
            model->setItem(i,10, item);
            item = new QStandardItem(phonenumb);
            model->setItem(i,11, item);
            ++i;
        }
        ui->tableData->setModel(model);
        ui->tableData->resizeRowsToContents();
        ui->tableData->resizeColumnsToContents();
    }
    else
    {
        item = new QStandardItem(QString("Error: "+db.lastError().text()));
        model->setItem(0,0, item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//insert
void MainWindow::on_actionHuman_triggered()
{
    EditData formOpt;
    formOpt.setModal(true);
    if (formOpt.exec() == QDialog::Accepted)
    {
        QString name, secondname, lastname, dateB, dateD,
            placeB, placeL, phonenumb;
        int sex, workedNITI, workedGroup;
        name = formOpt.nameEd->text();
        secondname = formOpt.snameEd->text();
        lastname = formOpt.lnameEd->text();
        dateB = formOpt.DtBEd->text();
        dateD = formOpt.dtdEd->text();
        placeB = formOpt.plbEd->text();
        placeL = formOpt.pllEd->text();
        sex = formOpt.sexCB->currentIndex();
        workedNITI = formOpt.workNITICB->currentIndex();
        workedGroup = formOpt.workGroupCB->currentIndex();
        phonenumb = formOpt.phnEd->text();
        People::insert(name, secondname, lastname, dateB, dateD,
                      placeB, placeL, sex, workedNITI, workedGroup, phonenumb);
    }
}

//insert
void MainWindow::on_actionSponsor_triggered()
{
    edirsponsor formOpt;
    formOpt.setModal(true);
    if (formOpt.exec() == QDialog::Accepted)
    {
        QString name, contact, mainhelp;
        name = formOpt.nameEd->text();
        contact = formOpt.contactEd->text();
        mainhelp = formOpt.mainhelpEd->text();
        Sponsors::insert(name, contact, mainhelp);
    }
}

//show
void MainWindow::on_actionAll_people_triggered()
{
    idTable = 0;
    model->clear();
    QStringList horizontalHeader;
    horizontalHeader.append("id");
    horizontalHeader.append("Name");
    horizontalHeader.append("SName");
    horizontalHeader.append("LName");
    horizontalHeader.append("DateB");
    horizontalHeader.append("DateD");
    horizontalHeader.append("placeB");
    horizontalHeader.append("PlaceL");
    horizontalHeader.append("Sex");
    horizontalHeader.append("Work NITI");
    horizontalHeader.append("work Group");
    horizontalHeader.append("Phone");

    model->setHorizontalHeaderLabels(horizontalHeader);
    QString id, name, secondname, lastname, dateB, dateD,
        placeB, placeL, sex, workedNITI, workedGroup, phonenumb;
    QSqlQuery query = People::selectall();
    QStandardItem* item;
    int i = 0;
    while (query.next())
    {
        id = query.value(0).toString();
        name = query.value(1).toString();
        secondname = query.value(2).toString();
        lastname = query.value(3).toString();
        dateB = query.value(4).toString();
        dateD = query.value(5).toString();
        placeB = query.value(6).toString();
        placeL = query.value(7).toString();
        if (query.value(8).toInt() == 0)
            sex = "Female";
        else
            sex = "Male";
        if (query.value(9).toInt() == 0)
            workedNITI = "No";
        else
            workedNITI = "Yes";
        if (query.value(10).toInt() == 0)
            workedGroup = "No";
        else
            workedGroup = "Yes";
        phonenumb = query.value(11).toString();

        item = new QStandardItem(id);
        model->setItem(i,0, item);
        item = new QStandardItem(name);
        model->setItem(i,1, item);
        item = new QStandardItem(secondname);
        model->setItem(i,2, item);
        item = new QStandardItem(lastname);
        model->setItem(i,3, item);
        item = new QStandardItem(dateB);
        model->setItem(i,4, item);
        item = new QStandardItem(dateD);
        model->setItem(i,5, item);
        item = new QStandardItem(placeB);
        model->setItem(i,6, item);
        item = new QStandardItem(placeL);
        model->setItem(i,7, item);
        item = new QStandardItem(sex);
        model->setItem(i,8, item);
        item = new QStandardItem(workedNITI);
        model->setItem(i,9, item);
        item = new QStandardItem(workedGroup);
        model->setItem(i,10, item);
        item = new QStandardItem(phonenumb);
        model->setItem(i,11, item);
        ++i;
    }
    return;
}

//show
void MainWindow::on_actionSponsors_triggered()
{
    idTable = 1;
    model->clear();
    QStringList horizontalHeader;
    horizontalHeader.append("id");
    horizontalHeader.append("Name");
    horizontalHeader.append("Contact");
    horizontalHeader.append("Main help");
    model->setHorizontalHeaderLabels(horizontalHeader);
    QString id, name, contact, mainhelp;
    QSqlQuery Items = Sponsors::selectall();
    int i = 0;
    QStandardItem* item;
    while (Items.next())
    {
        id = Items.value(0).toString();
        name = Items.value(1).toString();
        contact = Items.value(2).toString();
        mainhelp = Items.value(3).toString();

        item = new QStandardItem(id);
        model->setItem(i,0, item);
        item = new QStandardItem(name);
        model->setItem(i,1, item);
        item = new QStandardItem(contact);
        model->setItem(i,2, item);
        item = new QStandardItem(mainhelp);
        model->setItem(i,3, item);
        ++i;
    }
    return;
}

//update
void MainWindow::on_actionHuman_edit_triggered()
{
    EditData formOpt;
    formOpt.setModal(true);
    if (formOpt.exec() == QDialog::Accepted)
    {
        QString name, secondname, lastname, dateB, dateD,
            placeB, placeL, phonenumb;
        int sex, workedNITI, workedGroup;
        name = formOpt.nameEd->text();
        secondname = formOpt.snameEd->text();
        lastname = formOpt.lnameEd->text();
        dateB = formOpt.DtBEd->text();
        dateD = formOpt.dtdEd->text();
        placeB = formOpt.plbEd->text();
        placeL = formOpt.pllEd->text();
        sex = formOpt.sexCB->currentIndex();
        workedNITI = formOpt.workNITICB->currentIndex();
        workedGroup = formOpt.workGroupCB->currentIndex();
        phonenumb = formOpt.phnEd->text();
        std::cout << ui->tableData->currentIndex().row();
        People::update(ui->tableData->currentIndex().row(), name, secondname, lastname, dateB, dateD,
                      placeB, placeL, sex, workedNITI, workedGroup, phonenumb);
    }
}

//update
void MainWindow::on_actionSponsor_2_triggered()
{
    edirsponsor formOpt;
    formOpt.setModal(true);
    if (formOpt.exec() == QDialog::Accepted)
    {
        QString name, contact, mainhelp;
        int id;
        name = formOpt.nameEd->text();
        contact = formOpt.contactEd->text();
        mainhelp = formOpt.mainhelpEd->text();
        Sponsors::update(id, name, contact, mainhelp);
    }
}

//insertPaySponsor
void MainWindow::on_actionFrom_sponsor_triggered()
{
    PaySponsor formOpt;
    formOpt.setModal(true);
    if (formOpt.exec() == QDialog::Accepted)
    {
        QString date, item, name;
        int number;
        name = formOpt.nameEd->text();
        number = formOpt.numberEd->text().toInt();
        date = formOpt.dateEd->text();
        item = formOpt.itemEd->text();
        Pay::insertPaySponsor(name, number, date, item);
    }
}

//updatePaySponsor
void MainWindow::on_actionPays_sponsors_s_triggered()
{
    PaySponsor formOpt;
    formOpt.setModal(true);
    if (formOpt.exec() == QDialog::Accepted)
    {
        QString date, name, item;
        int id, number;
        name = formOpt.nameEd->text();
        number = formOpt.numberEd->text().toInt();
        date = formOpt.dateEd->text();
        item = formOpt.itemEd->text();
        Pay::updatePaySponsor(id, name, number, date, item);
    }
}

//edit
void MainWindow::on_tableData_doubleClicked(const QModelIndex &index)
{
    switch (idTable)
    {
    case 0:
    {
        EditData formOpt;
        formOpt.setModal(true);
        QString name, secondname, lastname, dateB, dateD,
            placeB, placeL, sex, workedNITI, workedGroup, phonenumb;
    name = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 1).data().toString();
    secondname =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 2).data().toString();
    lastname =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 3).data().toString();
    dateB =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 4).data().toString();
    dateD =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 5).data().toString();
    placeB =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 6).data().toString();
    placeL =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 7).data().toString();
    sex =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 8).data().toString();
    workedNITI =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 9).data().toString();
    workedGroup =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 10).data().toString();
    phonenumb =  ui->tableData->model()->index(ui->tableData->currentIndex().row(), 11).data().toString();
    formOpt.FillForms(name, secondname, lastname, dateB, dateD,
                        placeB, placeL, sex, workedNITI, workedGroup, phonenumb);
    //std::cout << ui->tableData->currentIndex().row();
    formOpt.setId(ui->tableData->currentIndex().row() + 1);
    if (formOpt.exec() == QDialog::Accepted)
        {
        QString name, secondname, lastname, dateB, dateD,
            placeB, placeL, phonenumb;
        int sex, workedNITI, workedGroup;
        name = formOpt.nameEd->text();
        secondname = formOpt.snameEd->text();
        lastname = formOpt.lnameEd->text();
        dateB = formOpt.DtBEd->text();
        dateD = formOpt.dtdEd->text();
        placeB = formOpt.plbEd->text();
        placeL = formOpt.pllEd->text();
        sex = formOpt.sexCB->currentIndex();
        workedNITI = formOpt.workNITICB->currentIndex();
        workedGroup = formOpt.workGroupCB->currentIndex();
        phonenumb = formOpt.phnEd->text();
        std::cout << ui->tableData->currentIndex().row();
        People::update(ui->tableData->currentIndex().row() + 1, name, secondname, lastname, dateB, dateD,
                      placeB, placeL, sex, workedNITI, workedGroup, phonenumb);
        }
    }
    break;
    case 1:
    {
        edirsponsor formOpt;
        formOpt.setModal(true);
        QString name, contact, mainhelp;
        name = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 1).data().toString();
        contact = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 2).data().toString();
        mainhelp = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 3).data().toString();
        formOpt.FillForms(name, contact, mainhelp);
        std::cout << ui->tableData->currentIndex().row();
        if (formOpt.exec() == QDialog::Accepted)
        {

            name = formOpt.nameEd->text();
            contact = formOpt.contactEd->text();
            mainhelp = formOpt.mainhelpEd->text();
            Sponsors::update(ui->tableData->currentIndex().row() + 1, name, contact, mainhelp);
        }
    }
    break;
    case 2:
    {
        PaySponsor formOpt;
        formOpt.setModal(true);
        QString name, date, itemh;
        int number;
        name = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 1).data().toString();
        date = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 2).data().toString();
        number = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 3).data().toInt();
        itemh = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 4).data().toString();
        formOpt.FillForms(name, date, number, itemh);
        std::cout << ui->tableData->currentIndex().row();
        if (formOpt.exec() == QDialog::Accepted)
        {

            name = formOpt.nameEd->text();
            date = formOpt.dateEd->text();
            number = formOpt.numberEd->text().toInt();
            itemh = formOpt.itemEd->text();
            Pay::updatePaySponsor(ui->tableData->currentIndex().row() + 1, name, number, date, itemh);
        }
    }
        break;
        case 3:
        {
            HumanPay formOpt;
            formOpt.setModal(true);
            QString name, namel, namep, date, itemh;
            int number;
            name = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 1).data().toString();
            namel = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 2).data().toString();
            namep = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 3).data().toString();
            date = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 4).data().toString();
            number = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 5).data().toInt();
            itemh = ui->tableData->model()->index(ui->tableData->currentIndex().row(), 6).data().toString();
            formOpt.FillForms(name, namel, namep, date, number, itemh);
            std::cout << ui->tableData->currentIndex().row();
            if (formOpt.exec() == QDialog::Accepted)
            {

                name = formOpt.nameEd->text();
                date = formOpt.dateEd->text();
                number = formOpt.numberEd->text().toInt();
                itemh = formOpt.itemEd->text();
                Pay::updatePayHuman(ui->tableData->currentIndex().row() + 1, name, namel, namep, number, date, itemh);
            }
        }

    }
}

void MainWindow::on_actionSponsor_s_pays_triggered()
{
    idTable = 2;
    model->clear();
    QStringList horizontalHeader;
    horizontalHeader.append("id");
    horizontalHeader.append("Name");
    horizontalHeader.append("Date");
    horizontalHeader.append("Number");
    horizontalHeader.append("Item");
    model->setHorizontalHeaderLabels(horizontalHeader);
    QString id, name, number, date, itemhelp;
    QSqlQuery Items = Pay::selectall();
    int i = 0;
    QStandardItem* item;
    while (Items.next())
    {
        id = Items.value(0).toString();
        name = Items.value(1).toString();
        number = Items.value(2).toString();
        date = Items.value(3).toString();
        itemhelp = Items.value(4).toString();

        item = new QStandardItem(id);
        model->setItem(i,0, item);
        item = new QStandardItem(name);
        model->setItem(i,1, item);
        item = new QStandardItem(number);
        model->setItem(i,2, item);
        item = new QStandardItem(date);
        model->setItem(i,3, item);
        item = new QStandardItem(itemhelp);
        model->setItem(i,4, item);
        ++i;
    }
    return;
}

void MainWindow::on_actionBank_triggered()
{
    idTable = -1;
    model->clear();
    QStringList horizontalHeader;
    horizontalHeader.append("Name item");
    horizontalHeader.append("Number");
        model->setHorizontalHeaderLabels(horizontalHeader);
        QString name, number;
        QSqlQuery Items = Pay::selectallBank();
        int i = 0;
        QStandardItem* item;
        while (Items.next())
        {
            name = Items.value(1).toString();
            number = Items.value(2).toString();
            item = new QStandardItem(name);
            model->setItem(i,0, item);
            item = new QStandardItem(number);
            model->setItem(i,1, item);
            ++i;
        }
        return;
}

void MainWindow::on_actionFor_human_triggered()
{
    HumanPay formOpt;
    formOpt.setModal(true);
    if (formOpt.exec() == QDialog::Accepted)
    {
        QString date, item, name, namel, namep;
        int number;
        name = formOpt.nameEd->text();
        namel = formOpt.namelEd->text();
        namep = formOpt.namepEd->text();
        number = formOpt.numberEd->text().toInt();
        date = formOpt.dateEd->text();
        item = formOpt.itemEd->text();
        Pay::insertPayHuman(name, namel, namep, number, date, item);
    }
}

void MainWindow::on_actionPays_for_human_triggered()
{
    idTable = 3;
        model->clear();
        QStringList horizontalHeader;
        horizontalHeader.append("id");
        horizontalHeader.append("Name");
        horizontalHeader.append("Name second");
        horizontalHeader.append("Patronimyc");
        horizontalHeader.append("Date");
        horizontalHeader.append("Number");
        horizontalHeader.append("Item");
        model->setHorizontalHeaderLabels(horizontalHeader);
        QString name, namel, namep, number, date, itemh, id;
        QSqlQuery Items = Pay::selectallPayHuman();
        int i = 0;
        QStandardItem* item;
        while (Items.next())
        {
            name = Items.value(0).toString();
            namel = Items.value(1).toString();
            namep = Items.value(2).toString();
            date = Items.value(3).toString();
            number = Items.value(4).toString();
            itemh = Items.value(5).toString();
            id = Items.value(6).toString();
            item = new QStandardItem(id);
            model->setItem(i,0, item);
            item = new QStandardItem(name);
            model->setItem(i,1, item);
            item = new QStandardItem(namel);
            model->setItem(i,2, item);
            item = new QStandardItem(namep);
            model->setItem(i,3, item);
            item = new QStandardItem(date);
            model->setItem(i,4, item);
            item = new QStandardItem(number);
            model->setItem(i,5, item);
            item = new QStandardItem(itemh);
            model->setItem(i, 6, item);
            ++i;
        }
        return;
}
