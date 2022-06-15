#ifndef SCHEDULE_H
#define SCHEDULE_H

#pragma once
#include "League.hpp"

namespace ex6
{
    class Schedule
    {
    public:
        Schedule(League lig);
        void PlaySeason();
        Team* findMostWins();
        Team* findMostLosses();
        Team* findMaxWinStreak();
        Team* findMaxLoseSteak();
    private:
        League league;
    };
}

#endif