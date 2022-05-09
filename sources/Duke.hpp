#pragma once
#include "Game.hpp"

namespace coup{
    class Duke : public Player
    {
    public:
        Duke(Game &game, string name);

        void tax(); //takes three coins
        void block(Player &player);
    };
}