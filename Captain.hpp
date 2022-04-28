#pragma once
#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Captain : public Player
    {
    private:
        int _coins;
        string _role;
        string _name;
    public:
        Captain(Game const &game, string name);
        ~Captain();

        void steal(Player const &player); //steals 2 coins from the player and gives it to the Captain
    };
}