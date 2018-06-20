#ifndef ICEBULLET_H
#define ICEBULLET_H
#include"bullet.h"
extern bool  playerstatus;
class IceBullet : public Bullet
{
public:
    IceBullet(){}
    ~IceBullet(){}
private:
    void changeStatus();
};

#endif // ICEBULLET_H
