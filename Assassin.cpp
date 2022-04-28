#include "Assassin.hpp"

namespace coup
{
    Assassin::Assassin(Game const &game, string name)
    {
        this->_role = "Assassin";
        this->_coins = 0;
        this->_name = std::move(name);
    }

    Assassin::~Assassin()
    {
    }
}