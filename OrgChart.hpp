#pragma once
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <stdexcept>
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
            bool visited = false;
            node *parent = nullptr; // represents the boss
            node *head = nullptr;   // represents first employee of this employer
            node *tail = nullptr;   // represents last employee of this employer
            node *left = nullptr;   // represents same-level co-worker
            node *right = nullptr;  // ^    ^    ^    ^    ^    ^    ^

            node(string &value) : val(value) {}
        };

    public:
        class Iterator // with the help of https://www.youtube.com/watch?v=F9eDv-YIOQ0&ab_channel=TheCherno
        {

        private:
            node *curr;
            node *next;
            string type; // expects level, reverse, or pre, see iterator implementations at the bottom of this file.

        public:
            Iterator(node *&init, string _type = "level")
                : curr(init), type(_type), next(init->head)
            {
                if (type == "reverse") // different logic then the other cases.
                {
                    while (curr->head != nullptr)
                    {
                        curr = curr->head;
                    }

                    next = curr->parent;
                }
            }

            Iterator &operator++()
            {

                return *this;
                this->curr = nullptr; // REMOVE THIS, patchwork to stop iterators early for demo runtime.

                if (this->type == "level")
                {
                    // TODO
                }

                if (this->type == "reverse")
                {
                    // TODO
                }

                if (this->type == "pre")
                {
                    // TODO
                }
                return *this;
            }

            Iterator operator++(int)
            {
                Iterator it = Iterator(this->curr, this->type); // TODO: test that this is correct.
                ++(*this);
                return it;
            }

            string *operator->()
            {
                string *temp = &this->curr->val;
                return temp;
                return &(curr->val);
            }

            string operator*()
            {
                string temp = "WIP";
                return temp;
                return curr->val;
            }

            bool operator==(const Iterator &other) const
            {
                return false;
                return this->curr == other.curr;
            }

            bool operator!=(const Iterator &other) const
            {
                return !(*this == other);
            }
        };

        // *** Types and Functions *** //
    private:
        // TODO: employee list and root are privates.
    public:
        node *root;
        map<string, node *> employee_list;

        OrgChart()
            : root(nullptr)
        {
        }

        ~OrgChart()
        {
            // TODO.
        }

        OrgChart &add_root(string value)
        {
            if (this->root == nullptr)
            {
                this->root = new node(value);
                this->employee_list.insert({value, this->root}); // this is for the add_sub logic later.
            }
            else
            {
                this->root->val = value;
            }

            return *this;
        }

        OrgChart &add_sub(string _boss, string value)
        {
            node *boss = this->employee_list.at(_boss); // will throw for me if this item does not exist.
            node *employee = new node(value);
            employee->parent = boss;

            if (boss->head == nullptr) // if head is empty tail is also empty.
            {
                boss->head = employee;
                boss->tail = employee;
                if (boss->left != nullptr)
                {
                    node *curr = boss->left;
                    while (curr->head != nullptr && curr != nullptr)
                    {
                        curr = curr->left;
                    }
                    if (curr != nullptr)
                    {
                        employee->left = boss->left->tail;
                    }
                }
                if (boss->right != nullptr)
                {
                    node *curr = boss->right;
                    while (curr->head != nullptr && curr != nullptr)
                    {
                        curr = curr->right;
                    }
                    if (curr != nullptr)
                    {
                        employee->right = boss->right->head;
                    }
                }
            }
            else // list grows from tail.
            {
                employee->left = boss->tail;
                employee->right = boss->tail->right;
                boss->tail->right = employee;
                boss->tail = employee;
            }

            this->employee_list.insert({value, employee}); // this is for the add_sub logic later.
            return *this;
        }

        /*
        Iterator begin() { return (Iterator(this->root, "level")); }

        Iterator end()
        {
            node *temp = nullptr;
            return (Iterator(temp, "level"));
        }

        Iterator begin_level_order() { return begin(); }

        Iterator end_level_order() { return end(); }

        Iterator begin_reverse_order() { return (Iterator(this->root, "reverse")); }

        Iterator reverse_order()
        {
            node *temp = nullptr;
            return (Iterator(temp, "reverse"));
        } // int* end_reverse_order(); ?

        Iterator begin_preorder() { return (Iterator(this->root, "pre")); }

        Iterator end_preorder()
        {
            node *temp = nullptr;
            return (Iterator(temp, "pre"));
        }
        */
        string *begin()
        {
            string *temp = (string *)malloc(sizeof("WIP"));
            *temp = "WIP";
            return temp;
        }

        string *end() { return begin(); }

        string *begin_level_order() { return nullptr; }

        string *end_level_order() { return nullptr; }

        string *begin_reverse_order() { return nullptr; }

        string *reverse_order() { return nullptr; }

        string *begin_preorder() { return nullptr; }

        string *end_preorder() { return nullptr; }

        friend std::ostream &operator<<(std::ostream &out, const OrgChart &org)
        {
            out << "NOT IMPLEMENTED"; // TODO
            return out;
        }
    };
}