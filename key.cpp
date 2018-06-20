#include "key.h"
#include <QMediaPlayer>
extern string path;
QMediaPlayer * playerk = new QMediaPlayer;
void Key::initKey(){
    this->_eatable=true;
}

void Key::onErase(){
    string the_path=path+"music\\eat3.mp3";
    const char * path1=the_path.c_str();
    playerk->setMedia(QUrl::fromLocalFile(path1));
    playerk->setVolume(100);
    playerk->play();
}
