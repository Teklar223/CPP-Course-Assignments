#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
using std::string;
using std::vector;
using namespace std;
constexpr int COUP_COINS = 7;
constexpr int MAX_PLAYERS = 6;

namespace coup
{
    class Game; //forward declaration.
    class Player
    {
    protected:
        Game *_game;
        unsigned int _coins;
        string _name;
        bool _action;
        bool _foraid;
        string _role;
        bool defeated;
        std::map<int, Player &> assassinated;
        std::map<int, Player &> stolefrom;
        void init_turn();

    public:
        bool getDefeated() const;
        void setDefeated(bool val = false);
        bool getAction() const;
        void setAction(bool val = false);
        bool getForaid() const;
        void setForaid(bool val = false);
        void cancelForeignAid();
        void addCoins(unsigned int num);
        void subCoins(unsigned int num);
        void income();
        void foreign_aid();
        void coup(Player &player);
        string name() const;
        string role() const;
        unsigned int coins() const;
        Player &getAssassinated();
        void clearAssassinated();
        Player &getStolenfrom();
        void clearStolenfrom();
    };

    class Game
    {
    private:
        vector<Player*> _players;
        unsigned int _turn;
        int _activePlayers;
        int _defeatedPlayers;
        string _winner;
        
    public:
        Game();

        void inc_turn();
        void addPlayer(Player *player);
        void removePlayer(string const &name);
        vector<string> players() const;
        string turn() const;
        string winner()  const;
    };
}