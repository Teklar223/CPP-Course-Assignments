#ifndef NOTEBOOK
#define NOTEBOOK

#include "Notebook.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <map>
#include <iterator>
using namespace std;

namespace ariel
{

    const int thirty = 30;
    const int hundred = 100;

    class Notebook
    {

        map<int, map<int, string>> notebook;
        string empty_row;

    public:
        Notebook();
        ~Notebook();

        bool write(int, int, int, Direction, const string &str);

        std::string read(int, int, int, Direction, int);

        bool erase(int, int, int, Direction, int);

        void show(int);

        bool _is_row_empty(int page, int row)
        {
            if (this->_is_page_empty(page))
            {
                return true;
            }
            try
            {
                return this->notebook.at(page).at(row).empty();
            }
            catch (out_of_range)
            {
                return true;
            }
        }

        bool _is_page_empty(int page)
        {
            try
            {
                return this->notebook.at(page).empty();
            }
            catch (out_of_range)
            {
                return true;
            }
        }

        string _generate_string_from_char(char c, int length)
        {
            string str = "";
            for (int i = 0; i < length; i++)
            {
                str += c;
            }
            return str;
        }

        void _write_horizontal(int page, int row, int column, const string &str)
        {
            int index = 0;

            if (_is_page_empty(page))
            {
                map<int, string> tmp;
                tmp.insert({row, this->empty_row});
                this->notebook.insert({page, tmp});
                for (const char &c : str)
                {

                    this->notebook[page][row][(unsigned int)(column + index)] = c;
                    index++;
                }
            }
            else
            {
                if (_is_row_empty(page, row))
                {
                    this->notebook[page].insert({row, this->empty_row});

                    for (const char &c : str)
                    {
                        this->notebook[page][row][(unsigned int)(column + index)] = c;
                        index++;
                    }
                }
                else
                {
                    for (int i = 0; i < str.length(); i++)
                    { // this block checks that nothing else is written
                        if (this->notebook.at(page).at(row).at((unsigned int)(column + i)) != '_')
                        {
                            throw std::invalid_argument("cant write on something other than '_'");
                        }
                    }

                    for (const char &c : str) // this block writes to the map
                    {
                        this->notebook[page][row][(unsigned int)(column + index)] = c;
                        index++;
                    }
                }
            }
        }

        // using operator[] with non-existent key always performs an insert.
        // https://en.cppreference.com/w/cpp/container/map  -  example code at bottom of the page.

        void _write_vertical(int page, int row, int column, const string &str)
        {
            if (_is_page_empty(page))
            {
                map<int, string> tmp;
                this->notebook.insert({page, tmp});
            }

            for (int i = row; i < row + (int)(str.length()); i++)
            {
                if (!_is_row_empty(page, row + i))
                {
                    if (this->notebook.at(page).at(row).at((unsigned int)(column + i)) != '_')
                    {
                        throw std::invalid_argument("cant write on something other than '_'");
                    }
                }
            }

            int index = 0;
            for (const char &c : str)
            {
                if (_is_row_empty(page, row + index))
                {
                    this->notebook[page].insert({row + index, this->empty_row});
                }
                this->notebook[page][row + index][(unsigned int)(column)] = c;
                index++;
            }
        }

        string _read_horizontal(int page, int row, int column, int length)
        {
            string str;
            for (int i = 0; i < length; i++)
            {
                try
                {
                    str += this->notebook.at(page).at(row).at((unsigned int)(column + i));
                }
                catch (std::out_of_range)
                {
                    str += '_';
                }
            }
            return str;
        }

        string _read_vertical(int page, int row, int column, int length)
        {
            string str;
            for (int i = 0; i < length; i++)
            {
                try
                {
                    str += this->notebook.at(page).at(row + i).at((unsigned int)(column));
                }
                catch (std::out_of_range)
                {
                    str += '_';
                }
            }
            return str;
        }

        void _erase_horizontal(int page, int row, int column, int length)
        {
            if (_is_page_empty(page))
            {
                map<int, string> tmp;
                tmp.insert({row, this->empty_row});
                this->notebook.insert({page, tmp});
                for (int i = 0; i < length; i++)
                    {
                        this->notebook[page][row][(unsigned int)(column + i)] = '~';
                    }
            }
            else
            {
                if (_is_row_empty(page, row))
                {
                    this->notebook[page].insert({row, this->empty_row});

                    for (int i = 0; i < length; i++)
                    {
                        this->notebook[page][row][(unsigned int)(column + i)] = '~';
                    }
                }
                else
                {
                    for (int i = 0; i < length; i++)
                    {
                        this->notebook[page][row][(unsigned int)(column + i)] = '~';
                    }
                }
            }
        }

        void _erase_vertical(int page, int row, int column, int length)
        {
            if (_is_page_empty(page))
            {
                map<int, string> tmp;
                this->notebook.insert({page, tmp});
            }

            for (int i = row; i < row + length; i++)
            {
                if (!_is_row_empty(page, row + i))
                {
                    if (this->notebook.at(page).at(row).at((unsigned int)(column + i)) != '_')
                    {
                        throw std::invalid_argument("cant write on something other than '_'");
                    }
                }
            }

            for (int i = 0; i < length; i++)
            {
                if (_is_row_empty(page, row + i))
                {
                    this->notebook[page].insert({row + i, this->empty_row});
                }
                this->notebook[page][row + i][(unsigned int)(column)] = '~';
            }
        }

        string _get_row_by_page(int page, int row)
        {
            if (this->_is_page_empty(page))
            {
                return this->empty_row;
            }

            if (this->_is_row_empty(page, row))
            {
                return this->empty_row;
            }

            return this->notebook[page][row];
        }

        void _print_empty_until_num(int num)
        {
            for (int i = 1; i <= num; i++)
            { // starts at 1 since it's more natural than 0 to represent rows ( this is for visual only )
                std::cout << i << " " << this->empty_row;
            }
        }

        void _print_until_num(int page, int num)
        {
            for (int i = 1; i <= num; i++)
            { // starts at 1 since it's more natural than 0 to represent rows ( this is for visual only )
                std::cout << i << " " << this->_get_row_by_page(page, i);
            }
        }

        void _print_from_num_to_num(int num1, int num2)
        {
            for (int i = num1; i <= num2; i++)
            {
                std::cout << i << " " << this->empty_row;
            }
        }

        int _get_max_written_row(int page)
        {

            // https://stackoverflow.com/questions/1443793/iterate-keys-in-a-c-map

            if (this->_is_page_empty(page))
            {
                return 0;
            }

            int max = 0;
            int curr;

            for (map<int, string>::iterator iter = this->notebook.at(page).begin();
                 iter != this->notebook.at(page).end(); iter++)
            {
                curr = iter->first;
                if (curr > max)
                {
                    max = curr;
                }
            }

            return max;
        }
    };
}

#endif