#include "Player.hpp"
#include "Game.hpp"
using namespace std;
constexpr int COUP_COINS = 7;

namespace coup
{
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
        this->_game.inc_turn();
    }

    void Player::foreign_aid()
    {
        this->init_turn();
        this->_coins += 2;
        this->_foraid = true;
        this->_game.inc_turn();
    }

    void Player::coup(Player &player)
    {

        this->init_turn();

        if (this->_coins >= COUP_COINS)
        {
            this->_coins -= COUP_COINS;
            this->_game.removePlayer(player.name());
            player.setDefeated(true);
            // delete &player; // TODO: is this even needed?
        }
        else
        {
            throw invalid_argument{"Need at least 7 coins to initiate a coup!"};
        }

        this->_game.inc_turn();
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

    Player& Player::getAssassinated(){
        return this->assassinated.at(1);
    }

    void Player::clearAssassinated(){
        this->assassinated.clear();
    }
}