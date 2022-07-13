#ifndef AUDI_H
#define AUDI_H

#include <QMainWindow>
#include "bmw.h"

namespace Ui {
class audi;
}

class audi : public QMainWindow
{
    Q_OBJECT

public:
    explicit audi(QWidget *parent = 0);
    ~audi();

private slots:


    void on_next_clicked();

    void on_buyq8_clicked();

    void on_tomenu_clicked();

    void on_buyetron_clicked();

    void on_buya7_clicked();

private:
    Ui::audi *ui;
    BMW *bmw;
};

#endif // AUDI_H
