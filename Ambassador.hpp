#pragma once
#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Ambassador : public Player
    {
    private:
        int _coins;
        string _role;
        string _name;
    public:
        Ambassador(Game const &game, string name);
        ~Ambassador();

        void transfer(Player const &player1, Player const &player2); //takes coin from player1 and gives it to player2
    };
}