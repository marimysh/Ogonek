#ifndef PAY_H
#define PAY_H

#include "QLineEdit"
#include "QSqlQuery"

class Pay
{
public:
    Pay();
    static void insertPaySponsor(QString name, int number, QString date, QString item);
    static void updatePaySponsor(int id, QString name, int number, QString date, QString item);
    static QSqlQuery selectall();
    static QSqlQuery selectallBank();
    static QSqlQuery selectallPayHuman();
    static void insertPayHuman(QString name, QString namel, QString namep, int number, QString date, QString item);
    static void updatePayHuman(int id, QString name, QString namel, QString namep, int number, QString date, QString item);
};

#endif // PAY_H
