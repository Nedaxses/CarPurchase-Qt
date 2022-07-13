#include "mainwindow.h"
#include "ui_mainwindow.h"

RegData usr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    //reg
    ui->log_reg->setPlaceholderText("Login");
    ui->email_reg->setPlaceholderText("Email");
    ui->pass_reg->setPlaceholderText("Password");
    //log
    ui->log_log->setPlaceholderText("Login or email");
    ui->pass_log->setPlaceholderText("Password");
    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool islog = false;
void MainWindow::on_button_reg_clicked()
{
    QFile file("../Carsharring_files/users.txt");
    QString logline = ui->log_reg->text();
    QString emailline = ui->email_reg->text();
    QString passline = ui->pass_reg->text();
    int balance = 0;
    bool empty = false, requirements = true;

    //Isempty
    if(logline.isEmpty()){
        QMessageBox::warning(this, "Error", "Input login");
        empty = true;
    }
    if(emailline.isEmpty()) {
        QMessageBox::warning(this, "Error", "Input email");
        empty = true;
    }
    if(passline.isEmpty()) {
        QMessageBox::warning(this, "Error", "Input password");
        empty = true;
    }
    //Requirements
    if(empty == false and emailline.contains("@") == false)
    {
        QMessageBox::warning(this, "Error", "Incorrect email format");
        requirements = false;
    }
    if(empty == false and passline.count() < 8)
    {
        QMessageBox::warning(this, "Error", "The password contains less than 8 symbols");
        requirements = false;
    }
    if(empty == false and requirements == true)
    {
        QVector<RegData> data;
        //RegData account;
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString str1, str2, str3;
            while(!in.atEnd())
            {
                in>>str1>>str2>>str3>>balance;
                if(str1 != "" or str2 !="" or str3 != "")
                {
                    RegData tmp(str1, str2, str3, balance);
                    data.push_back(tmp);
                }
            }
            bool isreg = false;
            for(QVector<RegData>::iterator it = data.begin();  it < data.end(); it++)
            {
                if(it->getLogin() == logline or it->getEmail() == emailline)
                {
                    QMessageBox::warning(this, "Error", "The account has already registered!");
                    usr.cpy(*it);
                    isreg = true;
                }
            }
            if(!isreg)
            {
                RegData tmp(logline, emailline, passline, balance);
                usr.cpy(tmp);
                data.push_back(tmp);
                file.close();
                QFile infile("../Carsharring_files/users.txt");
                if(infile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
                {
                    for(QVector<RegData>::iterator it = data.begin(); it < data.end(); it++)
                    {
                        QTextStream textstr(&infile);
                        textstr<<it->getLogin()<<" "<<it->getEmail()<<" "<<it->getPassword()<<" "<<it->getBalance()<<"\n";
                    }
                    QMessageBox::information(this, "Registration", "Registration successful!");
                    ui->log_reg->setText("");
                    ui->email_reg->setText("");
                    ui->pass_reg->setText("");
                    islog = true;
                }
            }
            if(islog)
            {
                hide();
                second = new MainMenu2(nullptr);
                second->show();
            }
        }
        else QMessageBox::warning(this, "Connection", "Connection error");
    }

}

void MainWindow::on_button_log_clicked()
{
    QString loginline = ui->log_log->text();
    QString passwordline = ui->pass_log->text();
    QVector<RegData> data;
    //class RegData account;
    QFile file_login("../Carsharring_files/users.txt");
    bool isempty = false;

    if(loginline.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Input login");
        isempty = true;
    }
    if(passwordline.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Input password");
        isempty = true;
    }
    else if(passwordline.count() < 8)
    {
        QMessageBox::warning(this, "Error", "The password contains less than 8 symbols");
        isempty = true;
    }

    if(!isempty)
    {
        if(file_login.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file_login);
            QString str1, str2, str3;
            int balance;
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
                if(loginline == it->getLogin() and passwordline == it->getPassword() or loginline == it->getEmail() and passwordline == it->getPassword())
                {
                    islog = true;
                    usr.cpy(*it);
                    break;
                }
                else
                {
                    islog = false;
                }
            }
            if(islog)
            {
                QMessageBox::information(this, "Login", "You have successfully logged in account!");
                ui->log_log->setText("");
                ui->pass_log->setText("");

                hide();
                second = new MainMenu2(nullptr);
                second->show();

            }
            else if(!islog)
            {
                QMessageBox::warning(this, "Login", "Incorrect data");
            }
        }
        else
        {
            QMessageBox::warning(this, "Connection", "Connect error");
        }
    }
}
