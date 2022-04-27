#pragma once
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Assassin.hpp"
#include "Duke.hpp"
#include <string>
using std::string;

namespace coup
{

    class Game
    {
    private:
        vector<Player> _players;
        int _turn;
        string _winner;

        void addPlayer(Player p){
            this->_players.push_back(p);
        }

    public:
        Game();

        ~Game();

        string players();
        int turn();
        string winner();
    };
}