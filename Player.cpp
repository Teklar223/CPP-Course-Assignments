#include "Player.hpp"

namespace coup
{
    Player::Player(string role, string name){
        this->_coins = 0;
        this->_role = std::move(role);
        this->_name = std::move(name);
    }

    Player::~Player(){

    }

    void Player::income(){

    }
    void Player::foreign_aid(){

    }
    void Player::coup(Player const &player){

    }


    string Player::name() const{
        return this->_name;
    }
    string Player::role() const{
        return this->_role;
    }
    int Player::coins() const{
        return this->_coins;
    }
    void Player::block(Player const &player){
        
    }
}