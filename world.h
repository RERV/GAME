#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"
#include"enemy.h"
class World
{
public:
    World(){}
    ~World(){}

    void initWorld(string mapFile);
    void save(string mapFile);
    void show(QPainter * painter);
    void handlePlayerMove(int direction, int steps);
    void handleMonsterMove();
    void handleBulletMove();
    void shootBullet(int x,int y,int direction,int index,int status);
    void destroy();
    void erase();

    bool canCover(int direction, int steps,vector<RPGObj*>::iterator k);
    bool canCover(int direction, int steps);
    bool canEat(int direction, int steps);
    bool getVictory()const{return this->_victory;}

    Player getPlayer()const{return _player;}
private:
    vector<RPGObj*> _objs;
    Player _player;
    bool _victory;
};

#endif // WORLD_H
