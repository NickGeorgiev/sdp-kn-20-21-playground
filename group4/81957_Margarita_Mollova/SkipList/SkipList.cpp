#include "SkipList.h"

#include <cmath>

void SkipList::copySkipList (const SkipList& other)
{
    if (!other.start)
    {
        start = nullptr;
        size = 0;
        return;
    }

    start = new Node (other.start->data, nullptr);
    Node* previous = start;
    size = 1;

    Node* current = other.start->next;
    while (current)
    {
        addElementAt(current->data, previous);
        previous = previous->next;
        current = current->next;
    }

    optimize();
}

void SkipList::deleteSkipList ()
{
    while (start)
    {
        Node* previous = start;
        start = start->next;
        delete previous;
        size--;
    }
}

SkipList::SkipList (): start {nullptr}, size {0} {}
SkipList::SkipList (const SkipList& other)
{
    this->copySkipList(other);
}

SkipList::~SkipList ()
{
    this->deleteSkipList();
}

SkipList& SkipList::operator = (const SkipList& other)
{
    if (this != &other)
    {
        this->deleteSkipList();
        this->copySkipList(other);
    }

    return *this;
}

size_t SkipList::getSize () const
{
    return size;
}

size_t SkipList::getNumSkipElements () const
{
    int numSkips = 0;
    Node* current = start;
    while (current)
    {
        current = current->skip;
        numSkips++;
    }
    return numSkips;
}

SkipList::Node* SkipList::locate (const int& elem) const
{
    if (!start || start->data > elem)
    {
        return nullptr;
    }

    Node* current = start;
    while (current->skip && current->skip->data <= elem)
    {
        current = current->skip;
    }

    while (current->next && current->next->data <= elem)
    {
        current = current->next;
    }

    return current;
}

void SkipList::optimize ()
{
    int skipNum = sqrt(size), curNum = 0;
    Node* current = start->next;
    Node* prevToSkip = start;

    while (current)
    {
        current->skip = nullptr;
        curNum++;
        if (curNum % skipNum == 0 || curNum+1 == size)
        {
            prevToSkip->skip = current;
            prevToSkip = current;
        }

        current = current->next;
    }
}

void SkipList::addElementAt (const int& elem, Node*& at)
{
    if (!at)
    {
        start = new Node (elem, start);
    }
    else
    {
        at->next = new Node (elem, at->next);
    }

    size++;
}

void SkipList::addElement (const int& elem)
{
    Node* at = locate(elem);
    addElementAt(elem, at);
    optimize();
}

void SkipList::printSkipList () const
{
    Node* current = start;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void SkipList::printSkipping () const
{
    Node* current = start;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->skip;
    }
    std::cout << std::endl;
}