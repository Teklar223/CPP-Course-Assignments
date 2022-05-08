#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

namespace coup
{
    class Game
    {
    private:
        vector<string> _players;
        unsigned int _turn;
        string _winner;
        
    public:
        Game();

        void inc_turn();
        void addPlayer(string name);
        void removePlayer(string const &name);
        vector<string> players() const;
        string turn() const;
        string winner()  const;
    };
}