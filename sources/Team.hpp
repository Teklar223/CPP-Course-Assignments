#ifndef TEAM_H
#define TEAM_H

#pragma once
#include <string>
#include <stdexcept>
using std::string;

namespace ex6
{
    class Team
    {
    public:
        Team(string name, double talent);
        string getName() const;
        void setName(string &name);
        double getTalent() const;
        void setTalent(const double &talent);


    private:
        string m_name;
        double m_talent;
    public:
        int wins;
        int loses;
        int totalPoints;
        int win_streak;
        int lose_streak;
    };
}

#endif