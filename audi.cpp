#include "audi.h"
#include "ui_audi.h"
#include "mainwindow.h"

extern RegData usr;

audi::audi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::audi)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // | Qt::FramelessWindowHint);
    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));
}

audi::~audi()
{
    delete ui;
}

void audi::on_next_clicked()
{
    hide();
    bmw = new BMW(nullptr);
    bmw->show();
}

void audi::on_buyq8_clicked()
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
                if(usr.getBalance() < 70000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 70000; // current balance - car's price
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
        QMessageBox::information(this, "Audi", "Congratulations! You bought AUDI Q8!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance!");
    }
}

void audi::on_tomenu_clicked()
{
    MainMenu2 *menu = new MainMenu2(nullptr);
    hide();
    menu->show();
}

void audi::on_buyetron_clicked()
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
                if(usr.getBalance() < 70000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 70000; // current balance - car's price
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
        QMessageBox::information(this, "Audi", "Congratulations! You bought AUDI E Tron!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance!");
    }
}

void audi::on_buya7_clicked()
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
                if(usr.getBalance() < 55000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 55000; // current balance - car's price
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
        QMessageBox::information(this, "Audi", "Congratulations! You bought AUDI A7!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}
