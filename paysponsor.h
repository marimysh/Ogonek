#ifndef PAYSPONSOR_H
#define PAYSPONSOR_H

#include <QDialog>
#include "QLineEdit"
#include "QLabel"
#include "QSqlQuery"

namespace Ui {
class PaySponsor;
}

class PaySponsor : public QDialog
{
    Q_OBJECT
    
public:
    explicit PaySponsor(QWidget *parent = 0);
    ~PaySponsor();
    QLineEdit *nameEd = new QLineEdit(this);
    QLineEdit *numberEd = new QLineEdit(this);
    QLineEdit *dateEd = new QLineEdit(this);
    QLineEdit *itemEd = new QLineEdit(this);
    void setId(int id);
    void FillForms(QString name, QString date, int number, QString itemh);

    
private:
    Ui::PaySponsor *ui;
    int id;
};

#endif // PAYSPONSOR_H
