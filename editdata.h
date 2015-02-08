#ifndef EDITDATA_H
#define EDITDATA_H

#include <QDialog>
#include "QLineEdit"
#include <QtCore/QCoreApplication>
#include <QtCore>
#include "QComboBox"

namespace Ui {
class EditData;
}

class EditData : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditData(QWidget *parent = 0);
     QLineEdit *nameEd = new QLineEdit(this);
     QLineEdit *snameEd = new QLineEdit(this);
     QLineEdit *lnameEd = new QLineEdit(this);
     QLineEdit *DtBEd = new QLineEdit(this);
     QLineEdit *dtdEd = new QLineEdit(this);
     QLineEdit *plbEd = new QLineEdit(this);
     QLineEdit *pllEd = new QLineEdit(this);
     QLineEdit *phnEd = new QLineEdit(this);
     QComboBox *sexCB = new QComboBox(this);
     QComboBox *workNITICB = new QComboBox(this);
     QComboBox *workGroupCB = new QComboBox(this);
     void setId(int id);
     void FillForms(QString name, QString secondname, QString lastname, QString dateB, QString dateD,
                      QString placeB, QString placeL, QString sex, QString workedNITI, QString workedGroup, QString phonenumb);
    ~EditData();

    
private:
    Ui::EditData *ui;
    int id;
};

#endif // EDITDATA_H
