#include "pay.h"

Pay::Pay()
{
}

void Pay::insertPaySponsor(QString name, int number, QString date, QString item)
{
    QSqlQuery submit;
    submit.prepare("CALL insertintopayspons (:name, :number, :date, :item)");
    submit.bindValue(":name", name);
    submit.bindValue(":number", number);
    submit.bindValue(":date", date);
    submit.bindValue(":item", item);
    submit.exec();
    return;
}

void Pay::updatePaySponsor(int id, QString name, int number, QString date, QString item)
{
    QSqlQuery submit;
    submit.prepare("CALL updatepayspons (:id, :name, :number, :date, :item);");
    submit.bindValue(":id", id);
    submit.bindValue(":name", name);
    submit.bindValue(":number", number);
    submit.bindValue(":date", date);
    submit.bindValue(":item", item);
    submit.exec();
    return;
}

QSqlQuery Pay::selectall()
{
    QSqlQuery getInfo;
    getInfo.prepare("SELECT sp.id, s.name, sp.datepay, sp.number, bank.nameitem "
                    "from sponsorspay sp, bank, sponsors s where s.id = sp.sponsor and bank.id = sp.item;");
    getInfo.exec();
    return getInfo;
}

QSqlQuery Pay::selectallBank()
{
    QSqlQuery getInfo;
    getInfo.prepare("SELECT * from bank;");
    getInfo.exec();
    return getInfo;
}

QSqlQuery Pay::selectallPayHuman()
{
    QSqlQuery getInfo;
    getInfo.prepare("SELECT pl.name, pl.lastname, pl.patronymic, pm.datepay, pm.number, bank.nameitem, pm.id "
                    "from payments pm, bank, people pl where pl.id = pm.human and bank.id = pm.item;");
    getInfo.exec();
    return getInfo;
}

void Pay::insertPayHuman(QString name, QString namel, QString namep, int number, QString date, QString item)
{
    QSqlQuery submit;
    submit.prepare("CALL insertintopaypeople (:name, :namel, :namep, :number,"
                   ":date, :item);");
    submit.bindValue(":name", name);
    submit.bindValue(":namel", namel);
    submit.bindValue(":namep", namep);
    submit.bindValue(":number", number);
    submit.bindValue(":date", date);
    submit.bindValue(":item", item);
    submit.exec();
    return;
}

void Pay::updatePayHuman(int id, QString name, QString namel, QString namep, int number, QString date, QString item)
{
    QSqlQuery submit;
    submit.prepare("CALL updatepaypeople (:id, :name, :namel, :namep, :number,"
                   ":date, :item);");
    submit.bindValue(":id", id);
    submit.bindValue(":name", name);
    submit.bindValue(":namel", namel);
    submit.bindValue(":namep", namep);
    submit.bindValue(":number", number);
    submit.bindValue(":date", date);
    submit.bindValue(":item", item);
    submit.exec();
    return;
}
