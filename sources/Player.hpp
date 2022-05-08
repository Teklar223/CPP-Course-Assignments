#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include "Game.hpp"
#include <map>
using std::string;

namespace coup
{

    class Player
    {
    protected:
        Game _game;
        unsigned int _coins;
        string _name;
        bool _action;
        bool _foraid;
        string _role;
        bool defeated;
        std::map<int, Player &> assassinated;
        std::map<int, Player &> stolefrom;
        void init_turn();

    public:
        bool getDefeated() const;
        void setDefeated(bool val = false);
        bool getAction() const;
        void setAction(bool val = false);
        bool getForaid() const;
        void setForaid(bool val = false);
        void cancelForeignAid();
        void addCoins(unsigned int num);
        void subCoins(unsigned int num);
        void income();
        void foreign_aid();
        void coup(Player &player);
        string name() const;
        string role() const;
        unsigned int coins() const;
        Player &getAssassinated();
        void clearAssassinated();
        Player &getStolenfrom();
        void clearStolenfrom();
    };
}