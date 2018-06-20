#ifndef GUN_H
#define GUN_H
#include "rpgobj.h"


class Gun : public RPGObj
{
public:
    Gun(){}
    ~Gun(){}
    void initGun(int index);
    virtual int getBulletChangeIndex()const{return this->_bullet_change_index;}
    virtual void onErase();
private:
    int _bullet_change_index;
    //int _money_change;
};

#endif // GUN_H
