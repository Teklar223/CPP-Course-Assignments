#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <iterator>

#include "Notebook.hpp"
#include "Direction.hpp"
using namespace std;

namespace ariel
{

    Notebook::Notebook()
    {
        string temp;
        for (int i = 0; i < hundred; i++)
        {
            temp.append("_");
        }
        temp.append("\n");
        this->empty_row = temp;
    }
    Notebook::~Notebook()
    {
        // iterates over each map in the map and clear()'s each one
        /*
        for (map<int, map<int, string>>::iterator iter = this->notebook.begin();
             iter != this->notebook.end(); iter++)
        {
            this->notebook.at(iter->first).clear();
        }

        this->notebook.clear(); // finally - clear() this map as well
        */
    }

    bool Notebook::write(int page, int row, int column, Direction dir, const string &str)
    {
        if (column < 0 || row < 0 || page < 0 || column >= hundred || (int)(str.length() < 1))
        {
            throw invalid_argument{"check that ints are atleast 0 and that column is not above hundred"};
        }

        for (const char &c : str)
        {
            if (c == '~' || !isprint(c) ){
                throw invalid_argument{"cant write some chars in the string or it's empty"};
            }
        }

        

        if (dir == Direction::Horizontal)
        {
            if (column + (int)(str.length()) >= hundred)
            {
                throw invalid_argument{"cant write over capacity"};
            }
            _write_horizontal(page, row, column, str);
        }
        if (dir == Direction::Vertical)
        {
            _write_vertical(page, row, column, str);
        }
        return true;
    }

    std::string Notebook::read(int page, int row, int column, Direction dir, int length)
    {
        if (column < 0 || row < 0 || page < 0 || length < 0 || column >= hundred)
        {
            throw invalid_argument{"check that ints are atleast 0 and that column/length is not above hundred"};
        }

        if (dir == Direction::Horizontal)
        {
            if (column + length >= hundred)
            {
                throw invalid_argument{"cant read past the hundred'th column in a row!"};
            }
            return this->_read_horizontal(page, row, column, length);
        }
        if (dir == Direction::Vertical)
        {

            return this->_read_vertical(page, row, column, length);
        }

        return "something went very wrong with your compiler.";
    }

    bool Notebook::erase(int page, int row, int column, Direction dir, int length)
    {
        if (column < 0 || row < 0 || page < 0 || length < 0 || column >= hundred)
        {
            throw invalid_argument{"check that ints are atleast 0 and that column/length is not above hundred"};
            // throw invalid_argument ("check that ints are atleast 0 and that column/length is not above hundred");
        }

        if (dir == Direction::Horizontal)
        {
            if (column + length >= hundred)
            {
                throw invalid_argument{"cant erase past the hundred'th column in a row!"};
            }
            this->_erase_horizontal(page, row, column, length);
        }
        if (dir == Direction::Vertical)
        {
            this->_erase_vertical(page, row, column, length);
        }
        return false;
    }

    void Notebook::show(int page)
    {
        
        if (page < 0){
            throw invalid_argument{"invladi argument < 0"};
        }

        if (this->_is_page_empty(page))
        {
            this->_print_empty_until_num(hundred);
        }
        else
        {
            int max = this->_get_max_written_row(page);
            this->_print_until_num(page, (int)max + thirty);
        }
    }

};
