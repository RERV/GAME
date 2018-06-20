#ifndef CHARGE_H
#define CHARGE_H

#include <QMainWindow>

namespace Ui {
class Charge;
}

class Charge : public QMainWindow
{
    Q_OBJECT

public:
    explicit Charge(QWidget *parent = 0);
    ~Charge();
    void paintEvent(QPaintEvent *e);
signals:
    void turnToMenu();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Charge *ui;
};

#endif // CHARGE_H
