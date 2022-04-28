#pragma once
#include "Player.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

namespace coup
{

    class Game
    {
    private:
        vector<Player> _players;
        int _turn;
        string _winner;
    public:
        Game();

        ~Game();

        void addPlayer(Player const &p);
        vector<string> players();
        int turn() const;
        string winner();
    };
}