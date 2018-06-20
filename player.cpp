#include "player.h"

int Player::_key_amount=0;

void Player::setMoney(int money){
    if(money>500)money=500;
    else this->_money=money;
}

void Player::move(int direction, int steps){
    switch (direction){
        case 2:
            if(this->_pos_y<25)
            this->_pos_y += steps;
            break;
        case 0:
            if(this->_pos_y>0)
            this->_pos_y -= steps;
            break;
        case 3:
            if(this->_pos_x>0 )
            this->_pos_x -= steps;
            break;
        case 1:
            if(this->_pos_x<28 )
            this->_pos_x += steps;
            break;
    }
}

