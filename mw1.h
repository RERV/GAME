#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include<QTime>
#include<QTimer>

namespace Ui {
class MW1;
}

class MW1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
protected slots:
    void randomMove();//响应时钟事件的函数
    void bulletMove();
    void start();
    void end();
signals:
    void turnToMenu();
    void turnToEnd();
    void victory();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void newgame();
    void oldgame();
private:
    Ui::MW1 *ui;
    World _game;
    QTimer *timer;
    QTimer *timer2;

    bool status;//暂停使用，lu
        //时钟，控制玩家移动频率
};

#endif // MW1_H
