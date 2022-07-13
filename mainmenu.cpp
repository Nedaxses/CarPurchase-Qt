#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"

extern RegData usr;
Mainmenu::Mainmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainmenu)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    QObject::connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(ui->maximize, &QPushButton::clicked, [this](){
          if (isFullScreen())
            showNormal();
          else
            showFullScreen();
        });
}

Mainmenu::~Mainmenu()
{
    delete ui;
}

void Mainmenu::on_pushButton_clicked()
{
    QMessageBox::information(this, "Great", "No");
}
