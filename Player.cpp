#include "Player.hpp"

namespace coup
{
    Player::Player(){
        this->_coins = 0;
        this->_role = "undefiend";
    }

    Player::~Player(){

    }

    void Player::income(){

    }
    void Player::foreign_aid(){

    }
    void Player::coup(){

    }

    string Player::role(){
        return this->_role;
    }
    int Player::coins(){
        return this->_coins;
    }
}