#include "icon.h"
#include<iostream>
int ICON::GRID_SIZE = 66;


pair<string,ICON> pairArray[] =
{
    make_pair("gaoda",ICON("gaoda",0,0, 1, 1)),
    make_pair("bullet",ICON("bullet",0,0, 1, 1)),
    make_pair("enemy",ICON("enemy",0,0, 1, 1)),
    make_pair("tools",ICON("tools",0,0, 1, 1)),
    make_pair("dete",ICON("dete",0,0, 1, 1)),
    make_pair("gun",ICON("gun",0,0, 1, 1)),
    make_pair("transport",ICON("transport",0,0, 1, 1)),
    make_pair("direction",ICON("direction",0,0, 1, 1)),
    make_pair("blood",ICON("blood",0,0, 1, 1)),
    make_pair("barrier",ICON("barrier",0,0, 1, 1)),
    make_pair("key",ICON("key",0,0, 1, 1))
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type)
{
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end())
    {

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}
