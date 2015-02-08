#include "sponsors.h"

Sponsors::Sponsors()
{
}

void Sponsors::insert(QString name, QString contact, QString mainhelp)
{
    QSqlQuery submit;
    submit.prepare("INSERT INTO sponsors (name, contact, mainhelp) "
                   "VALUES (:name, :contact, :mainhelp)");
    submit.bindValue(":name", name);
    submit.bindValue(":contact", contact);
    submit.bindValue(":mainhelp", mainhelp);
    submit.exec();
    return;
}

QSqlQuery Sponsors::selectall()
{
    QSqlQuery getInfo;
    getInfo.prepare("SELECT * from sponsors");
    getInfo.exec();
    return getInfo;
}

void Sponsors::update(int id, QString name, QString contact, QString mainhelp)
 {
     QSqlQuery submit;
     submit.prepare("UPDATE sponsors SET name=:name, contact=:contact, mainhelp=:mainhelp WHERE id=:id");
     submit.bindValue(":id", id);
     submit.bindValue(":name", name);
     submit.bindValue(":contact", contact);
     submit.bindValue(":mainhelp", mainhelp);
     submit.exec();
     return;
 }
