#include "slist.h"
#include <cmath>
Slist::Slist(comparator c) : first(nullptr), count(0), c(c)
{
}

Slist::Slist(const Slist &other)
{
    copy(other);
}

void Slist::copy(const Slist &other)
{
    Slist::skipBox *crr = other.first, *last = nullptr;
    first = nullptr;
    count = 0;
    if (crr == nullptr)
    {
        return;
    }
    first = new Slist::skipBox(crr->data, nullptr, nullptr);
    last = first;
    crr = crr->next;
    count = 1;

    while (crr != nullptr)
    {
        last->next = new Slist::skipBox(crr->data, nullptr, nullptr);
        last = last->next;
        crr = crr->next;
        ++count;
    }
}
Slist::~Slist()
{
    clear();
}
void Slist::clear()
{
    Slist::skipBox *crr = first, *save;
    while (crr != nullptr)
    {
        save = crr;
        crr = crr->next;
        delete save;
    }
}
Slist::skipBox::skipBox(const int &data, skipBox *next, skipBox *skip) : data(data), next(next), skip(skip)
{
}
Slist &Slist::operator=(const Slist &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

size_t Slist::size() const
{
    return count;
}

bool Slist::member(const int &_data) const
{
    if (first == nullptr)
    {
        return false;
    }
    Slist::skipBox *crr = first;
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

typename Slist::skipBox *Slist::locate(const int &data) const
{
    if (first == nullptr || !c(first->data, data))
    {
        return nullptr;
    }
    Slist::skipBox *crr = first;
    while (crr->next != nullptr && c(crr->next->data, data))
    {
        crr = crr->next;
    }
    return crr;
}
void Slist::pushSorted(const int &data)
{

    count++;

    Slist::skipBox *el = locate(data);

    if (el == nullptr)
    {
        first = new Slist::skipBox(data, first, nullptr);
        return;
    }

    el->next = new Slist::skipBox(data, el->next, nullptr);
    optimise();
}

Slist &Slist::operator+=(const int &data)
{
    pushSorted(data);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Slist &list)
{

    typename Slist::skipBox *current = list.first;
    while (current != nullptr)
    {
        out << current->data << " ";
        current = current->next;
    }
    return out;
}
void Slist::optimise()
{
    Slist::skipBox *crr = first, *lastCrr = first;
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