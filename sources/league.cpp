#include "League.hpp"

namespace ex6
{
    League::League()
    {
        int size = 20;
        string name = "Team ";
        for(int i = 1; i<=20; i++) //1 based for names.
        {
            teams.push_back(Team(name + std::to_string(i),((double) rand() / (RAND_MAX))));
        }
    }

    vector<Team> * League::getTeams()
    {
        return &teams;
    }
}