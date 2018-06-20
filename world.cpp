#include "world.h"
#include "icon.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include<bullet.h>
#include "blood.h"
#include "barrier.h"
#include "gun.h"
#include "key.h"

#include <QMediaPlayer>
using namespace std;

extern string path;
extern int _gundamChoose;
QMediaPlayer * player_background = new QMediaPlayer;
QMediaPlayer * player = new QMediaPlayer;

void World::initWorld(string mapFile){
    this->_victory=false;

    string line,s1;
    stringstream ss1;
    int x1,y1,indexfirst,indexbullet,hp,money;
    ifstream ifs(mapFile);

    getline(ifs,line);
    ss1 << line;

    ss1 >> s1 >> x1 >> y1>>indexfirst>>indexbullet>>hp>>money;
    if(s1=="gaoda")
    {
        _player.initObj("gaoda",_gundamChoose);
        _player.initPlayer();
        _player.setPosX(x1);
        _player.setPosY(y1);
        _player.setHp(hp);
        _player.setMoney(money);
        _player.setBulletIndex(_gundamChoose);
    }
    else if(s1=="gaodaa")
    {   int k;
        ss1>>k;
        _gundamChoose=k;
        _player.initObj("gaoda",indexfirst);
        _player.initPlayer();
        _player.setPosX(x1);
        _player.setPosY(y1);
        _player.setHp(hp);
        _player.setMoney(money);
        _player.setBulletIndex(indexbullet);
    }

    string the_path=path+"music\\background.mp3";
    const char* path1=the_path.c_str();
    player_background->setMedia(QUrl::fromLocalFile(path1));
    player_background->setVolume(50);
    player_background->play();

    while(1)
    {
        string s;
        int x,y;
        stringstream ss;
        getline(ifs,line);
        if(ifs.fail())return;
        ss << line;
        ss >> s >> x >> y>>indexfirst;
        if(s.size()==0)return;

        if(s=="enemy"){
            Enemy * obj1=new Enemy;
            obj1->initObj(s,indexfirst);
            obj1->initEnemy(indexfirst);
            obj1->setPosX(x);
            obj1->setPosY(y);
            _objs.push_back(obj1);
        }
        else if(s=="bullet"){
            Bullet * obj1=new Bullet;
            obj1->initObj(s,indexfirst);
            obj1->initBullet(indexfirst);
            obj1->setPosX(x);
            obj1->setPosY(y);
            _objs.push_back(obj1);
        }
        else if(s=="blood"){
            Blood * obj1=new Blood;
            obj1->initObj(s,indexfirst);
            obj1->initBlood(indexfirst);
            obj1->setPosX(x);
            obj1->setPosY(y);
            _objs.push_back(obj1);
        }
        else if(s=="barrier"){
            Barrier *obj1 = new Barrier;
            obj1->initObj(s,indexfirst);
            obj1->initBarrier(indexfirst);
            obj1->setPosX(x);
            obj1->setPosY(y);
            _objs.push_back(obj1);
        }
        else if(s=="gun"){
            Gun *obj1 = new Gun;
            obj1->initObj(s,indexfirst);
            obj1->initGun(indexfirst);
            obj1->setPosX(x);
            obj1->setPosY(y);
            _objs.push_back(obj1);
        }
        else if(s=="key"){
            Key *obj1 = new Key;
            obj1->initObj(s,indexfirst);
            obj1->initKey();
            obj1->setPosX(x);
            obj1->setPosY(y);
            _objs.push_back(obj1);
        }
        else{
            RPGObj * obj1 = new RPGObj;
            obj1->initObj(s,indexfirst);
            obj1->setPosX(x);
            obj1->setPosY(y);
            _objs.push_back(obj1);
        }
    }
}

void World::save(string mapFile)
{
    string line,s1;
    stringstream ss1;

    ofstream ifs(mapFile,fstream::out);
    ifs << "gaodaa "<< _player.getPosX()<<" "<<_player.getPosY()<<" "
        <<_player.getIndex()<<" "<<_player.getBulletIndex()<<" "
        <<_player.getHp()<<" "<<_player.getMoney()<<_gundamChoose<<endl;
    auto it = _objs.begin();
    for(;it != _objs.end();++it)
    {
        if((*it)->getObjType()=="bullet")continue;
        ifs << (*it)->getObjType()<<" "<<(*it)->getPosX()<<" "<<(*it)->getPosY()<<" "
            <<(*it)->getIndex()<<endl;
    }
}

void World::destroy()
{
    auto it=_objs.begin();
    while(it!=_objs.end()){
        delete(*it);
        it++;
    }
    _objs.clear();

    player_background->stop();

}
void World::shootBullet(int x, int y,int direction,int index,int status){
    //status为0表示玩家发射，为1表示敌人发射
    if(direction == 0)--y;
    if(direction == 1)++x;
    if(direction == 2)++y;
    if(direction == 3)--x;

    Bullet * obj1=new Bullet;
    obj1->initObj("bullet",index);
    obj1->setDirection(direction);
    obj1->setPosX(x);
    obj1->setPosY(y);
    obj1->initBullet(status);
    _objs.push_back(obj1);
}

void World::show(QPainter * painter){
    vector<RPGObj*>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it)->show(painter);
    }
    this->_player.show(painter);
}

void World::handleMonsterMove(){
    int i=_objs.size();
    for(auto it = _objs.begin();i>0;++it,i--)
    {
        if((*it)->getObjType()=="enemy")
        {
            int ra=0;
            if(_gundamChoose==4)
            {
                if((*it)->getPosX()<=_player.getPosX()&&(*it)->getPosY()>=_player.getPosY())
                {
                    ra = rand()%2;
                }
                else if((*it)->getPosX()<=_player.getPosX()&&(*it)->getPosY()<=_player.getPosY())
                {
                    ra = rand()%2+1;
                }
                else if((*it)->getPosX()>=_player.getPosX()&&(*it)->getPosY()<=_player.getPosY())
                {
                    ra = rand()%2+2;
                }
                else if((*it)->getPosX()>=_player.getPosX()&&(*it)->getPosY()>=_player.getPosY())
                {
                    int ram = rand()%2;
                    if(ram==0)
                    {
                        ra=0;
                    }
                    else
                    {
                        ra=3;
                    }
                }
            }
            else
            {
                ra = rand()%4;
            }
            if(!canCover(ra,1,(it)))continue;
            if(i%2==0)
            {
                shootBullet((*it)->getPosX(),(*it)->getPosY(),ra,
                                     (*it)->getBulletIndex(),1);
            }
            else   (*it)->move(ra, 1);
        }
    }
}
void World::handleBulletMove(){
    for(auto it = _objs.begin();it != _objs.end();++it)
    {
        if((*it)->getObjType()=="bullet")
        {
            int ra = (*it)->getDirection();

            if(!canCover(ra,1,(it))){
                continue;
            }
            int posx=(*it)->getPosX();
            int posy=(*it)->getPosY();
            if(posx<=0||posx>=28||posy>=15||posy<=0) {(*it)->setHp(-1);}
            (*it)->move(ra, 1);

        }
    }
}

bool World::canCover(int direction, int steps,vector<RPGObj*>::iterator k)
{//这是针对除了玩家以外的万物
    int x = (*k)->getPosX(),y = (*k)->getPosY();
    if(direction == 0)--y;
    if(direction == 1)++x;
    if(direction == 2)++y;
    if(direction == 3)--x;
    if(x==_player.getPosX()&&y==_player.getPosY())
    {
        if ((*k)->getObjType()=="bullet" )
        {
            (*k)->setHp(-1);
            _player.setHp(_player.getHp()-(*k)->get_attack_player());
            string the_path=path+"music\\hit.mp3";
            const char * path1=the_path.c_str();
            player->setMedia(QUrl::fromLocalFile(path1));
            player->setVolume(100);
            player->play();
            //if(player->state()==0)delete player;
        }
        return false;
    }
    if((*k)->getPosX()==_player.getPosX()&&
            (*k)->getPosY()==_player.getPosY()&&
            (*k)->getObjType()=="bullet")
    {
        _player.setHp(_player.getHp()-(*k)->get_attack_player());
        string the_path=path+"music\\hit.mp3";
        const char * path1=the_path.c_str();
        player->setMedia(QUrl::fromLocalFile(path1));
        player->setVolume(100);
        player->play();
        if(player->state()==0)delete player;
        return false;
    }
    auto it = _objs.begin();
    for(;it != _objs.end();++it)
    {
        int x1 = (*it)->getPosX();
        int y1 = (*it)->getPosY();
        if(it == k)continue;

        if(x==x1&&y==y1&&(*it)->getObjType()=="enemy"&&(*k)->getObjType()=="bullet")
        {
            (*it)->setHp( (*it)->getHp()-(*it)->get_attack_enemy());
            (*k)->setHp(-1);
            return false;
        }
        if((*k)->getPosX()==(*it)->getPosX()&&
                (*k)->getPosY()==(*it)->getPosY()&&
                (*k)->getObjType()=="bullet"&&
                (*it)->getObjType()=="enemy")
        {
            (*it)->setHp( (*it)->getHp()-(*it)->get_attack_enemy());
            (*k)->setHp( -1);
            return false;
        }
        if((*k)->getPosX()==(*it)->getPosX()&&
                (*k)->getPosY()==(*it)->getPosY()&&
                (*k)->getObjType()=="bullet"&&
                (*it)->getObjType()=="barrier")
        {
            (*it)->setHp( (*it)->getHp()-(*it)->getHpReduce_hit());
            (*k)->setHp( -1);

             return false;
        }
        if(x==x1&&y==y1&&(*it)->getObjType()=="bullet"&&(*k)->getObjType()=="enemy")
        {

            (*k)->setHp( (*k)->getHp()-(*it)->get_attack_enemy());
            (*it)->setHp( -1);
            return false;
        }
        if(x==x1&&y==y1&&(*it)->getObjType()=="barrier"&&(*k)->getObjType()=="bullet")
        {

            (*it)->setHp( (*it)->getHp()-(*it)->getHpReduce_hit());
            (*k)->setHp( -1);
            return false;
        }

        if(x==x1&&y==y1&&(*k)->getObjType()=="bullet"){
            if((*it)->getObjType()=="bullet")return true;
            else if((*it)->canEat())return true;
            if(!(*it)->canCover())(*k)->setHp( -1);
            return (*it)->canCover();
        }
        if(x==x1&&y==y1){
            return (*it)->canCover();
        }

    }
    return true;
}
bool World::canCover(int direction, int steps)
{//针对玩家的cancover
    int x = _player.getPosX(),y = _player.getPosY();
    if(direction == 0)--y;//上右下左
    if(direction == 1)++x;
    if(direction == 2)++y;
    if(direction == 3)--x;
    auto it = _objs.begin();
    bool g = 0;
    while(it!=_objs.end())
    {
        int x1 = (*it)->getPosX();
        int y1 = (*it)->getPosY();
        if(!(*it)->canCover()&&x==x1&&y==y1)
        {
            if ((*it)->getObjType()=="bullet" ) {
                (*it)->setHp(-1);
                _player.setHp(_player.getHp()-(*it)->get_attack_player());

                string the_path=path+"music\\hit.mp3";
                const char * path1=the_path.c_str();
                player->setMedia(QUrl::fromLocalFile(path1));
                player->setVolume(100);
                player->play();
                if(player->state()==0)delete player;
            }

            if ((*it)->getObjType()=="enemy" ) {
                cout<<"hp"<<_player.getHp()<<endl;
                _player.setHp(_player.getHp()-10);
                cout<<"hp"<<_player.getHp()<<endl;

            }
            cout<<(*it)->getObjType()<<endl;
            if ((*it)->getObjType()=="blood" )
            {
                this->_player.setHp(_player.getHp()+(*it)->get_add_hp());
                (*it)->onErase();
                auto im=*it;
                _objs.erase(it);
                delete im;
                return true;
            }
            if ((*it)->getObjType()=="gun" )
            {
                this->_player.setBulletIndex((*it)->getBulletChangeIndex());
                (*it)->onErase();
                auto im=*it;
                _objs.erase(it);
                delete im;
                return true;
            }
            if ((*it)->getObjType()=="key" )
            {
                Player::addKeyAmount();
                (*it)->onErase();
                auto im=*it;
                _objs.erase(it);
                delete im;
                if(Player::getKeyAmount()==3){
                   this->_victory=true;
                   cout<<"victory!"<<endl;
                }
                return true;
            }

                g = 1;

                break;

        }
        ++it;
    }
    if(g)
    {
        return false;
    }
    return true;
}
void World::handlePlayerMove(int direction, int steps)
{
    _player.setDirection(direction);
    if(!canCover(direction,steps))return;
    this->_player.move(direction, steps);
        return;
}

void World::erase(){
    vector<RPGObj *>::iterator it=_objs.begin();

    while(it!=_objs.end()){
        while(it!=_objs.end()){
            if ((*it)->getHp()<0) {
                if((*it)->getObjType()=="enemy"){
                    _player.setMoney(_player.getMoney()+(*it)->getAddMoney());
                }

                (*it)->onErase();
                auto im=*it;
                _objs.erase(it);
                delete im;
                break;
            }
            it++;
        }
    }
}



