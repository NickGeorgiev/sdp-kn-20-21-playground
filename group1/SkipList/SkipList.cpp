#include "SkipList.h"
#include <vector>

SkipList::SkipList(const SkipList &other)
{
    copy(other);
}

SkipList::SkipList()
{
    first = nullptr;
    last = nullptr;
    list_size = 0;
}

SkipList::~SkipList()
{
    clear();
}

void SkipList::push(const int& element)
{
    list_size++;
    if(first == nullptr){
        first = new box(element, nullptr, nullptr, nullptr);
        last = first;

        optimize();
        return;
    }

    SkipList::box* crr = locate(element);

    crr->next = new box(element, crr->next, crr, nullptr);
    if(crr->next->next != nullptr) crr->next->next->prev = crr->next;

    if(last->next != nullptr) last = last->next;
    if(first->prev != nullptr) first = first->prev;

    optimize();
}

void SkipList::reverse()
{
    if(first == nullptr || first == last) return;

    for(size_t i = 0; i < size() / 2; ++i)
    {
       box* crr1 = first, * crr2 = last;

        for(size_t j = 0; j < i; ++j)
        {
            crr1 = crr1->next;
            crr2 = crr2->prev;
        }

        int temp = crr1->data;
        crr1->data = crr2->data;
        crr2->data = temp;
    }
}

void SkipList::print() const
{
    box *crr = first;
    while (crr != nullptr)
    {
        std::cout << crr->data << " -> ";
        crr = crr->next;
    }
    std::cout << std::endl;
}

void SkipList::clear()
{
    if (first == nullptr)
        return;

    box *crr = first;

    while (crr != nullptr)
    {
        typename SkipList::box *save = crr;
        crr = crr->next;
        delete save;
    }
    first = last = nullptr;
    list_size = 0;
}

void SkipList::optimize()
{
    clear_skip_steps();

    box* crr = first, *temp = first;
    size_t count = 0;

    while(crr != nullptr)
    {
        crr = crr->next;
        ++count;

        if(count >= sqrt(size())){
            temp->skip = crr;
            temp = crr;
            count = 0;
        }
    }

}

void SkipList::copy(const SkipList &other)
{
    clear();
    if (other.first == nullptr)
        return;

    box *crr = other.first;
    while (crr != nullptr)
    {
        push(crr->data);
        crr = crr->next;
    }
}

int SkipList::size()
{
    return list_size;
}

typename SkipList::box* SkipList::locate(const int &element) const
{
    if(first == nullptr || first->data > element) return nullptr;

    box* crr = first;

    while(crr->next != nullptr && crr->next->data < element)
    {
        crr = crr->next;
    }

    return crr;
}

void SkipList::clear_skip_steps()
{
    if(first == nullptr) return;

    box* crr = first;

    while(crr != nullptr)
    {
        box* save = crr;
        crr = crr->skip;
        save->skip = nullptr;
    }
}

bool SkipList::member(const int& element) const
{
    if(first == nullptr) return false;
    if(first == last && first->data == element) return true;

    box* crr = first;

    while(crr->skip != nullptr && crr->skip->data < element)
    {
        crr = crr->skip;
    }

    while(crr != nullptr && crr->data != element)
    {
        crr = crr->next;
    }

    return crr != nullptr;
}

SkipList &SkipList::operator=(const SkipList &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
} 