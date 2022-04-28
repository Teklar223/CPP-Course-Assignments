#include "Ambassador.hpp"

namespace coup
{

    Ambassador::Ambassador(Game const &game, string name)
    {
        this->_role = "Ambassador";
        this->_coins = 0;
        this->_name = std::move(name);
    }


    Ambassador::~Ambassador()
    {
    }

    void Ambassador::transfer(Player const &player1, Player const &player2)
    {
        
    }
}