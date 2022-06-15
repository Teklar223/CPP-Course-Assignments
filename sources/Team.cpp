#include "Team.hpp"

namespace ex6
{
    Team::Team(string name, double talent)
        : m_name(std::move(name)), m_talent(talent), wins(0), totalPoints(0), win_streak(0), lose_streak(0)
    {
        /**
         * @brief Construct a new 'Team' object
         *
         */
        if (talent <= 0 || talent >= 1)
        {
            throw std::logic_error{"0 < talent < 1"};
        }
    }

    string Team::getName() const
    {
        return m_name;
    }

    void Team::setName(string &name)
    {
        m_name = std::move(name);
    }

    double Team::getTalent() const
    {
        return m_talent;
    }

    void Team::setTalent(const double &talent)
    {
        m_talent = talent;
    }

}
