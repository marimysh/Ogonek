#include "editdata.h"
#include "ui_editdata.h"
#include "QLabel"
#include "QFormLayout"
#include "people.h"
#include "QComboBox"

EditData::EditData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditData)
{
    ui->setupUi(this);
        QLabel* Name = new QLabel(tr("Enter Name: "), this);
        Name->setGeometry(5,5,150,20);
        nameEd->setGeometry(5, 30, 250, 30);

        QLabel* sName = new QLabel(tr("Enter second name: "), this);
        sName->setGeometry(5,65,150,20);
        snameEd->setGeometry(5, 90, 250, 30);

        QLabel* lName = new QLabel(tr("Enter Last Name: "), this);
        lName->setGeometry(5,125,150,20);
        lnameEd->setGeometry(5, 150, 250, 30);

        QLabel* DtB = new QLabel(tr("Enter date birth: "), this);
        DtB->setGeometry(5,185,150,20);
        DtBEd->setGeometry(5, 210, 250, 30);

        QLabel* dtd = new QLabel(tr("Enter date death: "), this);
        dtd->setGeometry(5,245,150,20);
        dtdEd->setGeometry(5, 270, 250, 30);

        QLabel* plb = new QLabel(tr("Enter place birth: "), this);
        plb->setGeometry(5,305,150,20);
        plbEd->setGeometry(5, 330, 250, 30);

        QLabel* pll = new QLabel(tr("Enter living: "), this);
        pll->setGeometry(5,365,150,20);
        pllEd->setGeometry(5, 390, 250, 30);

        QLabel* sex = new QLabel(tr("Enter sex: "), this);
        sex->setGeometry(5,425,150,20);
        //sexEd->setGeometry(5, 450, 250, 30);

        sexCB->setEnabled(true);
        sexCB->setGeometry(5, 450, 250, 30);
        sexCB->addItem("Female");
        sexCB->addItem("Male");

        QLabel* wrN = new QLabel(tr("Enter wr NITI: "), this);
        wrN->setGeometry(5,485,150,20);
        workNITICB->addItem("Yes");
        workNITICB->addItem("No");
        workNITICB->setGeometry(5, 510, 250, 30);

        QLabel* wrG = new QLabel(tr("Enter wr group: "), this);
        wrG->setGeometry(5,545,150,20);
        workGroupCB->addItem("Yes");
        workGroupCB->addItem("No");
        workGroupCB->setGeometry(5, 570, 250, 30);

        QLabel* phn = new QLabel(tr("Enter phone number: "), this);
        phn->setGeometry(5,605,150,20);
        phnEd->setGeometry(5, 630, 250, 30);
}

void EditData::setId(int idt)
{
    this->id = idt;
    return;
}


void EditData::FillForms(QString name, QString secondname, QString lastname, QString dateB, QString dateD,
                           QString placeB, QString placeL, QString sex, QString workedNITI, QString workedGroup, QString phonenumb)
{
    short int tempsex;
    nameEd->setText(name);
    snameEd->setText(secondname);
    lnameEd->setText(lastname);
    DtBEd->setText(dateB);
    dtdEd->setText(dateD);
    plbEd->setText(placeB);
    pllEd->setText(placeL);
    if (sex == "Female")
        sexCB->setCurrentIndex(0);
    else
        sexCB->setCurrentIndex(1);
    if (workedNITI == "Yes")
        workNITICB->setCurrentIndex(0);
    else
        workNITICB->setCurrentIndex(1);
    if (workedGroup == "Yes")
        workGroupCB->setCurrentIndex(0);
    else
        workGroupCB->setCurrentIndex(1);
    phnEd->setText(phonenumb);

    return;
}

EditData::~EditData()
{
    delete ui;
}
