#include "Game.hpp"

namespace coup
{
    /* P L A Y E R */

    bool Player::getAction() const
    {
        return this->_action;
    }

    bool Player::getForaid() const
    {
        return this->_foraid;
    }

    void Player::setAction(bool val)
    {
        this->_action = val;
    }

    void Player::setForaid(bool val)
    {
        this->_foraid = val;
    }

    void Player::addCoins(unsigned int num)
    {
        this->_coins += num;
    }

    void Player::subCoins(unsigned int num)
    {
        this->_coins -= num;
    }

    void Player::init_turn()
    {
        this->_action = false;
        this->_foraid = false;
        this->assassinated.clear();
        this->stolefrom.clear();
    }

    bool Player::getDefeated() const
    {
        return this->defeated;
    }

    void Player::setDefeated(bool val)
    {
        this->defeated = val;
    }

    void Player::income()
    {
        this->init_turn();
        this->_coins += 1;
        (*this->_game).inc_turn();
    }

    void Player::foreign_aid()
    {
        this->init_turn();
        this->_coins += 2;
        this->_foraid = true;
        (*this->_game).inc_turn();
    }

    void Player::coup(Player &player)
    {

        this->init_turn();

        if (this->_coins >= COUP_COINS)
        {
            this->_coins -= COUP_COINS;
            player.setDefeated(true);
        }
        else
        {
            throw invalid_argument{"Need at least 7 coins to initiate a coup!"};
        }

        (*this->_game).inc_turn();
    }

    string Player::name() const
    {
        return this->_name;
    }

    string Player::role() const
    {
        return this->_role;
    }

    unsigned int Player::coins() const
    {
        return this->_coins;
    }

    Player &Player::getStolenfrom()
    {
        return this->stolefrom.at(1);
    }

    void Player::clearStolenfrom()
    {
        this->stolefrom.clear();
    }

    Player &Player::getAssassinated()
    {
        return this->assassinated.at(1);
    }

    void Player::clearAssassinated()
    {
        this->assassinated.clear();
    }

    /* G A M E */

    Game::Game()
    {
        this->_turn = 0;
        this->_defeatedPlayers = 0;
        this->_activePlayers = 0;
        this->_winner = "undefiend";
    }

    void Game::addPlayer(Player *player)
    {
        if (this->_players.size() < MAX_PLAYERS)
        {
            this->_players.push_back(player);
        }
        else
        {
            throw invalid_argument{"A maximum of 6 players per game is allowed."};
        }
    }

    /*
    void Game::removePlayer(string const &name)
    {
        TODO:
        for (std::vector<string>::iterator it = this->_players.begin(); it != this->_players.end(); )
        {
            if (*it == name)
            {
                this->_players.erase(it);
                it = this->_players.end(); //efectively breaking.
            }
        }
    }
    */

    vector<string> Game::players() const
    {
        // TODO:return this->_players;
        vector<string> ans;
        for (unsigned int i = 0; i < this->_players.size(); i++)
        {
            if (!(*this->_players.at(i)).getDefeated())
            {
                // ans.push_back(this->_players.at(i).name());
                ans.push_back((*this->_players.at(i)).name());
            }
        }
        return ans;
    }

    string Game::turn() const
    {
        return (*this->_players.at(this->_turn)).name();
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
        /*
        if (mod == 0){
            mod++;
        }
        */
        unsigned int i = 0;
        while ((*this->_players.at(this->_turn)).getDefeated()) // will happen at most 6 times
        {
            if (i == MAX_PLAYERS)
            { // brute forcing that ensures this breaks.
                if (!(*this->_players.at(i)).getDefeated())
                {
                    this->_winner = (*this->_players.at(i)).name();
                }
                else
                {
                    throw invalid_argument{"HOW IS EVERYONE DEFEATED????????"};
                }
            }
            this->_turn = (this->_turn + 1) % mod;
        }
    }
}