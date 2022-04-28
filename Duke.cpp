#include "Duke.hpp"

namespace coup
{

    Duke::Duke(Game const &game, string name){
        this->_role = "Duke";
        this->_coins = 0;
        this->_name = std::move(name);
    }

    Duke::~Duke()
    {
    }

    void Duke::tax()
    {
        
    }
}