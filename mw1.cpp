#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"
#include <QTimer>
#include <map>
#include <iostream>
#include <windows.h>

using namespace std;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);

    //init game world
    _game.initWorld("C:\\learing\\programming\\RCgame\\oldGame.txt");//TODO 应该是输入有效的地图文件

    //以下是对时钟的初始化
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(randomMove()));//timeoutslot()为自定义槽
        //时钟事件与randomMove函数绑定
    timer->start(100);
    timer->setInterval(400);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        //设置随机数种子
}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    pa->drawPixmap(0,0,800,600,QPixmap("C:\\learing\\programming\\RCgame\\1.jpg"));
    this->_game.show(pa);
    pa->end();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    bool b = 0;
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1,b);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(4,1,b);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1,b);
    }
    else if(e->key() == Qt::Key_S)
    {
        this->_game.handlePlayerMove(2,1,b);
    }
    this->repaint();
    if(b)
    {
        Sleep(300);
        _game.destroy();
        cout << "You are dead!"<<endl;
        cout << "Game over!"<<endl;
        cout << "Thanks for playing!"<<endl;
    }
    this->repaint();
}


void MW1::randomMove(){
    bool g = 0;
    _game.handleMonsterMove(g);
    this->repaint();
    if(g)
    {
        Sleep(300);
        _game.destroy();
        cout << "You are dead!"<<endl;
        cout << "Game over!"<<endl;
        cout << "Thanks for playing!"<<endl;
    }
    this->repaint();
}

void MW1::on_pushButton_clicked()
{
    _game.destroy();
    cout << "Game over!"<<endl;
    cout << "Thanks for playing!"<<endl;
}

void MW1::on_pushButton_2_clicked()
{
    _game.save("C:\\learing\\programming\\RCgame\\oldGame.txt");
    cout << "Saving successfully!"<<endl;
}

void MW1::on_pushButton_3_clicked()
{
    _game.destroy();
    _game.initWorld("C:\\learing\\programming\\RCgame\\newGame.txt");
}
