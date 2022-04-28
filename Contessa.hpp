#pragma once
#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Contessa : public Player
    {
    private:
        int _coins;
        string _role;
        string _name;
    public:
        Contessa(Game const &game, string name);
        ~Contessa();
    };
}