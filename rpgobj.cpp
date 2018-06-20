#include "rpgobj.h"
#include <iostream>
extern string path;
void RPGObj::setHp(int k){
    if(k>500) this->_hp=500;
    else _hp=k;
}

void RPGObj::initObj(string type,int index)
{   _hp=100;
    this->_coverable = false;
    this->_eatable=false;
    _index=index;
    _direction = 0;

    this->_icon = ICON::findICON(type);
    QImage all;
    string thepath=path;
    char indexpath='0'+index;
    thepath+=("picture\\"+type+" ("+indexpath+").png");
    const char* path1=thepath.c_str();
    all.load(path1);
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}

void RPGObj::show(QPainter * pa)
{
    int gSize = ICON::GRID_SIZE;
    QTransform trans;
    trans.translate(+this->getPosX()*66+33,+this->getPosY()*66+33);
    trans.rotate(90*_direction);
    trans.translate(-this->getPosX()*66-33,-this->getPosY()*66-33);
    pa->setWorldTransform(trans);
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

void RPGObj::move(int direction, int steps){
    switch (direction){
    case 2:
        if(this->_pos_y<15)
        this->_pos_y += steps;
        break;
    case 0:
        if(this->_pos_y>0)
        this->_pos_y -= steps;
        break;
    case 3:
        if(this->_pos_x>0 )
        this->_pos_x -= steps;
        break;
    case 1:
        if(this->_pos_x<28 )
        this->_pos_x += steps;
        break;

    }
}

