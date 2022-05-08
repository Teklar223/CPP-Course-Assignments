#include "Captain.hpp"

namespace coup
{
    Captain::Captain(Game &game, string name)
    {
        game.addPlayer(name);
        this->_coins = 0;
        this->_name = std::move(name);
        this->_action = false;
        this->_foraid = false;
        this->_game = game;
        this->_role = "Captain";
        this->defeated = false;
    }

    void Captain::steal(Player &player)
    {
        this->init_turn();
        if (player.coins() >= 2)
        {
            player.subCoins(2);
            this->stolefrom.insert({1, player});
            this->_coins += 2;
        }
        else
        {
            throw std::invalid_argument{"player has less than 2 coins..."};
        }
        this->_game.inc_turn();
    }

    void Captain::block(Player &player)
    {
        this->init_turn();
        if (player.role() == "Captain")
        {
            if (player.getAction())
            {
                player.setAction();
                player.subCoins(2);
                player.getStolenfrom().addCoins(2);
                player.clearStolenfrom();
            }
            else
            {
                throw std::invalid_argument{"can only block a captain if he stole this round."};
            }
        }
        else
        {
            throw std::invalid_argument{"can only block other captains."};
        }
        this->_game.inc_turn();
    }
}