#include"list.h"
#include<iostream>

List::List():first(nullptr), last(nullptr){}

List::List(const List& other)
{
    copy(other);
}

List& List::operator=(const List& other)
{
   if (this != &other)
   {
        copy(other);
   }
   return *this;
}

List::~List()
{
   clear();
}

void List::copy(const List& other)
{
    Box* toCopy = other.first;
    Box* previousCopied = nullptr;
    
    if(other.first)
        {
        this->first = new Box(other.first->data);
        toCopy = toCopy->next;
        previousCopied = this->first;

        while(toCopy)
        {
            previousCopied->next = new Box(toCopy->data);
            toCopy = toCopy->next;
            previousCopied = previousCopied->next;
        }
        this->last = previousCopied;
    }
}

void List::clear()
{
   while(this->first)
   {
       pop();
   }
}

void List::push(const int& other)
{
    this->first = new Box(other, this->first);
    if (!this->last)
    {
        this->last = this->first;
    }
}

void List::pop()
{
    Box* saver = this->first->next;
    delete this->first;
    this->first = saver;
}

void List::print() const
{
    Box* current = this->first;
    while(current)
    {
        std::cout<<current->data<<" ";
        current = current->next;
    }
    std::cout<<std::endl;
}

Box* List::locate(size_t index)
{
    Box* curr = this->first;
    while(curr && index > 0)
    {
        --index;
        curr = curr->next;
    }
    return curr;
}

void List::insertAt(const int& other, size_t index) 
{
    if(!this->first || index == 0)
    {
      push(other);
      return;
    }
    Box* previous = locate(index - 1);    
    Box* newElem = new Box(other, previous->next);
    previous->next = newElem;
}

void List::deleteAt(size_t index)
{
    if(index == 0) 
    {
        pop();
        return;
    }
    Box* previous = locate(index - 1);
    Box* saver = previous->next;
    previous->next = previous->next->next;
    delete saver;
}

int List::count(int x) const
{
    Box* curr = this->first;
    int counter = 0;

    while(curr)
    {
        if(curr->data == x) counter++;
        curr = curr->next;
    }
    return counter;
}

void List::push_back(const int& other)
{   
    if(this->first)
    {
        this->last = this->last->next = new Box(other,nullptr);
    }
    else
    {
        push(other);
    }    
}

void List::operator+=(const int& other)
{
    push_back(other);
}

int List::get_ith(int n)
{
    Box* curr = this->first;
    while(curr && (n - 1) > 0)
    {
        n--;
        curr = curr->next;
    }
    return curr->data;
}

void List::removeAll(int x)
{
    if(this->first)
    {
        Box* previous = this->first;   
        while(previous->next)
        {     
            Box* saver = previous->next;
            if(saver->data == x)
            {
                previous->next = previous->next->next;
                delete saver;
            }
            else
            {
                 previous = previous->next;
            }      
        }
    }
}

void List::append(const List& list2)
{
    Box* helper = list2.first;
    while(helper)
    {
        push_back(helper->data);
        helper = helper->next;
    }
}

void List::operator+=(const List& other)
{
    append(other);
}

List List::concat(const List& other)
{
    List newList(*this);
    newList+=other;
    return newList;
}

List List::operator+(const List& other)
{
    List newList = concat(other);
    return newList;
}

void List::reverse()
{
    Box* prev = nullptr;
    Box* next = nullptr;
    Box* curr = this->first;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    this->first = prev;
}
