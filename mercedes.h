#ifndef MERCEDES_H
#define MERCEDES_H

#include <QMainWindow>
#include "audi.h"

namespace Ui {
class mercedes;
}

class mercedes : public QMainWindow
{
    Q_OBJECT

public:
    explicit mercedes(QWidget *parent = 0);
    ~mercedes();

private slots:
    void on_pushButton_clicked();


    void on_buyvito_clicked();

    void on_buygl63_clicked();

    void on_buyc_clicked();

    void on_tomenu_clicked();

private:
    Ui::mercedes *ui;
    audi *audi_window;
};

#endif // MERCEDES_H
