#include "newcar.h"
#include "ui_newcar.h"
#include "mainwindow.h"

extern RegData usr;

newcar::newcar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newcar)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // | Qt::FramelessWindowHint);
    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));
}

newcar::~newcar()
{
    delete ui;
}

void newcar::on_tomercedes_clicked()
{
    hide();
    merc_window = new mercedes(nullptr);
    merc_window->show();
}

void newcar::on_tomenu_clicked()
{
    MainMenu2 *menu = new MainMenu2(nullptr);
    hide();
    menu->show();

}

void newcar::on_buymodelx_clicked()
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
                if(usr.getBalance() < 90000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 90000; // current balance - car's price
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
        QMessageBox::information(this, "Tesla", "Congratulations! You bought Tesla Model X!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}

void newcar::on_buymodels_clicked()
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
        QMessageBox::information(this, "Tesla", "Congratulations! You bought Tesla Model S!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}

void newcar::on_buymodely_clicked()
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
                if(usr.getBalance() < 66000)
                {
                    issucceed = false;
                }
                else {
                    balanceres = usr.getBalance() - 66000; // current balance - car's price
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
        QMessageBox::information(this, "Tesla", "Congratulations! You bought Tesla Model Y!");
        MainMenu2 *menu = new MainMenu2(nullptr);
        hide();
        menu->show();
    }
    else {
        QMessageBox::warning(this, "Balance", "Not enough money on the balance");
    }
}
