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
        string _name;

    public:
        Player(string role ="undefined", string name = "undefined");

        ~Player();

        void income();
        void foreign_aid();
        void coup(Player const &player);

        string name() const;
        string role() const;
        int coins() const;
        void block(Player const &player);
    };
}