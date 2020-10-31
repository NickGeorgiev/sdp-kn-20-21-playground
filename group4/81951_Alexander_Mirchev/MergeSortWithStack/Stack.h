#ifndef __STACK_HH__
#define __STACK_HH__

#include <iostream>
#include <vector>

/*
    From the repo. TODO as LinkedListWrapper
*/
template <class T>
class Stack
{
    std::vector<T> container;
    int topOfStack;

public:
    Stack();
    void push(const T &element);
    T pop();
    T top() const;
    size_t size() const;
    bool empty() const;
};

#include "Stack.cpp"
#endif