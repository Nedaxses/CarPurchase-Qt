#ifndef BMW_H
#define BMW_H

#include <QMainWindow>

namespace Ui {
class BMW;
}

class BMW : public QMainWindow
{
    Q_OBJECT

public:
    explicit BMW(QWidget *parent = 0);
    ~BMW();

private slots:


    void on_buyx5m_clicked();

    void on_buyix3_clicked();

    void on_buym5_clicked();

    void on_tomenu_clicked();

private:
    Ui::BMW *ui;
};

#endif // BMW_H
