#include "Game.hpp"

namespace coup
{
    Game::Game(){
        this->_turn = 0;
        this->_winner = "undefiend";
    }

    Game::~Game(){

    }

    string Game::players(){
        return "undefined";
    }
    int Game::turn(){
        return this->_turn;
    }
    string Game::winner(){
        return this->_winner;
    }
}