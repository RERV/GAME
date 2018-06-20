#ifndef BLOOD_H
#define BLOOD_H
#include "rpgobj.h"
#include <QMediaPlayer>

class Blood : public RPGObj
{
public:
    Blood(){}
    ~Blood(){}
    void initBlood(int index);
    virtual int get_add_hp()const{return this->_hpChange;}
    virtual void onErase();
protected:
    int _hpChange;

};

#endif // BLOOD_H
