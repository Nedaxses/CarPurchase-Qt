#ifndef MAINMENU2_H
#define MAINMENU2_H

#include <QMainWindow>
#include "addmoney.h"
#include "changepass.h"
#include "newcar.h"

namespace Ui {
class MainMenu2;
}

class MainMenu2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu2(QWidget *parent = 0);
    ~MainMenu2();

private slots:
    void on_mybalance_clicked();

    void on_addbalance_clicked();

    void on_changepass_clicked();

    void on_rentacar_clicked();

private:
    Ui::MainMenu2 *ui;
    addmoney *addbalance_window;
    ChangePass *newpass_window;
    newcar *rent_window;
};

#endif // MAINMENU2_H
