#pragma once
#include "Player.hpp"

namespace coup{
    class Captain
    {
    public:
        Captain();
        ~Captain();

        void action(Player player); //steals 2 coins from the player and gives it to the Captain
    };
}