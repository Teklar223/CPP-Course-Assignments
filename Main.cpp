#include "mat.hpp"
#include <string>

int main(){
    std :: cout << ariel :: mat(5,7,'@','#') << endl;
    std :: cout << ariel :: mat(99,99,'-',';') << endl;
    std :: cout << ariel :: mat(13,33,'!','?') << endl;
    std :: cout << ariel :: mat(51,51,'@','#') << endl;
    std :: cout << ariel :: mat_alt(16,16,'*','0') << endl;

    int row, col;
    std :: cout << "Pleaes enter a row number:" << endl;
    std :: cin >> row;

    std :: cout << "Pleaes enter a column number:" << endl;
    std :: cin >> col;

    char sym1, sym2;
    std :: cout << "Pleaes enter the first symbol:" << endl;
    std :: cin >> sym1;

    std :: cout << "Pleaes enter the second symbol:";
    std :: cin >> sym2;

    std :: cout << ariel :: mat(row,col,sym1,sym2) << endl;

}