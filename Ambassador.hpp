#pragma once
#include "Player.hpp"

namespace coup{
    class Ambassador
    {
    public:
        Ambassador();
        ~Ambassador();

        void action(Player player1, Player player2); //takes coin from player1 and gives it to player2
    };
}