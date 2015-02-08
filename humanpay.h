#ifndef HUMANPAY_H
#define HUMANPAY_H

#include <QDialog>
#include "QLabel"
#include "QLineEdit"

namespace Ui {
class HumanPay;
}

class HumanPay : public QDialog
{
    Q_OBJECT
    
public:
    explicit HumanPay(QWidget *parent = 0);
    QLineEdit *nameEd = new QLineEdit(this);
    QLineEdit *namelEd = new QLineEdit(this);
    QLineEdit *namepEd = new QLineEdit(this);
    QLineEdit *numberEd = new QLineEdit(this);
    QLineEdit *dateEd = new QLineEdit(this);
    QLineEdit *itemEd = new QLineEdit(this);
    void FillForms(QString name, QString namel, QString namep, QString date, int number, QString itemh);
    ~HumanPay();
    
private:
    Ui::HumanPay *ui;
};

#endif // HUMANPAY_H
