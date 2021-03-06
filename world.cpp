#include "world.h"
#include "icon.h"
#include <fstream>
#include <sstream>

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5

    string line,s1;
    stringstream ss1;
    int x1,y1;
    ifstream ifs(mapFile);

    getline(ifs,line);
    ss1 << line;

    ss1 >> s1 >> x1 >> y1;
    if(s1=="player")
    {
        _player.initObj("player");
        _player.setPosX(x1);
        _player.setPosY(y1);
    }
    while(1)
    {
        string s;
        int x,y;
        stringstream ss;
        getline(ifs,line);
        if(ifs.fail())return;
        ss << line;
        ss >> s >> x >> y;
        if(s.size()==0)return;
        RPGObj obj1;
        obj1.initObj(s);
        obj1.setPosX(x);
        obj1.setPosY(y);
        _objs.push_back(obj1);
    }
}

void World::save(string mapFile)
{
    string line,s1;
    stringstream ss1;
    int x1,y1;
    ofstream ifs(mapFile,fstream::out);
    ifs << "player "<< _player.getPosX()<<" "<<_player.getPosY()<<endl;
    for(const auto &g : _objs)
    {
        ifs << g.getObjType()<<" "<<g.getPosX()<<" "<<g.getPosY()<<endl;
    }
}

void World::destroy()
{
    _player.setAlive(0);
    _objs.clear();
}

void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    this->_player.show(painter);
}

void World::handleMonsterMove(bool &b)
{
    for(auto it = _objs.begin();it != _objs.end();++it)
    {
        if(it->getObjType()=="grave")
        {
            int ra = 1 + rand()%4;
            if(!canCover(ra,1,it,b))continue;
            it->move(ra, 1);
        }
    }
}

bool World::canCover(int direction, int steps,vector<RPGObj>::iterator k,bool &b)
{
    int x = k->getPosX(),y = k->getPosY();
    if(direction == 1)--y;
    if(direction == 2)++y;
    if(direction == 3)--x;
    if(direction == 4)++x;
    if(x==_player.getPosX()&&y==_player.getPosY()+1)
    {
      //  b = 1;
        return true;
    }
    for(auto it = _objs.begin();it != _objs.end();++it)
    {
        if(it == k)continue;
        if(!it->canCover()/*||it->canEat()||it->ifDeadly()*/)
        {
            int x1 = it->getPosX(),x2 = x1 + it->getWidth();
            int y1 = it->getPosY(),y2 = y1 + it->getHeight();
            if(x1<=x&&x<x2&&y1<=y&&y<y2)
            {
                return false;
            }
        }
    }
    return true;
}

void World::handlePlayerMove(int direction, int steps,bool &b)
{

    if(ifDead(direction, steps))
    {
        this->_player.move(direction, steps);
        b = 1;
        return;
    }

    if(!canCover(direction,steps))return;

    if(canEat(direction, steps))
    {
        this->_player.move(direction, steps);
        return;
    }

    this->_player.move(direction, steps);
}

bool World::canCover(int direction, int steps)
{
    int x = _player.getPosX(),y = _player.getPosY()+1;
    if(direction == 1)--y;
    if(direction == 2)++y;
    if(direction == 3)--x;
    if(direction == 4)++x;
    auto it = _objs.begin();
    auto the_it = it;
    bool g = 0;
    while(it!=_objs.end())
    {
        if(!it->canCover()&&!it->canEat())
        {
            int x1 = it->getPosX(),x2 = x1 + it->getWidth();
            int y1 = it->getPosY(),y2 = y1 + it->getHeight();
            if(x1<=x&&x<x2&&y1<=y&&y<y2)
            {
                the_it = it;
                g = 1;
                break;
            }
        }
        ++it;
    }
    if(g)
    {
        return false;
    }
    return true;
}

bool World::canEat(int direction, int steps)
{
    int x = _player.getPosX(),y = _player.getPosY()+1;
    if(direction == 1)y--;
    if(direction == 2)y++;
    if(direction == 3)x--;
    if(direction == 4)x++;
    auto it = _objs.begin();
   // auto the_it = it;
    bool g = 0;
    while(it!=_objs.end())
    {
        if(it->canEat())
        {
            int x1 = it->getPosX(),x2 = x1 + it->getWidth();
            int y1 = it->getPosY(),y2 = y1 + it->getHeight();
            if(x1<=x&&x<x2&&y1<=y&&y<y2)
            {
       //         the_it = it;
                g = 1;
                break;
            }
        }
        ++it;
    }
    if(g)
    {
        _objs.erase(it);
        return false;
    }
    return true;
}

bool World::ifDead(int direction, int steps)
{
    int x = _player.getPosX(),y = _player.getPosY()+1;
    if(direction == 1)y--;
    if(direction == 2)y++;
    if(direction == 3)x--;
    if(direction == 4)x++;
    auto it = _objs.begin();
    bool g = 0;
    while(it!=_objs.end())
    {
        if(it->ifDeadly())
        {
            int x1 = it->getPosX(),x2 = x1 + it->getWidth();
            int y1 = it->getPosY(),y2 = y1 + it->getHeight();
            if(x1<=x&&x<x2&&y1<=y&&y<y2)
            {
                g = 1;
                break;
            }
        }
        ++it;
    }
    if(g)
    {
        return true;
    }
    return false;
}
