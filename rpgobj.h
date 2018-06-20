#ifndef RPGOBJ_H
#define RPGOBJ_H
#include <QImage>
#include <QPainter>
#include <string>
#include <icon.h>
#include <map>
#include<iostream>
using namespace std;
class RPGObj
{
public:
    RPGObj():_hp(100){}
    virtual ~RPGObj(){}

    void initObj(string type,int index);
    void show(QPainter * painter);
    void move(int direction, int steps);

    void setDirection(int x){this->_direction=x;}
    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    void setHp(int k);
    void setStatus(int k){_status=k;}

    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getHeight() const{return this->_icon.getHeight();}
    int getWidth() const{return this->_icon.getWidth();}
    int getDirection ()const{return _direction;}
    int getHp ()const {return _hp;}
    int getStatus() const{return _status;}
    int getIndex() const{return _index;}
    string getObjType() const{return this->_icon.getTypeName();}

    bool canCover() const{return this->_coverable;}
    bool canEat() const{return this->_eatable;}

    virtual void onErase(){return;}
    virtual int getBulletIndex()const{return 1;}
    virtual int get_attack_player()const{return 10;}
    virtual int get_attack_enemy()const{return 10;}
    virtual int get_add_hp()const{return 10;}
    virtual int getHpReduce_hit()const{return 0;}
    virtual int getBulletChangeIndex()const{return 1;}
    virtual int getAddMoney()const{return 10;}
protected:
    QImage _pic;
    int _pos_x, _pos_y;//该物体在游戏中当前位置（左上角坐标）
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息
    bool _coverable;
    bool _eatable;
    int _hp;
    int _direction;
    string _type;
    int _status;
    int _index;
};

#endif // RPGOBJ_H
