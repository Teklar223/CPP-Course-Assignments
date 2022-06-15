#include "Schedule.hpp"
#include "Game.hpp"

namespace ex6
{
    Schedule::Schedule(League lig)
        : league(lig)
    {
    }
    void Schedule::PlaySeason()
    {
        vector<Team> *vec = league.getTeams();
        unsigned int i, j;
        for (i = 0; i < 19; i++)
        {
            for (j = 0; j < 20; j++)
            {
                Game(&vec->at(j), &vec->at((j + i) % 20));
            }
        }
    }

    Team *Schedule::findMostWins()
    {
        vector<Team> *vec = league.getTeams();
        Team* ans = &vec->at(0);

        for(unsigned int i = 1; i < 20; i++)
        {
            if (vec->at(i).wins > ans->wins)
            {
                ans = &vec->at(i);
            }
        }

        return ans;
    }

    Team *Schedule::findMostLosses()
    {
        vector<Team> *vec = league.getTeams();
        Team* ans = &vec->at(0);

        for(unsigned int i = 1; i < 20; i++)
        {
            if (vec->at(i).loses > ans->loses)
            {
                ans = &vec->at(i);
            }
        }

        return ans;
    }

    Team *Schedule::findMaxWinStreak()
    {
        vector<Team> *vec = league.getTeams();
        Team* ans = &vec->at(0);

        for(unsigned int i = 1; i < 20; i++)
        {
            if (vec->at(i).win_streak > ans->win_streak)
            {
                ans = &vec->at(i);
            }
        }

        return ans;
    }

    Team *Schedule::findMaxLoseSteak()
    {
        vector<Team> *vec = league.getTeams();
        Team* ans = &vec->at(0);

        for(unsigned int i = 1; i < 20; i++)
        {
            if (vec->at(i).lose_streak > ans->lose_streak)
            {
                ans = &vec->at(i);
            }
        }

        return ans;
    }

}