#include "Game.hpp"
#include "League.hpp"
#include "Schedule.hpp"
#include "Team.hpp"
#include <iostream>
using namespace std;
using namespace ex6;

int main()
{
    League lig = League();
    Schedule s = Schedule(lig);
    s.PlaySeason();
    Team *most_wins = s.findMostWins();
    Team *most_lose = s.findMostLosses();
    Team *win_streak = s.findMaxWinStreak();
    Team *lose_streak = s.findMaxLoseSteak();
    cout << "Most wins: " << most_wins->getName() << endl;
    cout << "Most losses: " << most_lose->getName() << endl;
    cout << "Biggest win streak: " << win_streak->getName() << endl;
    cout << "Biggest lose streak: " << lose_streak->getName() << endl;
}