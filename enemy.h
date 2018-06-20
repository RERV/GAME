#ifndef ENEMY_H
#define ENEMY_H
#include "rpgobj.h"
#include"bullet.h"
class Enemy : public RPGObj
{
public:
    Enemy(){}
    ~Enemy(){}
    void initEnemy(int index);
    void setBulletIndex(int k){this->_bulletIndex=k;}
    virtual int getBulletIndex() const{return this->_bulletIndex;}
    virtual void onErase();
    virtual int getAddMoney()const{return this->_add_money_hit;}
private:
    int _bulletIndex;
    int _add_money_hit;
};

#endif // ENEMY_H
