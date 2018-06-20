#include "loading.h"
#include "ui_loading.h"
#include <QPainter>
#include<iostream>
using namespace std;
extern string path;
loading::loading(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loading)
{
    ui->setupUi(this);
}

loading::~loading()
{
    delete ui;
}

void loading:: paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);


    int index=8;
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