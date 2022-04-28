#include "Contessa.hpp"

namespace coup
{

    Contessa::Contessa(Game const &game, string name){
        this->_role = "Contessa";
        this->_coins = 0;
        this->_name = std::move(name);
    }

    Contessa::~Contessa()
    {
    }
}