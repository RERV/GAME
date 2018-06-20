#include "end.h"
#include "ui_end.h"
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include<string>
#include<Qtime>
#include<iostream>
using namespace std;
extern string path;

End::End(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);
}

void End:: paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);


    int index=4;
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

End::~End()
{
    delete ui;
}
void End::on_pushButton_4_clicked()
{
    cout<<"end1"<<endl;
    emit turnToGame();
    this->close();
}
void End::on_pushButton_2_clicked()
{
    emit turnToMenu();
    this->close();
}
void End::on_pushButton_3_clicked()
{
    this->close();
}
