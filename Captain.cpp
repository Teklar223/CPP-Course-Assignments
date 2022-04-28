#include "Captain.hpp"

namespace coup
{
    Captain::Captain(Game const &game, string name)
    {
        this->_role = "Captain";
        this->_coins = 0;
        this->_name = std::move(name);
    }

    Captain::~Captain()
    {
    }

    void Captain::steal(Player const &player)
    {
        
    }
}