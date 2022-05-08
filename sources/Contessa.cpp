#include "Contessa.hpp"

namespace coup
{

    Contessa::Contessa(Game &game, string name)
    {
        game.addPlayer(name);
        this->_coins = 0;
        this->_name = std::move(name);
        this->_action = false;
        this->_foraid = false;
        this->_game = game;
        this->_role = "Contessa";
        this->defeated = false;
    }

    void Contessa::block(Player &player)
    {
        this->init_turn();
        if (player.role() == "Assassin")
        {
            if (player.getAction())
            {
                player.setAction();
                player.addCoins(3);
                player.getAssassinated().setDefeated(false);
                this->_game.addPlayer(player.getAssassinated().name());
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
        this->_game.inc_turn();
    }
}