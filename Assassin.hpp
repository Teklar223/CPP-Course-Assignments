#pragma once
#include "Player.hpp"

namespace coup{
    class Assassin
    {
    public:
        Assassin();
        ~Assassin();

        void action(Player player); //assasinates player for 3 coins instead of 7
    };
}