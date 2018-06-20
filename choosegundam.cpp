#include "choosegundam.h"
#include "ui_choosegundam.h"
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include<string>
#include<Qtime>
using namespace std;
extern string path;
extern int _gundamChoose;
ChooseGundam::ChooseGundam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseGundam)
{
    ui->setupUi(this);
}

void ChooseGundam:: paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);


    int index=7;
    string thepath=path;
    char indexpath='0'+index;
    thepath+=("picture//");
    thepath+=indexpath;
    thepath+=".jpg";
    const char* path1=thepath.c_str();


    pa->drawPixmap(0,0,1920,1080,QPixmap(path1));
    //this->_game.show(pa);
    pa->end();
    delete pa;
}
void ChooseGundam:: on_pushButton_clicked(){

    _gundamChoose=1;
    emit gundam();
    this->hide();
}
void ChooseGundam:: on_pushButton_2_clicked(){

    _gundamChoose=2;
    emit gundam();
    this->hide();
}
void ChooseGundam:: on_pushButton_3_clicked(){

    _gundamChoose=3;
    emit gundam();
    this->hide();
}
void ChooseGundam:: on_pushButton_4_clicked(){

    _gundamChoose=4;
    emit gundam();
    this->hide();
}

ChooseGundam::~ChooseGundam()
{
    delete ui;
}
