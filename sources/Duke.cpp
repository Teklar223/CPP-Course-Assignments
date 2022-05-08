#include "Duke.hpp"
#include <iostream>

namespace coup
{

    Duke::Duke(Game &game, string name)
    {
        game.addPlayer(name);
        this->_coins = 0;
        this->_name = std::move(name);
        this->_action = false;
        this->_foraid = false;
        this->_game = game;
        this->_role = "Duke";
        this->defeated = false;
    }

    void Duke::tax()
    {
        this->init_turn();
        this->_coins += 3;
        this->_game.inc_turn();
    }

    void Duke::block(Player &player){
        this->init_turn();
        if(player.getForaid()){
            player.setForaid();
            player.subCoins(2);
        }
        else{
            throw std::invalid_argument{"cant block that player since he did not use foreign aid this round."};
        }
        this->_game.inc_turn();
    }
}