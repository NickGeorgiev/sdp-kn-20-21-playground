#include"list.h"
#include<iostream>

List::List()
{
   first = nullptr;
}

List::List(const List& other)
{
    copy(other);
}

List& List::operator=(const List& other)
{
   copy(other);
   return *this;
}

List::~List()
{
   clear();
}

void List::copy(const List& other)
{
    box* toCopy = other.first;
    box* previousCopied = nullptr;
    
    if(other.first == nullptr)
    {
        first = nullptr;
        return;
    }
    this->first = new box(other.first->data);
    toCopy = toCopy->next;
    previousCopied = this->first;
    
    while(toCopy != nullptr)
    {
        previousCopied->next = new box(toCopy->data);
        toCopy = toCopy->next;
        previousCopied = previousCopied->next;
    }
}

void List::clear()
{
   while(this->first != nullptr)
   {
       pop();
   }
}

void List::push(const int& other)
{
    box* newBox = new box;
    newBox->data = other;
    newBox->next = this->first;
    this->first = newBox;
}

void List::pop()
{
    box* saver = this->first->next;
    delete this->first;
    this->first = saver;
}

void List::print() const
{
    box* current = this->first;
    while(current != nullptr)
    {
        std::cout<<current->data<<std::endl;
           std::cout<<current->next;
        current = current->next;
        if(current != nullptr)
        {
            std::cout<<"-------->";
        }
    }
    std::cout<<std::endl;
}

box* List::locate(size_t index)
{
    box* curr = this->first;
    while(curr != nullptr && index > 0)
    {
        --index;
        curr = curr->next;
    }
    return curr;
}

void List::insertAt(const int& other, size_t index)
{
    if(this->first == nullptr || index == 0)
    {
      (*this).push(other);
      return;
    }
    box* previous = (*this).locate(index - 1);
    
    box* newElem = new box;
    newElem->data = other;
    newElem->next = previous->next;
    previous->next = newElem;
}

void List::deleteAt(size_t index)
{
    if(index == 0) 
    {
        pop();
        return;
    }
    box* previous = (*this).locate(index - 1);
    box* saver = previous->next;
    previous->next = previous->next->next;
    delete saver;
}

int List::count(int x)
{
    box* curr = this->first;
    int counter = 0;

    while(curr != nullptr)
    {
        if(curr->data == x) counter++;
        curr = curr->next;
    }
    return counter;
}

void List::push_back(const int& other)
{
int counter = 0;
 box* last = this->first;
    while(last != nullptr)
    {
       counter ++;
       last = last->next;
    }
(*this).insertAt(other, counter);
}

void List::operator+=(const int& other)
{
    (*this).push_back(other);
}

int List::get_ith(int n)
{
    box* curr = this->first;
    while(curr != nullptr && (n - 1) > 0)
    {
        n--;
        curr = curr->next;
    }
    return curr->data;
}


void List::removeAll(int x)
{
    if(this->first == nullptr)
    {
        return;
    }
    box* previous = this->first;
   
    while(previous->next != nullptr)
    {     
        box* saver = previous->next;
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

void List::append(const List& list2)
{
    box* helper = list2.first;
    while(helper != nullptr)
    {
        (*this).push_back(helper->data);
        helper = helper->next;
    }
}

void List::operator+=(const List& other)
{
    (*this).append(other);
}

List List::concat(const List& other)
{
    List newList;
    newList+=(*this);
    newList+=other;
    return newList;
}

List List::operator+(const List& other)
{
    List newList = (*this).concat(other);
    return newList;
}

void List::reverse()
{
box* prev = nullptr;
box* next = nullptr;
box* curr = this->first;
while(curr != nullptr)
{
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
this->first = prev;
}
