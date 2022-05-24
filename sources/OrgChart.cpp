#include "OrgChart.hpp"

namespace ariel
{

    OrgChart::OrgChart() : root(nullptr) {}
    OrgChart::~OrgChart()
    {
        // initiating a reverse level pass on the OrgChart
        //(the implemented iterator does not support deletion as it does not allow access to the node itself, only the value it holds.)
        if (this->root != nullptr)
        {
            node *curr = this->root;
            while (curr->head != nullptr)
            {
                curr = curr->head;
            }
            node *next = curr->parent;
            node *toDelete = curr;

            // starting the reverse level pass, and deleting nodes along the way.
            while (curr != nullptr)
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
                    }
                }
                delete toDelete;
                toDelete = curr;
            }
        }
        // TODO: fix. currently using a variation of the reverse order iteration.

        this->employee_list.clear();
    }

    OrgChart &OrgChart::add_root(string value)
    {
        if (this->root == nullptr)
        {
            this->root = new node(value);
        }
        else
        {
            this->employee_list.erase(this->root->val); // removing map value instead of modifying the key
            this->root->val = value;
        }

        this->employee_list.insert({value, this->root}); // this is for the add_sub logic later.

        return *this;
    }
    OrgChart &OrgChart::add_sub(string const &_boss, string value)
    {
        if (this->root == nullptr)
        {
            throw std::logic_error{"You must add_root before you call add_sub!"};
        }
        node *boss = this->employee_list.at(_boss); // TODO : should throw for me if this item does not exist.
        node *employee = new node(value);
        employee->parent = boss;

        if (boss->head == nullptr) // if node has no children nodes, also if head is empty tail is also empty.
        {
            boss->head = employee;
            boss->tail = employee;
            /* This section ensures strong connectivity between same-level nodes. */
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

    std::ostream &operator<<(std::ostream &out, OrgChart &org)
    {
        out << org.root->val << "|\n";
        OrgChart::node *curr = org.root->head;
        OrgChart::node *next = curr->head;
        while (curr != nullptr)
        {
            out << curr->val << "(" << curr->parent->val << ") | ";
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

    OrgChart::Iterator OrgChart::begin()
    {
        if (this->root == nullptr)
        {
            throw std::logic_error{"Can't iterate over an empty OrgChart!"};
        }
        return (Iterator(this->root, "level"));
    }

    OrgChart::Iterator OrgChart::end()
    {
        if (this->root == nullptr)
        {
            throw std::logic_error{"Can't iterate over an empty OrgChart!"};
        }
        node *temp = nullptr;
        return (Iterator(temp, "level"));
    }

    OrgChart::Iterator OrgChart::begin_level_order() { return begin(); }

    OrgChart::Iterator OrgChart::end_level_order() { return end(); }

    OrgChart::Iterator OrgChart::begin_reverse_order()
    {
        if (this->root == nullptr)
        {
            throw std::logic_error{"Can't iterate over an empty OrgChart!"};
        }
        return (Iterator(this->root, "reverse"));
    }

    OrgChart::Iterator OrgChart::reverse_order()
    {
        if (this->root == nullptr)
        {
            throw std::logic_error{"Can't iterate over an empty OrgChart!"};
        }
        node *temp = nullptr;
        return (Iterator(temp, "reverse"));
    }
    OrgChart::Iterator OrgChart::begin_preorder()
    {
        if (this->root == nullptr)
        {
            throw std::logic_error{"Can't iterate over an empty OrgChart!"};
        }
        return (Iterator(this->root, "pre"));
    }

    OrgChart::Iterator OrgChart::end_preorder()
    {
        if (this->root == nullptr)
        {
            throw std::logic_error{"Can't iterate over an empty OrgChart!"};
        }
        node *temp = nullptr;
        return (Iterator(temp, "pre"));
    }

    /* ***** ITERATOR IMPLEMENTATION ***** */

    OrgChart::Iterator::Iterator(node *init, string _type)
        : curr(init), type(std::move(_type))
    {
        if (init != nullptr)
        {
            next = init->head; // not part of the initialization list, because init can be null, and thus we cant access this member without segfaulting.

            if (type == "reverse") // different start offset then the other cases
            {
                bool otherKids = true;
                while (curr->head != nullptr || otherKids)
                {
                    if (curr->head != nullptr)
                    {
                        gotoLeftmostChild();
                    }
                    next = rightKid();
                    if (next != nullptr)
                    {
                        curr = next;
                    }
                    else
                    {
                        otherKids = false;
                    }
                }
                next = curr->parent;
            }
        }
    }

    OrgChart::node *OrgChart::Iterator::rightKid()
    {
        node *it = curr;
        while (it != nullptr)
        {
            if (it->head != nullptr)
            {
                return it;
            }
            it = it->right;
        }

        return it; // same as return nullptr.
    }

    void OrgChart::Iterator::gotoLeftmostChild()
    {
        while (curr->head != nullptr)
        {
            curr = curr->head;
        }
    }

    OrgChart::Iterator &OrgChart::Iterator::operator++()
    {
        if (curr != nullptr)
        {
            if (this->type == "level")
            {
                if (curr != nullptr && curr->right != nullptr)
                {
                    curr = curr->right;
                    if (next == nullptr) // checks for any child nodes that could be missed before exiting.
                    {
                        if (curr->head != nullptr)
                        {
                            next = curr->head;
                        }
                    }
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
                if (curr != nullptr && curr->right != nullptr)
                {
                    curr = curr->right;
                }
                else
                {
                    curr = next;
                    if (curr != nullptr)
                    {
                        next = curr->parent;
                        if (next != nullptr)
                        {
                            while (next->left != nullptr)
                            {
                                next = next->left;
                            }
                        }
                    }
                }
            }

            if (this->type == "pre")
            {
                if (curr != nullptr && curr->head != nullptr)
                {
                    curr = curr->head;
                }
                else if (curr != nullptr && curr->right != nullptr)
                {
                    if (curr->right->parent->val == curr->parent->val) // if right neighbour has the same father node.
                    {
                        curr = curr->right;
                    }
                    else
                    {
                        while (curr->right->parent->val != curr->parent->val) // while curr and right neighbours parents are different.
                        {
                            curr = curr->parent;
                        }
                        if (curr->right != nullptr)
                        {
                            curr = curr->right;
                        }
                    }
                }
                else // this means the iterator reached a tail node in a level and has potentially finished the preoder
                {
                    curr = findAnyUncle();
                }
            }
        }
        return *this;
    }

    OrgChart::node *OrgChart::Iterator::findAnyUncle()
    {
        // TODO: fix the kinks
        node *it = curr;
        while (it != nullptr)
        {
            if (it->right != nullptr)
            {
                return it->right;
            }
            it = it->parent;
        }

        return it; // same as return nullptr.
    }

    OrgChart::Iterator OrgChart::Iterator::operator++(int)
    {
        Iterator it = Iterator(this->curr, this->type);
        ++(*this);
        return it;
    }

    string *OrgChart::Iterator::operator->()
    {
        string *temp = &this->curr->val;
        return temp;
        return &(curr->val);
    }

    string OrgChart::Iterator::operator*()
    {
        return (*curr).val;
    }

    bool OrgChart::Iterator::operator==(const Iterator &other) const
    {

        bool ans = true;
        if (this->curr == nullptr || other.curr == nullptr)
        {
            if (this->curr == nullptr && other.curr == nullptr)
            {
                return ans; // currently true.
            }
            return !ans;
        }
        return (this->curr == other.curr);
    }

    bool OrgChart::Iterator::operator!=(const Iterator &other) const
    {
        return !(*this == other);
    }
}