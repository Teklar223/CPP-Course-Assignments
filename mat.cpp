#include <string>
#include <cctype>       // found on https://www.cplusplus.com/reference/cctype/isprint/
#include <iostream>
#include "mat.hpp"

using namespace std;    // instead of std::cout
using namespace ariel;  // instead of ariel::mat


namespace ariel{
    string mat(int col, int row, char sym1, char sym2){
        if (col < 1 || row < 1){
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

        char arr[row][col];
        int start_row = 0;
        int start_col = 0;
        int end_row = row - 1;
        int end_col = col - 1;
        int symbol_index = 1;
        char curr = sym1;

        while (start_row <= end_row && start_col <= end_col)
        {
            if (symbol_index % 2 == 0){
                curr = sym2;
            }
            else{
                curr = sym1;
            }
            // Inserting Rows:
            for(int i = 0; start_row + i <= end_row; i++){
                arr[start_row+i][start_col] = curr;
                arr[end_row-i][end_col] = curr;
            }
            // Inserting Columns:
            for(int i = 0; start_col + i <= end_col; i++){
                arr[start_row][start_col+i] = curr;
                arr[end_row][end_col-i] = curr;
            }

            //
            start_row += 1;
            start_col += 1;
            end_row -= 1;
            end_col -= 1;
            symbol_index += 1;
        }

        string ans;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                ans += arr[i][j];
            }
            ans += '\n';
        }


        return ans;
    }
}


/*

Currently only a basic 'skeleton' to prepare tests on.

*/