#ifndef BULLET_H
#define BULLET_H
#include "rpgobj.h"


class Bullet: public RPGObj
{
protected:
    int _velocity;
    int _attackplayer;
    int _attackenemy;
    int _needtime;
public:
    Bullet(){}
    ~Bullet(){}
    void initBullet(int index);
    virtual int get_attack_player ()const{return this->_attackplayer;}
    virtual int get_attack_enemy() const{return this->_attackenemy;}
    //virtual void onErase(){return;}
};

#endif // BULLET_H
