#ifndef KEY_H
#define KEY_H
#include "rpgobj.h"


class Key : public RPGObj
{
public:
    Key(){}
    ~Key(){}
    void initKey();
    virtual void onErase();
};

#endif // KEY_H
