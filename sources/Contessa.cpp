#include "Contessa.hpp"

namespace coup
{

    Contessa::Contessa(Game &game, string name)
    {
        this->_coins = 0;
        this->_name = std::move(name);
        this->_action = false;
        this->_foraid = false;
        this->_game = &game;
        this->_role = "Contessa";
        this->defeated = false;
        game.addPlayer(this);
    }

    void Contessa::block(Player &player)
    {
        this->init_turn("block");
        if (player.role() == "Assassin")
        {
            if (player.getAction())
            {
                player.setAction();
                //TODO: player.addCoins(3);
                player.getAssassinated().setDefeated(false);
                player.clearAssassinated();
            }
            else
            {
                throw std::invalid_argument{"can only block an assassin if he killed a player this round."};
            }
        }
        else
        {
            throw std::invalid_argument{"The Contessa can only block assassins."};
        }
        this->blocked = true;
        //TODO: (*this->_game).inc_turn();
    }
}