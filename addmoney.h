#ifndef ADDMONEY_H
#define ADDMONEY_H

#include <QDialog>

namespace Ui {
class addmoney;
}

class addmoney : public QDialog
{
    Q_OBJECT

public:
    explicit addmoney(QWidget *parent = 0);
    ~addmoney();

//private slots:

private slots:


    void on_pushButton_clicked();

    void on_balancespin_valueChanged(int arg1);

private:
    Ui::addmoney *ui;
};

#endif // ADDMONEY_H
