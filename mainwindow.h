#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QStandardItemModel"
#include "QStandardItem"
#include "QSqlDatabase"
#include "QSqlError"
#include "QSqlQuery"
#include "iostream"
#include "editdata.h"
#include "people.h"
#include "edirsponsor.h"
#include "sponsors.h"
#include "QVariant"
#include "humanpay.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionHuman_triggered();

    void on_actionSponsor_triggered();

    void on_actionAll_people_triggered();

    void on_actionSponsors_triggered();

    void on_actionHuman_edit_triggered();

    void on_actionSponsor_2_triggered();

    void on_actionFrom_sponsor_triggered();

    void on_actionPays_sponsors_s_triggered();

    void on_tableData_doubleClicked(const QModelIndex &index);

    void on_actionSponsor_s_pays_triggered();

    void on_actionBank_triggered();

    void on_actionFor_human_triggered();

    void on_actionPays_for_people_triggered();

    void on_actionPays_for_human_triggered();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model = new QStandardItemModel;
    int idTable = 0;
};

#endif // MAINWINDOW_H
