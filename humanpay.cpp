#include "humanpay.h"
#include "ui_humanpay.h"

HumanPay::HumanPay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HumanPay)
{
    ui->setupUi(this);
    QLabel* Name = new QLabel(tr("Enter Name: "), this);
    Name->setGeometry(5,5,150,20);
    nameEd->setGeometry(5, 30, 250, 30);

    QLabel* Namel = new QLabel(tr("Enter second name: "), this);
    Namel->setGeometry(5,65,150,20);
    namelEd->setGeometry(5, 90, 250, 30);

    QLabel* Namep = new QLabel(tr("Enter patronymic: "), this);
    Namep->setGeometry(5,125,150,20);
    namepEd->setGeometry(5, 150, 250, 30);

    QLabel* number = new QLabel(tr("Enter number of item: "), this);
    number->setGeometry(5,185,150,20);
    numberEd->setGeometry(5, 210, 250, 30);

    QLabel* date = new QLabel(tr("Enter date of pay: "), this);
    date->setGeometry(5,245,150,20);
    dateEd->setGeometry(5, 270, 250, 30);

    QLabel* item = new QLabel(tr("Enter kind item: "), this);
    item->setGeometry(5,305,150,20);
    itemEd->setGeometry(5, 330, 250, 30);
}

void HumanPay::FillForms(QString name, QString namel, QString namep, QString date, int number, QString itemh)
{
    nameEd->setText(name);
    namelEd->setText(namel);
    namepEd->setText(namep);
    dateEd->setText(date);
    numberEd->setText(QString::number(number));
    itemEd->setText(itemh);
}

HumanPay::~HumanPay()
{
    delete ui;
}
