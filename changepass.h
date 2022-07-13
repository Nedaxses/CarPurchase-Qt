#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QMainWindow>

namespace Ui {
class ChangePass;
}

class ChangePass : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangePass(QWidget *parent = 0);
    ~ChangePass();

private slots:
    void on_confirm_clicked();

    void on_isshowpass_stateChanged(int arg1);

private:
    Ui::ChangePass *ui;
};

#endif // CHANGEPASS_H
