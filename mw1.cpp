#include <QMediaPlayer>
#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"
#include <QTimer>
#include <map>
#include <iostream>
#include <windows.h>
extern string path;
extern int _gundamChoose;
using namespace std;
int playerstatus=1;
void MW1::end(){
    _game.destroy();
}

void MW1::oldgame(){
    string thepath=path;
    thepath+=("newGame.txt");
    const char* path1=thepath.c_str();
    _game.initWorld(path1);
    status=1;
}

void MW1::newgame(){
        string thepath=path;
        if(_gundamChoose==1) thepath+=("oldGame.txt");
        if(_gundamChoose==2) thepath+=("oldGame2.txt");
        if(_gundamChoose==3) thepath+=("oldGame3.txt");
        if(_gundamChoose==4) thepath+=("oldGame4.txt");

        if(_gundamChoose==1) timer->setInterval(300);
        if(_gundamChoose==2) timer->setInterval(150);
        if(_gundamChoose==3) timer->setInterval(100);
        if(_gundamChoose==4) timer->setInterval(70);

        if(_gundamChoose==1) timer2->setInterval(700);
        if(_gundamChoose==2) timer2->setInterval(500);
        if(_gundamChoose==3) timer2->setInterval(400);
        if(_gundamChoose==4) timer2->setInterval(300);

        const char* path1=thepath.c_str();

        _game.initWorld(path1);
        status=1;
}
MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(bulletMove()));//timeoutslot()为自定义槽
    timer->start(100);

    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(randomMove()));//timeoutslot()为自定义槽
    timer2->start(100);

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


    int index=5;
    string thepath=path;
    char indexpath='0'+index;
    thepath+=("picture//");
    thepath+=indexpath;
    thepath+=".jpg";
    const char* path1=thepath.c_str();


    pa->drawPixmap(0,0,1920,1080,QPixmap(path1));

    pa->setBrush(Qt::red);
    pa->drawRect(212,72,this->_game.getPlayer().getHp()*0.56,57);

    pa->setBrush(Qt::yellow);
    pa->drawRect(212,200,this->_game.getPlayer().getMoney()*0.56,57);


    this->_game.show(pa);
    pa->end();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{   if (status==0) return;
    static int k=0;
    if( playerstatus==0&&k<3) {
        k++;

        return;

    }
    else {
        k-=3;
    }
    //direction = 0,1,2,3 for 上 右 下 左
    bool b = 0;

    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1);

    }
    else if(e->key() == Qt::Key_D)
    {

        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_W)
    {

        this->_game.handlePlayerMove(0,1);
    }
    else if(e->key() == Qt::Key_S)
    {

        this->_game.handlePlayerMove(2,1);
    }
    else if(e->key() == Qt::Key_J)
    {
        this->_game.shootBullet(_game.getPlayer().getPosX(),_game.getPlayer().getPosY(),
                                _game.getPlayer().getDirection(),
                                _game.getPlayer().getBulletIndex(),0);
    }
    if(this->_game.getPlayer().getHp()<0)
    {
        _game.destroy();
    }
    if(this->_game.getVictory()){
        this->close();
        Sleep(300);
        status=0;
        _game.destroy();
        QMediaPlayer * player = new QMediaPlayer;
        string the_path=path+"music\\victory.mp3";
        const char* path1=the_path.c_str();
        player->setMedia(QUrl::fromLocalFile(path1));
        player->setVolume(50);
        player->play();
        emit victory();
    }
    this->repaint();
}
void MW1::bulletMove(){
    if (status==0) return;
    _game.handleBulletMove();
    _game.erase();
    this->update();
}

void MW1::randomMove(){
    if (status==0) return;
    _game.handleMonsterMove();

    this->_game.erase();

    if(this->_game.getPlayer().getHp()<0)
    {
        Sleep(300);
        status=0;
        _game.destroy();
        QMediaPlayer * player = new QMediaPlayer;
        string the_path=path+"music\\gameover.mp3";
        const char* path1=the_path.c_str();
        player->setMedia(QUrl::fromLocalFile(path1));
        player->setVolume(50);
        player->play();


        emit turnToEnd();
        this->hide();
    }
}




void MW1::on_pushButton_clicked()
{
    string the_path=path+"newgame.txt";
    const char * path1=the_path.c_str();
    _game.save(path1);

    if(status==0) status=1;
    else status=0;

}

void MW1::start(){
    status=1;
}

void MW1::on_pushButton_3_clicked()
{

    emit turnToMenu();
    Sleep (500);
    this->close();
}



