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
        if((*this->_game).turn() != this->name()){
            if ((*(*this->_game).getCurrentPlayer()).getBlocked())
            {
                (*this->_game).inc_turn();
            }
        }

        if (!(*this->_game).has_started())
        {
            if ((*this->_game).players().size() > 1)
            {
                (*this->_game).start_game();
            }
            else
            {
                throw invalid_argument{"cant start game with just one player... waiting for more!"};
            }
        }

        if (!(*this->_game).is_enough_players())
        {
            throw invalid_argument{"need at least 2 players to play the game!"};
        }

        if ((*this->_game).is_game_over())
        {
            throw invalid_argument{"A winner was already declared!"};
        }

        if ((*this->_game).turn() == this->_name)
        {
            if (this->_coins >= MUST_COUP)
            {
                throw invalid_argument{"A player with at least 10 coins must coup!"};
            }
            this->_action = false;
            this->_foraid = false;
            this->blocked = false;
            this->assassinated.clear();
            this->stolefrom.clear();
        }
        else
        {
            throw invalid_argument{"Not this players turn yet!!!"};
        }
    }

    void Player::init_turn_free_action()
    {
        if (!(*this->_game).has_started())
        {
            if ((*this->_game).players().size() > 1)
            {
                (*this->_game).start_game();
            }
            else
            {
                throw invalid_argument{"cant start game with just one player... waiting for more!"};
            }
        }

        if (!(*this->_game).is_enough_players())
        {
            throw invalid_argument{"need at least 2 players to play the game!"};
        }

        if ((*this->_game).is_game_over())
        {
            throw invalid_argument{"A winner was already declared!"};
        }

        if ((*this->_game).turn() == this->_name)
        {
            this->_action = false;
            this->_foraid = false;
            this->blocked = false;
            this->assassinated.clear();
            this->stolefrom.clear();
        }
        else
        {
            /*
            if ((*(*this->_game).getCurrentPlayer()).getBlocked())
            {
                (*this->_game).inc_turn();
                this->init_turn_free_action();
            }*/
            throw invalid_argument{"Not this players turn yet!!!"};
        }
    }

    bool Player::getDefeated() const
    {
        return this->defeated;
    }

    void Player::setDefeated(bool val)
    {
        this->defeated = val;
        if (val)
        {
            (*this->_game).inc_defeated();
        }
        else
        {
            (*this->_game).dec_defeated();
        }

        if ((*this->_game).players().size() == 1)
        {
            (*this->_game).declareWinner((*this->_game).players().at(0));
        }
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

        this->init_turn_free_action();

        if (player.getDefeated())
        {
            throw invalid_argument{"That player is already out of the game!"};
        }

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

    bool Player::getBlocked() const
    {
        return this->blocked;
    }

    void Player::setBlocked(bool val)
    {
        this->blocked = val;
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
        this->_started = false;
        this->_winner = "_";
    }

    void Game::addPlayer(Player *player)
    {
        if (this->_started)
        {
            throw invalid_argument{"cant add a player to an ongoing match!"};
        }

        if (this->_players.size() < MAX_PLAYERS)
        {
            this->_players.push_back(player);
        }
        else
        {
            throw invalid_argument{"A maximum of 6 players per game is allowed."};
        }
    }

    vector<string> Game::players() const
    {
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
        if (this->_winner == "_")
        {
            throw invalid_argument{"Game is not over yet!"};
        }

        return this->_winner;
    }

    void Game::inc_turn()
    {
        unsigned int mod = this->_players.size();
        this->_turn = (this->_turn + 1) % mod;

        while ((*this->_players.at(this->_turn)).getDefeated()) // will happen at most 6 times, getDefeated return true if player is defeated.
        {
            this->_turn = (this->_turn + 1) % mod;
        }
    }

    void Game::declareWinner(string const &name)
    {
        this->_winner = name;
    }

    unsigned int Game::getDefeated() const
    {
        return this->_defeatedPlayers;
    }

    void Game::inc_defeated()
    {
        this->_defeatedPlayers += 1;
    }
    void Game::dec_defeated()
    {
        this->_defeatedPlayers -= 1;
    }

    bool Game::is_game_over() const
    {
        bool ans = true;

        if (this->_winner != "_")
        {
            return ans;
        }

        return !ans;
    }

    bool Game::is_enough_players() const
    {
        bool ans = true;
        if (this->_players.size() == 1)
        {
            return !ans;
        }

        return ans;
    }

    bool Game::has_started() const
    {
        return this->_started;
    }

    void Game::start_game()
    {
        this->_started = true;
    }

    Player *Game::getCurrentPlayer() const
    {
        return this->_players.at(this->_turn);
    }
}