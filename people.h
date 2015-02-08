#ifndef PEOPLE_H
#define PEOPLE_H

#include "QSqlQuery"
#include "QVariant"

class People
{
public:
    People();
    static void insert(QString name, QString secondname, QString lastname, QString dateB, QString dateD,
                       QString placeB, QString placeL, int sex, int workedNITI, int workedGroup, QString phonenumb);
    static QSqlQuery selectall();
    static void update(int id, QString name, QString secondname, QString lastname, QString dateB, QString dateD,
                       QString placeB, QString placeL, int sex, int workedNITI, int workedGroup, QString phonenumb);
};

#endif // PEOPLE_H
