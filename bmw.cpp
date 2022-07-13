#include "bmw.h"
#include "ui_bmw.h"
#include "mainwindow.h"
extern RegData usr;

BMW::BMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BMW)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // | Qt::FramelessWindowHint);
    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));
}

BMW::~BMW()
{
    delete ui;
}

void BMW::on_buyx5m_clicked()
{
    bool issucceed = false;
    int balanceres = 0;
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
            if(it->getLogin() == usr.getLogin() and it->getPassword() == it->getPassword())
            {
                if(usr.getBalance() < 65000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 65000; // current balance - car's price
                    it->setBalance(balanceres);
                    issucceed = true;
                    break;
                }
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
        QMessageBox::information(this, "BMW", "Congratulations! You bought BMW X5M!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}

void BMW::on_buyix3_clicked()
{
    bool issucceed = false;
    int balanceres = 0;
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
            if(it->getLogin() == usr.getLogin() and it->getPassword() == it->getPassword())
            {
                if(usr.getBalance() < 100000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 100000; // current balance - car's price
                    it->setBalance(balanceres);
                    issucceed = true;
                    break;
                }
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
        QMessageBox::information(this, "BMW", "Congratulations! You bought BMW iX3!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}

void BMW::on_buym5_clicked()
{
    bool issucceed = false;
    int balanceres = 0;
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
            if(it->getLogin() == usr.getLogin() and it->getPassword() == it->getPassword())
            {
                if(usr.getBalance() < 100000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 100000; // current balance - car's price
                    it->setBalance(balanceres);
                    issucceed = true;
                    break;
                }
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
        QMessageBox::information(this, "BMW", "Congratulations! You bought BMW M5 F90!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}

void BMW::on_tomenu_clicked()
{
    MainMenu2 *menu = new MainMenu2(nullptr);
    hide();
    menu->show();
}
