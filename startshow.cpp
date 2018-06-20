#include "startshow.h"
#include "ui_startshow.h"
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include<string>
#include<Qtime>
#include <QMediaPlayer>
QMediaPlayer * playerm = new QMediaPlayer;
using namespace std;
extern string path;
StartShow::StartShow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartShow)
{
    ui->setupUi(this);
}
void StartShow:: paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);


    int index=6;
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


    string the_path=path+"music\\start.mp3";
    const char * path2=the_path.c_str();
    playerm->setMedia(QUrl::fromLocalFile(path2));
    playerm->setVolume(100);
    playerm->play();
}

StartShow::~StartShow()
{
    delete ui;
}

void StartShow::on_pushButton_clicked()
{


  //  QTime dieTime = QTime::currentTime().addMSecs(100);
  //  while( QTime::currentTime() < dieTime )
  //  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    playerm->pause();
    playerm->setPosition(0);
    emit turnToVedio();
    this->close();
}


void StartShow::on_pushButton_2_clicked()
{
    playerm->pause();
    playerm->setPosition(0);
    emit oldgame();

    this->close();
}

void StartShow::on_pushButton_3_clicked()
{
    playerm->pause();
    playerm->setPosition(0);
    this->close();
    emit turnToCharge();

}

void StartShow::on_pushButton_4_clicked()
{
    playerm->pause();
    playerm->setPosition(0);
    emit quit();
    this->close();
}
