#pragma once
#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Assassin : public Player
    {
    private:
        int _coins;
        string _role;
        string _name;
    public:
        Assassin(Game const &game, string name);
        ~Assassin();
    };
}