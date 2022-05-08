#include "Game.hpp"

namespace coup
{
    Game::Game()
    {
        this->_turn = 0;
        this->_winner = "undefiend";
    }

    void Game::addPlayer(string name)
    {
        this->_players.push_back(std::move(name));
    }

    void Game::removePlayer(string const &name)
    {
        for (std::vector<string>::iterator it = this->_players.begin(); it != this->_players.end(); )
        {
            if (*it == name)
            {
                this->_players.erase(it);
                it = this->_players.end(); //efectively breaking.
            }
        }
    }

    vector<string> Game::players() const
    {
        return this->_players;
    }

    string Game::turn() const
    {
        return this->_players.at(this->_turn);
    }

    string Game::winner() const
    {
        if (this->_winner == "undefined")
        {
            throw std::invalid_argument{"Game is not over yet!"};
        }

        return this->_winner;
    }

    void Game::inc_turn()
    {
        unsigned int mod = this->_players.size();
        this->_turn = (this->_turn + 1) % mod;
    }
}