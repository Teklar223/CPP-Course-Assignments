#include "Duke.hpp"

namespace coup
{

    Duke::Duke(Game &game, string name)
    {
        this->_coins = 0;
        this->_name = std::move(name);
        this->_action = false;
        this->_foraid = false;
        this->_game = &game;
        this->_role = "Duke";
        this->defeated = false;
        game.addPlayer(this);
    }

    void Duke::tax()
    {
        this->init_turn("ncob");
        this->_coins += 3;
        (*this->_game).inc_turn();
    }

    void Duke::block(Player &player){
        if(player.getForaid()){
            player.setForaid();
            player.subCoins(2);
        }
        else{
            throw std::invalid_argument{"cant block that player since he did not use foreign aid this round."};
        }
        this->blocked = true;
    }
}