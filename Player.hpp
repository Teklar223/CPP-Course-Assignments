#pragma once
#include <string> 
using std::string;

namespace coup
{

    class Player
    {
    private:
        int _coins;
        string _role;

    public:
        Player();

        ~Player();

        void income();
        void foreign_aid();
        void coup();

        string role();
        int coins();
    };
}