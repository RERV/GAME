#include "vedioshow.h"
#include "ui_vedioshow.h"
#include <windows.h>
#include<iostream>
#include <QVideoWidget>
using namespace  std;
VedioShow::VedioShow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VedioShow),status(0)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);
    ui->verticalLayout->addWidget(videoWidget);
}
void VedioShow::showvedio(){
    player->setMedia(QUrl::fromLocalFile("C:\\QTMap\\1.mp4"));
    videoWidget->show();
    player->play();
    //this->setCentralWidget(videoWidget);

    this->showFullScreen();
    //if(player->EndOfMedia==7) emit turnToGame();
}

VedioShow::~VedioShow()
{
    delete ui;
}


void VedioShow::on_closeVideo_clicked()
{




    emit turnToGame();
   // time = new QTimer(this);
    //Sleep(1900);
    this->close();
    //delete ui;
    player->pause();
    player->setPosition(0);
   // delete videoWidget;
}
