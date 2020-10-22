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
slist::skipBox::skipBox(const int &data, skipBox *next, skipBox *skip) : data(data), next(next), skip(skip)
{
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
}

slist &slist::operator+=(const int &data)
{
    pushSorted(data);
    return *this;
}