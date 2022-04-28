#include "Game.hpp"

namespace coup
{
    Game::Game()
    {
        this->_turn = 0;
        this->_winner = "undefiend";
    }

    Game::~Game()
    {
    }

    void Game::addPlayer(Player const &p)
    {
        this->_players.push_back(p);
    }

    vector<string> Game::players()
    {
        vector<string> v;
        for (unsigned int i = 0; i < this->_players.size(); i++)
        {
            v.push_back(this->_players.at(i).name());
        }
        return v;
    }
    int Game::turn() const
    {
        return this->_turn;
    }
    string Game::winner()
    {
        return this->_winner;
    }
}