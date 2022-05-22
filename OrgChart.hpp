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
        class Iterator // with the help of https://www.youtube.com/watch?v=F9eDv-YIOQ0&ab_channel=TheCherno and similar sources (google)
        {

        private:
            node *next;
            string type; // expects level, reverse, or pre, see iterator implementations at the bottom of this file.

        public:
            node *curr; // TODO PRIVATE
            Iterator(node *init, string _type = "level")
                : curr(init), type(_type)
            {
                if (init != nullptr)
                {
                    next = init->head; // not part of the initialization list, because init can be null, and thus we cant access this member without segfaulting.

                    if (type == "reverse") // different start offset then the other cases, can only if init is not a nullptr.
                    {
                        while (curr->head != nullptr)
                        {
                            curr = curr->head;
                        }

                        next = curr->parent;
                    }
                }
            }

            Iterator &operator++()
            {
                if (curr != nullptr)
                {
                    if (this->type == "level")
                    {
                        if (curr->right != nullptr)
                        {
                            curr = curr->right;
                        }
                        else
                        {
                            curr = next;
                            if (curr != nullptr)
                            {
                                next = curr->head;
                                // TODO: more rigourous logic for the next (in cases where curr.head is empty but curr.right.right.head exists for example)????
                            }
                        }
                    }

                    if (this->type == "reverse")
                    {
                        if (curr->right != nullptr)
                        {
                            curr = curr->right;
                        }
                        else
                        {
                            curr = next;
                            if (curr != nullptr)
                            {
                                next = curr->parent;
                                // TODO: more rigourous logic for the next (in the constructor for this case!)???????
                            }
                        }
                    }

                    if (this->type == "pre")
                    {
                        curr->visited = true;
                        if (curr->head != nullptr)
                        {
                            curr = curr->head;
                        }
                        else if (curr->right != nullptr)
                        {
                            if (curr->right->parent->val == curr->parent->val)
                            {
                                curr = curr->right;
                            }
                            else
                            {
                                while (curr->right->parent->val != curr->parent->val)
                                {
                                    curr = curr->parent;
                                }
                                if (curr->right != nullptr)
                                {
                                    curr = curr->right;
                                }
                            }
                        }
                        else // this means the iterator reached the 'bottom right' member and has therefore finished the preoder
                        {
                            curr = nullptr;
                        }
                    }
                }
                return *this;
            }

            Iterator operator++(int)
            {
                Iterator it = Iterator(this->curr, this->type);
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
                return (*curr).val;
            }

            bool operator==(const Iterator &other) const
            {

                bool ans = true;
                if (this->curr == nullptr || other.curr == nullptr)
                {
                    if (this->curr == nullptr && other.curr == nullptr)
                    {
                        return ans; // curenntly true.
                    }
                    else
                    {
                        return !ans;
                    }
                }
                return (this->curr == other.curr);
            }

            bool operator!=(const Iterator &other) const
            {
                return !(*this == other);
            }
        };

        // *** Types and Functions *** //
    private:
        node *root;
        map<string, node *> employee_list;

    public:
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

            if (boss->head == nullptr) // if node has no children nodes, also if head is empty tail is also empty.
            {
                boss->head = employee;
                boss->tail = employee;
                if (boss->left != nullptr)
                {
                    node *curr = boss->left;
                    while (curr != nullptr && curr->head == nullptr)
                    {
                        curr = curr->left;
                    }
                    if (curr != nullptr)
                    {
                        employee->left = curr->tail;
                        curr->tail->right = employee;
                    }
                }
                if (boss->right != nullptr)
                {
                    node *curr = boss->right;
                    while (curr != nullptr && curr->head == nullptr)
                    {
                        curr = curr->right;
                    }
                    if (curr != nullptr)
                    {
                        employee->right = curr->head;
                        curr->head->left = employee;
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

        friend std::ostream &operator<<(std::ostream &out, OrgChart &org)
        {
            out << org.root->val << "|\n";
            node *curr = org.root->head;
            node *next = curr->head;
            while (curr != nullptr)
            {
                out << curr->val << "(" << curr->parent->val << ") | " ;
                if (curr->right != nullptr)
                {
                    curr = curr->right;
                }
                else
                {
                    out << '\n';
                    curr = next;
                    if (curr != nullptr)
                    {
                        next = curr->head;
                        // TODO: if the level order does need more grigours next logic, implement here too.
                    }
                }
            }
            return out;
        }
    };
}