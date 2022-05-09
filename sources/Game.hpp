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
constexpr int MUST_COUP = 10;

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
        bool blocked;
        std::map<int, Player &> assassinated;
        std::map<int, Player &> stolefrom;
        void init_turn();
        void init_turn_free_action();

    public:
        bool getDefeated() const;
        void setDefeated(bool val = false);
        bool getAction() const;
        void setAction(bool val = false);
        bool getForaid() const;
        void setForaid(bool val = false);
        bool getBlocked() const;
        void setBlocked(bool val = false);
        void cancelForeignAid();
        void addCoins(unsigned int num);
        void subCoins(unsigned int num);
        void income();
        void foreign_aid();
        virtual void coup(Player &player);
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
        bool _started;
        unsigned int _turn;
        unsigned int _defeatedPlayers;
        string _winner;
        
    public:
        Game();

        Player* getCurrentPlayer() const;
        void inc_turn();
        void inc_defeated();
        void dec_defeated();
        unsigned int getDefeated() const;
        void addPlayer(Player *player);
        void removePlayer(string const &name);
        void declareWinner(string const &name);
        vector<string> players() const;
        string turn() const;
        string winner()  const;
        bool is_game_over() const;
        bool is_enough_players() const;
        bool has_started() const;
        void start_game();
    };
}