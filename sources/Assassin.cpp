#include "Assassin.hpp"

namespace coup
{
    Assassin::Assassin(Game &game, string name)
    {
        this->_coins = 0;
        this->_name = std::move(name);
        this->_action = false;
        this->_foraid = false;
        this->_game = &game;
        this->_role = "Assassin";
        this->defeated = false;
        game.addPlayer(this);
    }

    void Assassin::coup(Player &player)
    {
        this->init_turn();
        if(this->_coins >= 3){
            this->_action = true;
            this->_coins -= 3;
            player.setDefeated(true);
            this->assassinated.insert({1,player});
        }
        else{
            throw std::invalid_argument{"Assassin needs at least 3 coins to coup."};
        }
        (*this->_game).inc_turn();
    }
}