#pragma once
#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Duke : public Player
    {
    private:
        int _coins;
        string _role;
        string _name;
    public:
        Duke(Game const &game, string name);
        ~Duke();

        void tax(); //takes three coins
    };
}