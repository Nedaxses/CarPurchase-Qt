#include "mercedes.h"
#include "ui_mercedes.h"
#include "mainwindow.h"

extern RegData usr;

mercedes::mercedes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mercedes)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // | Qt::FramelessWindowHint);
    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));
}

mercedes::~mercedes()
{
    delete ui;
}

void mercedes::on_pushButton_clicked()
{
    hide();
    audi_window = new audi(nullptr);
    audi_window->show();
}

void mercedes::on_buyvito_clicked()
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
                if(usr.getBalance() < 40000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 40000; // current balance - car's price
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
        QMessageBox::information(this, "Mercedes", "Congratulations! You bought Mercedes-Benz Vito!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}

void mercedes::on_buygl63_clicked()
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
                if(usr.getBalance() < 33000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 33000; // current balance - car's price
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
        QMessageBox::information(this, "Mercedes", "Congratulations! You bought Mercedes-Benz GLE 63!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}

void mercedes::on_buyc_clicked()
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
                if(usr.getBalance() < 39000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 39000; // current balance - car's price
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
        QMessageBox::information(this, "Mercedes", "Congratulations! You bought Mercedes-Benz C Class!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}

void mercedes::on_tomenu_clicked()
{
    MainMenu2 *menu = new MainMenu2(nullptr);
    hide();
    menu->show();
}
