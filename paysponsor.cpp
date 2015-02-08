#include "paysponsor.h"
#include "ui_paysponsor.h"

PaySponsor::PaySponsor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaySponsor)
{
    ui->setupUi(this);
    QLabel* Name = new QLabel(tr("Enter Name: "), this);
    Name->setGeometry(5,5,150,20);
    nameEd->setGeometry(5, 30, 250, 30);

    QLabel* number = new QLabel(tr("Enter number of item: "), this);
    number->setGeometry(5,65,150,20);
    numberEd->setGeometry(5, 90, 250, 30);

    QLabel* date = new QLabel(tr("Enter date of pay: "), this);
    date->setGeometry(5,125,150,20);
    dateEd->setGeometry(5, 150, 250, 30);

    QLabel* item = new QLabel(tr("Enter kind item: "), this);
    item->setGeometry(5,185,150,20);
    itemEd->setGeometry(5, 210, 250, 30);
}

void PaySponsor::setId(int id)
{
    this->id = id;
    return;
}

void PaySponsor::FillForms(QString name, QString date, int number, QString itemh)
{
    nameEd->setText(name);
    dateEd->setText(date);
    numberEd->setText(QString::number(number));
    itemEd->setText(itemh);
}

PaySponsor::~PaySponsor()
{
    delete ui;
}
