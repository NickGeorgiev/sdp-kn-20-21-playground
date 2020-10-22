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