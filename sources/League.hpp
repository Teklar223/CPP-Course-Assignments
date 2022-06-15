#ifndef LEAGUE_H
#define LEAGUE_H

#pragma once
#include <vector>
#include "Team.hpp"
#include <random>
using std::vector;
using std::rand;
constexpr int max_size = 20;

namespace ex6
{
    class League
    {
    public:
        League();
        vector<Team>* getTeams();

    private:
        vector<Team> teams;
    };
}

#endif