#ifndef PLAYER_H
#define PLAYER_H
#include "rpgobj.h"

class Player: public RPGObj
{
public:
    Player():_money(0){} //不做初始化会有金币槽闪现
    ~Player(){}
    void initPlayer(){this->_money=0;}
    void move(int direction, int steps=1);
    void setBulletIndex(int k){this->_player_Bullet_Index=k;}
    void setMoney(int money);
    int getMoney()const{return this->_money;}
    virtual int getBulletIndex()const{return this->_player_Bullet_Index;}
    static int getKeyAmount(){return _key_amount;}
    static void addKeyAmount(){_key_amount++;}
private:
    int _player_Bullet_Index;
    int _money;
    static int _key_amount;
};

#endif // PLAYER_H
