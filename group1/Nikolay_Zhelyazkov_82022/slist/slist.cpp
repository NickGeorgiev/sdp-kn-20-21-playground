#include "slist.h"
#include <cmath>
slist::slist(comparator c) : first(nullptr), count(0), c(c)
{
}

slist::slist(const slist &other)
{
    copy(other);
}

void slist::copy(const slist &other)
{
    slist::skipBox *crr = other.first, *last = nullptr;
    first = nullptr;
    count = 0;
    if (crr == nullptr)
    {
        return;
    }
    first = new slist::skipBox(crr->data, nullptr, nullptr);
    last = first;
    crr = crr->next;
    count = 1;

    while (crr != nullptr)
    {
        last->next = new slist::skipBox(crr->data, nullptr, nullptr);
        last = last->next;
        crr = crr->next;
        ++count;
    }
}
slist::~slist()
{
    clear();
}
void slist::clear()
{
    slist::skipBox *crr = first, *save;
    while (crr != nullptr)
    {
        save = crr;
        crr = crr->next;
        delete save;
    }
}

slist &slist::operator=(const slist &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}
slist &slist::operator+=(const int &data)
{
    pushSorted(data);
    return *this;
}
slist::skipBox::skipBox(const int &data, skipBox *next, skipBox *skip) : data(data), next(next), skip(skip)
{
}
size_t slist::size() const
{
    return count;
}
bool slist::member(const int &_data) const
{
    if (first == nullptr)
    {
        return false;
    }
    slist::skipBox *crr = first;
    while (crr->skip != nullptr && c(crr->skip->data, _data))
    {
        crr = crr->skip;
    }
    while (crr != nullptr && crr->data != _data)
    {
        crr = crr->next;
    }
    return crr != nullptr;
}
typename slist::skipBox *slist::locate(const int &data) const
{
    if (first == nullptr || !c(first->data, data))
    {
        return nullptr;
    }
    slist::skipBox *crr = first;
    while (crr->next != nullptr && c(crr->next->data, data))
    {
        crr = crr->next;
    }
    return crr;
}
void slist::skipping()
{
    slist::skipBox *crr = first, *lastCrr = first;
    size_t br = 0;

    while (crr != nullptr)
    {
        crr = crr->next;
        ++br;
        if (br >= sqrt(size()))
        {
            lastCrr->skip = crr;
            lastCrr = crr;
            br = 0;
        }
    }
}
void slist::pushSorted(const int &data)
{

    count++;

    slist::skipBox *el = locate(data);

    if (el == nullptr)
    {
        first = new slist::skipBox(data, first, nullptr);
        return;
    }

    el->next = new slist::skipBox(data, el->next, nullptr);
    skipping();
}

std::ostream &operator<<(std::ostream &out, const slist &list)
{

    typename slist::skipBox *current = list.first;
    while (current != nullptr)
    {
        out << current->data << " ";
        current = current->next;
    }

    std::cout << "\nSkippers: ";
    // typename slist::skipBox *currentSkip = list.first;
    // while (current != nullptr)
    // {
    //     out << current->data << " ";
    //     current = current->skip;
    // }
    return out;
}
bool slist::find(int elem)
{
    if (!first)
    {
        return false;
    }

    typename slist::skipBox *current = first;
    while (current->skip && current->skip->data < elem)
    {
        std::cout << current->data << " ";

        current = current->skip;
    }
    typename slist::skipBox *end = current->skip;
    while (current)
    {
        std::cout << current->data << " ";
        if (current->data == elem)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}
