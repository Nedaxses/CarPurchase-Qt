#ifndef NEWCAR_H
#define NEWCAR_H

#include <QMainWindow>
#include "mercedes.h"
namespace Ui {
class newcar;
}

class newcar : public QMainWindow
{
    Q_OBJECT

public:
    explicit newcar(QWidget *parent = 0);
    ~newcar();

private slots:
    void on_tomercedes_clicked();

    void on_tomenu_clicked();

    void on_buymodelx_clicked();

    void on_buymodels_clicked();

    void on_buymodely_clicked();

private:
    Ui::newcar *ui;
    mercedes *merc_window;
};

#endif // NEWCAR_H
