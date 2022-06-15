#include "Game.hpp"

namespace ex6
{
    Game::Game(Team *home_team, Team *out_team)
    {
        m_Home = home_team;
        m_Out = out_team;
        m_outScore = 50;
        m_homeScore = 55;

        // https://stackoverflow.com/questions/38244877/how-to-use-stdnormal-distribution
        // https://www.youtube.com/watch?v=K2nrsQwKmHQ&ab_channel=BoQian

        // generate source of randomness:

        std::random_device rd;
        // std::mt19937 gen(rd());
        int sample;

        // calculate out team score bonus:

        std::normal_distribution<double> d1(25.0, 25.0);
        sample = d1(rd); // cast down to int
        if (sample > 50)
        {
            sample = 50;
        }
        if (sample < 0)
        {
            sample = 0;
        }
        m_outScore += sample;

        // calculate home team score bonus:

        sample = d1(rd); // cast down to int
        if (sample > 45)
        {
            sample = 45;
        }
        if (sample < 0)
        {
            sample = 0;
        }
        m_homeScore += sample;

        // 10 bonus points to the more talented team

        if (m_Home->getTalent() > out_team->getTalent())
        {
            m_homeScore += 10;
        }
        else
        {
            m_outScore += 10;
        }

        // now set the winning team:

        if (m_homeScore >= m_outScore)
        {
            m_winner = m_Home;
            m_Home->wins += 1;
            m_Home->win_streak += 1;
            m_Home->lose_streak = 0;
            m_Out->loses += 1;
            m_Out->lose_streak += 1;
            m_Out->win_streak = 0;
        }
        else
        {
            m_winner = m_Out;
            m_Out->wins += 1;
            m_Out->win_streak += 1;
            m_Out->lose_streak = 0;
            m_Home->loses += 1;
            m_Home->lose_streak += 1;
            m_Home->win_streak = 0;
        }

        m_Home->totalPoints += m_homeScore;
        m_Out->totalPoints += m_outScore;

        // small note: home team gets 5 bonus points and has a smaller probablity space
        // so a small but significant balancing act is that if out.talent == home.talent then the out team gets the bonus
        // and if after everything home.score == out.score then home team wins.
    }

    Team *Game::getHome()
    {
        return this->m_Home;
    }

    void Game::setHome(Team *new_home)
    {
        m_Home = new_home;
    }

    Team *Game::getOut()
    {
        return m_Out;
    }

    void Game::setOut(Team *new_out)
    {
        m_Out = new_out;
    }

    int Game::getHomeScore()
    {
        return m_homeScore;
    }

    int Game::getOutScore()
    {
        return m_outScore;
    }

    Team *Game::getWinner()
    {
        return m_winner;
    }

}