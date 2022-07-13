#include "mainmenu2.h"
#include "ui_mainmenu2.h"
#include "mainwindow.h"

extern RegData usr;

MainMenu2::MainMenu2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu2)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // | Qt::FramelessWindowHint);

    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
        QObject::connect(ui->minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));
}

MainMenu2::~MainMenu2()
{
    delete ui;
}

void MainMenu2::on_mybalance_clicked()
{
    QString output;
    output.append("Your balance: ");
    output.append(QString::number(usr.getBalance()));
    output.append(" $");
    QMessageBox::information(this, "Balance", output);
}

void MainMenu2::on_addbalance_clicked()
{
    addbalance_window = new addmoney(nullptr);
    addbalance_window->show();
}

void MainMenu2::on_changepass_clicked()
{
    newpass_window = new ChangePass(nullptr);
    newpass_window->show();
}

void MainMenu2::on_rentacar_clicked()
{
    hide();
    rent_window = new newcar(nullptr);
    rent_window->show();
}
