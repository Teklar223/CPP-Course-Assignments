#pragma once
#include "Game.hpp"

namespace coup
{
    class Assassin : public Player
    {
    public:
        Assassin(Game &game, string name);
        void coup(Player &player); // overloads from parent class, this takes 3 coins instead of 7.
    };
}