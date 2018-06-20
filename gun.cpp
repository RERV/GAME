#include "gun.h"
#include <QMediaPlayer>
extern string path;
QMediaPlayer * playerg = new QMediaPlayer;

void Gun::initGun(int index){
    this->_bullet_change_index=index+1;
    this->_eatable=true;
}

void Gun::onErase(){
    string the_path=path+"music\\eat2.mp3";
    const char * path1=the_path.c_str();
    playerg->setMedia(QUrl::fromLocalFile(path1));
    playerg->setVolume(100);
    playerg->play();
}
