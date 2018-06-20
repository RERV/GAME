#ifndef BARRIER_H
#define BARRIER_H
#include "rpgobj.h"


class Barrier : public RPGObj
{
public:
    Barrier(){}
    ~Barrier(){}
    void initBarrier(int index);
    virtual int getHpReduce_hit()const{return this->_hpReduce_hit;}
protected:
    int _hpReduce_hit;
};

#endif // BARRIER_H
