#ifndef GAME_H
#define GAME_H

#pragma once
#include "Team.hpp"
#include <random>
using std::rand;
using std::string;

namespace ex6
{
    class Game
    {
    public:
        Game(Team *home_team, Team *out_team);
        Team *getHome();
        void setHome(Team *new_home);
        Team *getOut();
        void setOut(Team *new_out);
        Team *getWinner();
        int getHomeScore();
        int getOutScore();

    private:
        Team *m_Home;
        Team *m_Out;
        int m_homeScore;
        int m_outScore;
        Team *m_winner = nullptr;
    };
}

#endif