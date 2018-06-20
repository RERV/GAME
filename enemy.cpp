#include "enemy.h"
#include <QMediaPlayer>
#include <string>

extern string path;
QMediaPlayer * player_e = new QMediaPlayer;

void Enemy::initEnemy(int index){
    this->_bulletIndex=index;
    _hp=index*20+40;
    _add_money_hit=index*10;
}

void Enemy::onErase(){
    string the_path=path+"music\\disappear.mp3";
    const char * path1=the_path.c_str();
    player_e->setMedia(QUrl::fromLocalFile(path1));
    player_e->setVolume(100);
    player_e->play();
    //if(player_e->state()==0)delete player_e;
}

