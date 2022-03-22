#include "Direction.hpp"
#include "Notebook.hpp"
#include "doctest.h"
#include <array>
#include <string>

TEST_CASE("BAD INPUT"){

    SUBCASE("Horizontal"){

        ariel :: Notebook notebook;

        CHECK_THROWS(notebook.write(-5,2,2,ariel::Direction::Horizontal,"_"));
        CHECK_THROWS(notebook.write(2,-5,2,ariel::Direction::Horizontal,"_"));
        CHECK_THROWS(notebook.write(2,2,-5,ariel::Direction::Horizontal,"_"));

        CHECK_THROWS(notebook.read(-5,2,2,ariel::Direction::Horizontal,1));
        CHECK_THROWS(notebook.read(2,-5,2,ariel::Direction::Horizontal,1));
        CHECK_THROWS(notebook.read(2,2,-5,ariel::Direction::Horizontal,1));

        CHECK_THROWS(notebook.erase(-5,2,2,ariel::Direction::Horizontal,1));
        CHECK_THROWS(notebook.erase(2,-5,2,ariel::Direction::Horizontal,1));
        CHECK_THROWS(notebook.erase(2,2,-5,ariel::Direction::Horizontal,1));

    }

    SUBCASE("Vertical"){

        ariel :: Notebook notebook;

        CHECK_THROWS(notebook.write(-5,2,2,ariel::Direction::Vertical,"_"));
        CHECK_THROWS(notebook.write(2,-5,2,ariel::Direction::Vertical,"_"));
        CHECK_THROWS(notebook.write(2,2,-5,ariel::Direction::Vertical,"_"));

        CHECK_THROWS(notebook.read(-5,2,2,ariel::Direction::Vertical,1));
        CHECK_THROWS(notebook.read(2,-5,2,ariel::Direction::Vertical,1));
        CHECK_THROWS(notebook.read(2,2,-5,ariel::Direction::Vertical,1));

        CHECK_THROWS(notebook.erase(-5,2,2,ariel::Direction::Vertical,1));
        CHECK_THROWS(notebook.erase(2,-5,2,ariel::Direction::Vertical,1));
        CHECK_THROWS(notebook.erase(2,2,-5,ariel::Direction::Vertical,1));

    }

    SUBCASE("Invalid Column Length"){

        ariel :: Notebook notebook;

        CHECK_THROWS(notebook.write(5,2,101,ariel::Direction::Vertical,"_"));
        CHECK_THROWS(notebook.write(2,5,1001,ariel::Direction::Vertical,"_"));
        CHECK_THROWS(notebook.write(2,2,101,ariel::Direction::Horizontal,"_"));

        CHECK_THROWS(notebook.read(5,2,101,ariel::Direction::Vertical,1));
        CHECK_THROWS(notebook.read(2,5,1001,ariel::Direction::Vertical,1));
        CHECK_THROWS(notebook.read(2,2,101,ariel::Direction::Horizontal,1));

        CHECK_THROWS(notebook.erase(5,2,101,ariel::Direction::Vertical,1));
        CHECK_THROWS(notebook.erase(2,5,1001,ariel::Direction::Vertical,1));
        CHECK_THROWS(notebook.erase(2,2,101,ariel::Direction::Horizontal,1));

    }

    SUBCASE("Invalid Read or Erase lengths"){

        ariel :: Notebook notebook;

        CHECK_THROWS(notebook.read(5,2,11,ariel::Direction::Vertical,200));
        CHECK_THROWS(notebook.read(2,5,11,ariel::Direction::Vertical,500));
        CHECK_THROWS(notebook.read(2,2,11,ariel::Direction::Horizontal,999));

        CHECK_THROWS(notebook.erase(5,2,11,ariel::Direction::Vertical,200));
        CHECK_THROWS(notebook.erase(2,5,11,ariel::Direction::Vertical,500));
        CHECK_THROWS(notebook.erase(2,2,11,ariel::Direction::Horizontal,999));

    }
}

TEST_CASE("GOOD INPUT"){

    SUBCASE("basic func"){

        ariel :: Notebook notebook;

        CHECK(notebook.write(1,1,0,ariel::Direction::Horizontal,"hello"));
        CHECK(notebook.write(2,2,0,ariel::Direction::Horizontal,"world"));

        CHECK(notebook.erase(1,1,0,ariel::Direction::Horizontal,5));
        CHECK(notebook.erase(2,2,0,ariel::Direction::Horizontal,5));

    }

    SUBCASE("adv' func"){

        ariel :: Notebook notebook;

        CHECK(notebook.read(0,0,0,ariel::Direction::Horizontal,5) == "_____");
        notebook.write(0,0,0,ariel::Direction::Horizontal, "HELLO");
        CHECK_THROWS(notebook.write(0,0,0,ariel::Direction::Horizontal, "OLLEH")); // already wrote --> throws error
        CHECK(notebook.read(0,0,0,ariel::Direction::Horizontal,5) == "HELLO");
        notebook.erase(0,0,0,ariel::Direction::Horizontal,5);
        CHECK(notebook.read(0,0,0,ariel::Direction::Horizontal,5) == "~~~~~");

        notebook.write(0,10,0,ariel::Direction::Vertical, "SOMETHING");
        CHECK_THROWS(notebook.write(0,10,0,ariel::Direction::Vertical, "GNIHTEMOS")); // already wrote --> throws error

    }
}