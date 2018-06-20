#include "barrier.h"
#include <QMediaPlayer>
extern string path;

void Barrier::initBarrier(int index){
    if(index==1){
        this->_hpReduce_hit=0;
    }
    else if(index==2){
        this->_hpReduce_hit=50;
    }
    else if(index==3||index==4){
        this->_hpReduce_hit=100;
    }
    else if(index==5){
        this->_hpReduce_hit=35;
    }
}



