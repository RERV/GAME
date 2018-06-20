#ifndef END_H
#define END_H

#include <QMainWindow>

namespace Ui {
class End;
}

class End : public QMainWindow
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    ~End();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
signals:
    void turnToMenu();
    void turnToGame();

private:
    Ui::End *ui;
};

#endif // END_H
