#pragma once
#include "Game.hpp"

namespace coup
{
    class Ambassador : public Player
    {
    public:
        Ambassador(Game &game, string name);

        void transfer(Player &player1, Player &player2); // takes coin from player1 and gives it to player2
        void block(Player &player);
    };
}