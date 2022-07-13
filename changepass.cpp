#include "changepass.h"
#include "ui_changepass.h"
#include "mainwindow.h"

extern RegData usr;

ChangePass::ChangePass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangePass)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
}

ChangePass::~ChangePass()
{
    delete ui;
}

void ChangePass::on_confirm_clicked()
{
    QString newpass = ui->newpass->text();
    bool isempty = false, requirements = true, ischanged = false;
    if(newpass.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Input password");
        isempty = true;
    }
    if(isempty == false and newpass.count() < 8)
    {
        QMessageBox::warning(this, "Error", "The password contains less than 8 symbols");
        requirements = false;
    }
    if(isempty == false and requirements == true)
    {
        QVector<RegData> data;
        QFile file("../Carsharring_files/users.txt");
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
                if(it->getLogin() == usr.getLogin() and it->getPassword() == usr.getPassword())
                {
                    if(it->getPassword() == newpass)
                    {
                        QMessageBox::warning(this, "Error", "New password looks like the old");
                    }
                    else
                    {
                        it->setPassword(newpass);
                        ischanged = true;
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
        if(ischanged)
        {
            usr.setPassword(newpass);
            QMessageBox::information(this, "Password", "The password has changed");
            hide();
        }
    }
}

void ChangePass::on_isshowpass_stateChanged(int arg1)
{
    if(ui->isshowpass->isChecked()) ui->newpass->setEchoMode(QLineEdit::Normal);
    else ui->newpass->setEchoMode(QLineEdit::Password);
}
