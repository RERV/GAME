#ifndef STARTSHOW_H
#define STARTSHOW_H

#include <QMainWindow>

namespace Ui {
class StartShow;
}

class StartShow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartShow(QWidget *parent = 0);
    ~StartShow();
    void paintEvent(QPaintEvent *e);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


signals:
    void turnToVedio();//显示登录对话框信号
    void quit();//退出信号
    void oldgame();
    void turnToCharge();
private:
    Ui::StartShow *ui;
   // QPainter *pa;
    //int index;
   // QPainter *pa2;
};

#endif // STARTSHOW_H
