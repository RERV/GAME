#include "blood.h"
#include "player.h"

//WU
#include <QMediaPlayer>
QMediaPlayer * playerb = new QMediaPlayer;
extern string path;

void Blood::initBlood(int index){
    this->_hpChange=index*10;
    this->_eatable=true;

}

void Blood::onErase(){
   string the_path=path+"music\\eat.mp3";
   const char * path1=the_path.c_str();
   playerb->setMedia(QUrl::fromLocalFile(path1));
   playerb->setVolume(100);
    playerb->play();
}

