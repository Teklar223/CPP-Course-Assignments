#include <string>
#include <cctype>       // found on https://www.cplusplus.com/reference/cctype/isprint/
#include <iostream>
#include "mat.hpp"

using namespace std;    // instead of std::cout
using namespace ariel;  // instead of ariel::mat


string mat(int col, int row, char sym1, char sym2){

    if (col < 1 || row < 1){  // TODO: see if this will be accepted
        throw invalid_argument{"Both row and col must be stricly positive"};
    }

    if (col%2==0 || row%2==0){
        throw invalid_argument{"Both row and col must be odd numbers!"};
    }

    if (!((bool)isprint(sym1)) || !((bool)isprint(sym2))){
        throw invalid_argument{"sym1 or sym2 are not printable symbols!"};
    }

    if (sym1 == ' ' || sym2 == ' '){
        throw invalid_argument{"Does not accept space as a symbol!"};
    }

    return "Function not yet implemented";
}


/*

Currently only a basic 'skeleton' to prepare tests on.

*/