#include "addmoney.h"
#include "ui_addmoney.h"
#include "mainwindow.h"

extern RegData usr;

addmoney::addmoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addmoney)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
}

addmoney::~addmoney()
{
    delete ui;
}


void addmoney::on_pushButton_clicked()
{
    int value = ui->balancespin->value();
    int balanceres = 0;
    bool issucceed = false;
    QFile file("../Carsharring_files/users.txt");
    QVector<RegData> data;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString str1, str2, str3;
        int balance=0;
        while(!in.atEnd())
        {
            in>>str1>>str2>>str3>>balance;
            if(str1 != "" or str2 !="" or str3 != "")
            {
                RegData tmp(str1, str2, str3, balance);
                data.push_back(tmp);
            }
        }
        for(QVector<RegData>::iterator it = data.begin(); it<data.end(); it++)
        {
            if(it->getLogin() == usr.getLogin() && it->getPassword() == usr.getPassword())
            {
                balanceres = value+it->getBalance();
                it->setBalance(balanceres);
                issucceed = true;
                break;
            }
        }
        file.close();
        QFile infile("../Carsharring_files/users.txt");
        if(infile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
        {
            for(QVector<RegData>::iterator it = data.begin(); it < data.end(); it++)
            {
                QTextStream textstr(&infile);
                textstr<<it->getLogin()<<" "<<it->getEmail()<<" "<<it->getPassword()<<" "<<it->getBalance()<<"\n";
            }
        }
        infile.close();
    }
    if(issucceed)
    {
        usr.setBalance(balanceres);
        QMessageBox::information(this, "Balance", "Succeed");
        hide();
    }
}

void addmoney::on_balancespin_valueChanged(int arg1)
{
    ui->balancespin->setMaximum(50000);
}
