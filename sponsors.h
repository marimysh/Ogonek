#ifndef SPONSORS_H
#define SPONSORS_H

#include "QSqlQuery"
#include "QVariant"

class Sponsors
{
public:
    Sponsors();
    static void insert(QString name, QString contact, QString mainhelp);
    static QSqlQuery selectall();
    static void update(int id, QString name, QString contact, QString mainhelp);
};

#endif // SPONSORS_H
