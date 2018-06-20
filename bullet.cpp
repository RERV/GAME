#include "bullet.h"

void Bullet::initBullet(int status){
    if(status==0){
        this->_attackplayer=0;
        this->_attackenemy=20*_index;
    }
    else if(status==1) {
        this->_attackplayer=20*_index;
        this->_attackenemy=0;
    }
}

