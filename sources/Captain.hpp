#pragma once
#include "Game.hpp"

namespace coup
{
    class Captain : public Player
    {
    public:
        Captain(Game &game, string name);

        void steal(Player &player); // steals 2 coins from the player and gives it to the Captain.
        void block(Player &player); // can only block other Captains!
    };
}