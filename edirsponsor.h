#ifndef EDIRSPONSOR_H
#define EDIRSPONSOR_H

#include <QDialog>
#include "QLineEdit"

namespace Ui {
class edirsponsor;
}

class edirsponsor : public QDialog
{
    Q_OBJECT
    
public:
    explicit edirsponsor(QWidget *parent = 0);
    ~edirsponsor();
    QLineEdit *nameEd = new QLineEdit(this);
    QLineEdit *contactEd = new QLineEdit(this);
    QLineEdit *mainhelpEd = new QLineEdit(this);
    void setId(int id);
    void FillForms(QString name, QString contact, QString mainhelp);
    
private:
    Ui::edirsponsor *ui;
    int id;
};

#endif // EDIRSPONSOR_H
