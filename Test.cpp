#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

/*  4 of these cases were taken straight from the original problem
    as they are presented as the proper IO combination,
    https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix 
*/

TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));
	
    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													 "@-----------@\n"
													 "@-@@@@@@@@@-@\n"
													 "@-----------@\n"
													 "@@@@@@@@@@@@@"));
                                                     
    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
													"$+$\n"
													"$+$\n"
													"$+$\n"
													"$$$"));

    CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#"));

    CHECK(nospaces(mat(5, 5, '*', '*')) == nospaces("*****\n"
													"*****\n"
													"*****\n"
													"*****\n"
													"*****"));

    CHECK(nospaces(mat(1, 5, '*', ')')) == nospaces("*****"));

    /*  should work for the previous examples with different inputs 
        strictly speaking these are a variation of the first 4 tests:
    */

    CHECK(nospaces(mat(9, 7, '*', '#')) == nospaces("*********\n"
													"*#######*\n"
													"*#*****#*\n"
													"*#*###*#*\n"
													"*#*****#*\n"
													"*#######*\n"
													"*********"));
	
    CHECK(nospaces(mat(13, 5, '*', '!')) == nospaces("*************\n"
													 "*!!!!!!!!!!!*\n"
													 "*!*********!*\n"
													 "*!!!!!!!!!!!*\n"
													 "*************"));
                                                     
    CHECK(nospaces(mat(3, 5, ';', '+')) == nospaces(";;;\n"
													";+;\n"
													";+;\n"
													";+;\n"
													";;;"));

    CHECK(nospaces(mat(1, 1, '.', ')')) == nospaces("."));

}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%')); // row should be odd

    CHECK_THROWS(mat(11, 6, '$', '%')); // col should be odd
    
    CHECK_THROWS(mat(7, 5, ' ', '%'));  // space is an illegal argument

    CHECK_THROWS(mat(7, 5, '%', ' '));  // space is an illegal argument

    CHECK_THROWS(mat(0, 5, '$', '%'));  // row should be at least 1

    CHECK_THROWS(mat(-1, 5, '$', '%')); // ^ same ^

    CHECK_THROWS(mat(3, 0, '$', '%'));  // col should be at least 1

    CHECK_THROWS(mat(3, -5, '$', '%')); // ^ same ^

    CHECK_THROWS(mat(3, 5, '\n', '%'));  // \n is not printable

    CHECK_THROWS(mat(3, 5, '\v', '%'));  // \v is not printable

    CHECK_THROWS(mat(3, 5, '%', '\r'));  // \r is not printable

    CHECK_THROWS(mat(7, 5, '%', '\t'));  // \t is not printable



}


/* Add more test cases here */