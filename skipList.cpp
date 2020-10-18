#ifndef SKIPLIST_CPP
#define SKIPLIST_CPP
#include <iostream>
#include <cmath>
#include "skipList.h"

SkipList::SkipList() : first{nullptr}, last{nullptr}
{
}


SkipList::~SkipList()
{
    clear();
}


void SkipList::clear()
{
    SkipList::Node *previous;

    SkipList::Node *start = first;


    while (start)
    {
        previous = start;

        start = start->next;

        delete previous;

    }
}



void SkipList::copy(const SkipList &otherList)
{

    SkipList::Node *current = otherList.first;

    SkipList::Node *currentNewList = new SkipList::Node(current->value);

    first = currentNewList;

    SkipList::Node *nextNewList;

    current = current->next;


    while (current)
    {
        nextNewList = new SkipList::Node(current->value);

        currentNewList->next = nextNewList;

        currentNewList = nextNewList;

        current = current->next;
    }


    last = currentNewList;

    addSkips(membersNumber());
}


SkipList::SkipList(const SkipList &otherList)
{
    copy(otherList);
}


SkipList &SkipList::operator=(const SkipList &otherList)
{
    if (this != &otherList)
    {
        clear();

        copy(otherList);
    }

    return *this;
}


void SkipList::addMember(const int &newElValue)
{
    int count = membersNumber();

    SkipList::Node *newEl = new SkipList::Node(newElValue);

    ++count;

    int skipSpace = std::sqrt(count);

    if (count == 1)
    {
        first = newEl;

        last = newEl;

        newEl->next = nullptr;

        newEl->skip = nullptr;
    }

    else if (count == 2)
    {
        if (first->value < newEl->value)
        {
            first->next = newEl;

            first->skip = newEl;

            last = newEl;
        }
        else
        {
            last = first;

            first = newEl;

            first->next = last;

            first->skip = last;
        }
    }

    else if (count > 2)
    {

        if (newElValue >= last->value)
        {
            last->next = newEl;

            last = newEl;
        }
        else if (newElValue <= first->value)
        {
            newEl->next = first;

            first = newEl;
        }
        else
        {
            SkipList::Node *current = locateNewElement(newElValue);

            newEl->next = current->next;

            current->next = newEl;
        }

        deleteSkips();

        addSkips(count);
    }
}

int SkipList::membersNumber() const
{
    int count = 0;
    SkipList::Node *previous = first;
    while (previous)
    {
        previous = previous->next;

        count++;
    }
    return count;
}

typename SkipList::Node *SkipList::locateNewElement(const int &newElValue) const
{
    SkipList::Node *current = first;

    while (current && current->value <= newElValue)
    {

        if (current->value == newElValue || (current->value < newElValue && current->next->value > newElValue))
            return current;

        if (current->skip != nullptr && current->skip->value <= newElValue)
            current = current->skip;

        else if (current->next != nullptr && current->next->value <= newElValue)
            current = current->next;
    }
    return current;
}

void SkipList::deleteSkips()
{
    typename SkipList::Node *current;
    while (current)
    {
        current->skip = nullptr;

        current = current->next;
    }
}

void SkipList::addSkips(const int &membersNumber)
{
    typename SkipList::Node *current = first, *skip = first;

    int count = 0;

    int skipStep = std::sqrt(membersNumber);

    while (skip)
    {
        if (count >= 1 && (count % skipStep == 0 || !skip->next))
        {
            current->skip = skip;

            current = skip;
        }
        skip = skip->next;

        ++count;
    }
}


void SkipList::printList() const
{
    SkipList::Node *current = first;

    std::cout << "List : ";

    while (current)
    {
        std::cout << current->value << " ";
        current = current->next;
    }

    std::cout << std::endl;
}


void SkipList::printSkips() const
{
    SkipList::Node *current = first;

    std::cout << "Skips : ";

    while (current)
    {
        std::cout << current->value << " ";

        current = current->skip;
    }
    
    std::cout << std::endl;
}
#endif