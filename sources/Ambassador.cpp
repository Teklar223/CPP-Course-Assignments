#include "Ambassador.hpp"

namespace coup
{
    Ambassador::Ambassador(Game &game, string name)
    {
        this->_coins = 0;
        this->_name = std::move(name);
        this->_action = false;
        this->_foraid = false;
        this->_game = &game;
        this->_role = "Ambassador";
        this->defeated = false;
        game.addPlayer(this);
    }

    void Ambassador::transfer(Player &player1, Player &player2)
    {
        this->init_turn();
        if (player1.coins() >=1){
            player1.subCoins(1);
            player2.addCoins(1);
        }
        else{
            throw std::invalid_argument{"player has no coins to transfer..."};
        }
        (*this->_game).inc_turn();
    }

    void Ambassador::block(Player &player)
    {
        this->init_turn_free_action();
        if (player.role() == "Captain"){
            if (player.getAction()){
                player.setAction();
                player.subCoins(2);
                player.getStolenfrom().addCoins(2);
                player.clearStolenfrom();
            }
            else{
                throw std::invalid_argument{"can only block a captain if he stole this round."};
            }
        }
        else{
            throw std::invalid_argument{"can only block captains."};
        }
        (*this->_game).inc_turn();
    }
}