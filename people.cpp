#include "people.h"
#include "QDebug"

People::People()
{
}

void People::insert(QString name, QString secondname, QString lastname,
               QString dateB, QString dateD, QString placeB, QString placeL,
               int sex, int workedNITI, int workedGroup,
               QString phonenumb)
{
    QSqlQuery submit;
    submit.prepare("INSERT INTO people (name, lastname, patronymic, dateBirth, dateDeath, placeBirth, placeLiving, sex, workedNITI, workedGroup, phoneNumber) "
                   "VALUES (:name, :secondname, :lastname, :dateB, :dateD, "
                   ":placeB, :placeL, :sex, :workedNITI, :workedGroup, :phonenumb)");
    submit.bindValue(":name", name);
    submit.bindValue(":secondname", secondname);
    submit.bindValue(":lastname", lastname);
    submit.bindValue(":dateB", dateB);
    submit.bindValue(":dateD", dateD);
    submit.bindValue(":placeB", placeB);
    submit.bindValue(":placeL", placeL);
    submit.bindValue(":sex", sex);
    submit.bindValue(":workedNITI", workedNITI);
    submit.bindValue(":workedGroup", workedGroup);
    submit.bindValue(":phonenumb", phonenumb);
    qDebug() << submit.exec();
    return;
}

QSqlQuery People::selectall()
{
    QSqlQuery getInfo;
    getInfo.prepare("SELECT * from people");
    getInfo.exec();
    return getInfo;
}

void People::update(int id, QString name, QString secondname, QString lastname, QString dateB,
                    QString dateD, QString placeB, QString placeL, int sex,
                    int workedNITI, int workedGroup, QString phonenumb)
{
    QSqlQuery submit;
    submit.prepare("UPDATE people SET name=:name, lastname=:secondname, patronymic=:lastname, dateBirth=:dateB, dateDeath=:dateD, "
                   "placeBirth=:placeB, placeLiving=:placeL, sex=:sex, workedNITI=:workedNITI, workedGroup=:workedGroup, phoneNumber=:phonenumb WHERE id=:id");
    submit.bindValue(":id", id);
    submit.bindValue(":name", name);
    submit.bindValue(":secondname", secondname);
    submit.bindValue(":lastname", lastname);
    if (dateB == "")
        submit.bindValue(":dateB", "NULL");
    else
        submit.bindValue(":dateB", dateB);
    if (dateD == "")
        submit.bindValue(":dateD", "NULL");
    else
        submit.bindValue(":dateD", dateD);
    submit.bindValue(":placeB", placeB);
    submit.bindValue(":placeL", placeL);
    submit.bindValue(":sex", sex);
    submit.bindValue(":workedNITI", workedNITI);
    submit.bindValue(":workedGroup", workedGroup);
    submit.bindValue(":phonenumb", phonenumb);
    qDebug() << submit.exec();
    return;
}
