#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
#include "Contessa.hpp"
#include "Captain.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "doctest.h"
#include <array>
#include <string>
using namespace coup;

TEST_CASE("BAD INPUT")
{

    SUBCASE("Game")
    {

        Game game_1;
        Duke duke{game_1, "Moshe"};
        Assassin assassin{game_1, "Yossi"};
        Ambassador ambassador{game_1, "Meirav"};
        Captain captain{game_1, "Reut"};
        Contessa contessa{game_1, "Gilad"};

        CHECK_THROWS(duke.coup(assassin));
        CHECK_THROWS(duke.coup(contessa));
        CHECK_THROWS(duke.coup(duke));
        CHECK_THROWS(duke.coup(ambassador));
        CHECK_THROWS(assassin.coup(ambassador));
        CHECK_THROWS(assassin.coup(duke));
        CHECK_THROWS(assassin.coup(captain));
        CHECK_THROWS(assassin.coup(contessa));
        CHECK_THROWS(captain.coup(assassin));
        CHECK_THROWS(captain.coup(duke));
        CHECK_THROWS(captain.coup(contessa));
        CHECK_THROWS(captain.coup(assassin));
        CHECK_THROWS(ambassador.coup(assassin));
        CHECK_THROWS(ambassador.coup(duke));
        CHECK_THROWS(ambassador.coup(captain));
        CHECK_THROWS(ambassador.coup(contessa));
        CHECK_THROWS(contessa.coup(assassin));
        CHECK_THROWS(contessa.coup(duke));
        CHECK_THROWS(contessa.coup(captain));
        CHECK_THROWS(contessa.coup(ambassador));
        

    }
}