#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <string>
#include <QDebug>
#include "mainmenu2.h"
#include <QFile>
#include <QTextStream>

using namespace std;
class RegData
{
public:
    RegData(QString log = "", QString mail = "", QString pass = "", int bal = 0) : login(log), email(mail), password(pass), balance(bal)
    {
    }
    RegData(const RegData& src) :
        login(src.login), email(src.email), password(src.password), balance(src.balance)
    {
    }
    void cpy(const RegData& from)
    {
        login = from.login;
        email = from.email;
        password = from.password;
        balance = from.balance;
    }

    void output()
    {
        qDebug() << login<<email<<password<<balance;
    }
    QString getLogin()
    {
        return login;
    }
    QString getEmail()
    {
        return email;
    }
    QString getPassword()
    {
        return password;
    }
    int getBalance()
    {
        return balance;
    }

    void setLogin(const QString log)
    {
        login = log;
    }
    void setEmail(const QString mail)
    {
        email = mail;
    }
    void setPassword(const QString pass)
    {
        password = pass;
    }
    void setBalance(const int bal)
    {
        balance = bal;
    }

private:
    QString login;
    QString email;
    QString password;
    int balance;
};


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
    void on_button_reg_clicked();

    void on_button_log_clicked();

private:
    Ui::MainWindow *ui;
    MainMenu2 *second;
};
#endif // MAINWINDOW_H
