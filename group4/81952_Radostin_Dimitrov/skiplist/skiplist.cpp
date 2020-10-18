#include <iostream>
#include <cmath>
#include "skiplist.h"

void Skip_List::copy(const Skip_List &other)
{

    if (other.size == 0)
    {
        start = nullptr;
        last = nullptr;
        size = 0;
    }
    else

    {

        start = new Element(other.start->data, nullptr, nullptr);

        Element *curr = other.start->next;
        last = start;

        size = 1;

        while (curr)
        {

            insert(curr->data);

            curr = curr->next;
        }
        optimise_skip_list();
    }
}
void Skip_List::destroy()
{
    while (start)
    {
        Element *temp_start = start;
        start = start->next;
        delete temp_start;
    }
}

Skip_List::Skip_List()
{
    start = nullptr;
    last = nullptr;
    size = 0;
}

Skip_List::Skip_List(const Skip_List &other)
{
    copy(other);
}

Skip_List::~Skip_List()
{
    destroy();
}

Skip_List &Skip_List::operator=(const Skip_List &other)
{
    if (this != &other)
    {

        destroy();

        copy(other);
    }
    return *this;
}

Element *Skip_List::find_prev_member(const int &_data)
{
    Element *curr = start;

    bool find_prev_member = false;

    if (!start || start->data >= _data)
    {

        return nullptr;
    }

    if (last->data <= _data)
    {

        return last;
    }

    while (find_prev_member == false && curr)
    {

        if (curr->data < _data && curr->skip_step->data > _data)
        {
            find_prev_member = true;

            while (curr->next->data <= _data)
            {

                curr = curr->next;
            }
        }

        else if (curr->skip_step)
        {

            curr = curr->skip_step;
        }
    }

    return curr;
}

void Skip_List::optimise_skip_list()
{

    int curNum = 0, sqrt_of_size = sqrt(size);

    Element *curr = start->next;
    Element *prev = start;

    while (curr)
    {
        curr->skip_step = nullptr;
        curNum++;

        if (curNum % sqrt_of_size == 0 || curNum + 1 == size)
        {
            prev->skip_step = curr;
            prev = curr;
        }
        curr = curr->next;
    }
}

void Skip_List::add_to_start(const int &_data)
{
    if (!start)
    {

        start = last = new Element(_data, nullptr, nullptr);
    }
    else
    {

        Element *newElement = new Element(_data, start, nullptr);

        start = newElement;
    }
    size++;
    optimise_skip_list();
}

void Skip_List::insert(const int &_data)
{

    Element *_prevElement = find_prev_member(_data);

    if (!_prevElement)
    {
        add_to_start(_data);
        return;
    }

    Element *newElement = new Element(_data, _prevElement->next, nullptr);

    _prevElement->next = newElement;
    if (_prevElement == last)
    {
        last = newElement;
    }
    size++;

    optimise_skip_list();
}

void Skip_List::print() const
{
    Element *curr = start;

    while (curr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void Skip_List::print_skip() const
{
    Element *curr = start;

    while (curr)
    {
        std::cout << curr->data << " ";
        curr = curr->skip_step;
    }
    std::cout << std::endl;
}
