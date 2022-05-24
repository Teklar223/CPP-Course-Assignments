#pragma once
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <stdexcept>

/* !!!!!!!!!!!!!!!!!!!!!!! */
#include <vector>
/* ONLY HERE FOR THE AUTOMATIC TESTS TO COMPILE. */

using std::iterator;
using std::map;
using std::string;

namespace ariel
{
    class OrgChart
    {
        // *** Inner Classes *** //
    private:
        struct node
        {
            string val;
            node *parent = nullptr; // represents the boss
            node *head = nullptr;   // represents first employee of this employer
            node *tail = nullptr;   // represents last employee of this employer
            node *left = nullptr;   // represents same-level co-worker, linked from left
            node *right = nullptr;  // represents same-level co-worker, linked from right
            node(string &value) : val(value) {} //constructor
        };

    public:
        class Iterator // with the help of https://www.youtube.com/watch?v=F9eDv-YIOQ0&ab_channel=TheCherno and similar sources (google)
        {

        private:
            node *curr;
            node *next;
            string type; // expects level, reverse, or pre, see iterator implementations at the bottom of this file.
            node *rightKid();
            void gotoLeftmostChild();
            node *findAnyUncle();

        public:
            Iterator(node *init, string _type = "level");

            Iterator &operator++();

            Iterator operator++(int);

            string *operator->();

            string operator*();

            bool operator==(const Iterator &other) const;

            bool operator!=(const Iterator &other) const;
        };

        // *** Types and Functions *** //
    private:
        node *root;
        map<string, node *> employee_list;

    public:
        OrgChart();

        ~OrgChart();

        OrgChart &add_root(string value);

        OrgChart &add_sub(string const &_boss, string value);

        Iterator begin();
        Iterator end();
        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

        friend std::ostream &operator<<(std::ostream &out, OrgChart &org);
    };
}