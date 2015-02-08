#include "edirsponsor.h"
#include "ui_edirsponsor.h"
#include "QLabel"

edirsponsor::edirsponsor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edirsponsor)
{
    ui->setupUi(this);
    QLabel* Name = new QLabel(tr("Enter Name: "), this);
    Name->setGeometry(5,5,150,20);
    nameEd->setGeometry(5, 30, 250, 30);

    QLabel* contact = new QLabel(tr("Enter contact: "), this);
    contact->setGeometry(5,65,150,20);
    contactEd->setGeometry(5, 90, 250, 30);

    QLabel* mainhelp = new QLabel(tr("Enter main help: "), this);
    mainhelp->setGeometry(5,125,150,20);
    mainhelpEd->setGeometry(5, 150, 250, 30);
}

void edirsponsor::setId(int id)
{
    this->id = id;
    return;
}

void edirsponsor::FillForms(QString name, QString contact, QString mainhelp)
{
    nameEd->setText(name);
    contactEd->setText(contact);
    mainhelpEd->setText(mainhelp);
}

edirsponsor::~edirsponsor()
{
    delete ui;
}
