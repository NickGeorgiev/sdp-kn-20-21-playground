#ifndef _HISTORYQUEUE
#define _HISTORYQUEUE

#include <iostream>
#include <assert.h>
#include <stack> //To remove after tests
#include "../Stack/Stack.h"

template<class T>
class Queue
{
private:
    std::stack<T> inputStack;
    std::stack<T> outputStack;

    void update();
    void tellInput();

public:

    Queue();
    Queue(const Queue&);
    ~Queue();

    bool empty();
    size_t size();

    void push(const T&);
    void pop();
    T front();
    T back();

    void operator= (const Queue*);
};

template<class T>
Queue<T>::Queue(){}

template<class T>
Queue<T>:: Queue(const Queue<T>& other): inputStack(other.inputStack), outputStack(other.outputStack) {}

template<class T>
Queue<T>::~Queue(){}

template<class T>
void Queue<T>::update()
{
    while (!inputStack.empty())
    {
        outputStack.push(inputStack.top());
        inputStack.pop();
    }
}

template<class T>
void Queue<T>::tellInput()
{
    while (!outputStack.empty())
    {
        inputStack.push(outputStack.top());
        outputStack.pop();
    }
}


template<class T>
bool Queue<T>::empty()
{
    return inputStack.empty() && outputStack.empty();
}

template<class T>
size_t Queue<T>::size()
{
    return inputStack.size() + outputStack.size();
}

template<class T>
void Queue<T>::push(const T& data)
{
    if(outputStack.empty())
    {
        inputStack.push(data);
        outputStack.push(data);
    }
    else
    {
        inputStack.push(data);
    }
    
}

template<class T>
void Queue<T>::pop()
{
    if(outputStack.empty())
    {
        update();
    }

    if (!outputStack.empty())
    {
        outputStack.pop();
    }
}

template<class T>
T Queue<T>::front()
{
    if(outputStack.empty())
    {
        update();
    }

    return outputStack.top();
}

template<class T>
T Queue<T>::back()
{
    if(inputStack.empty())
    {
        tellInput();
    }
     return inputStack.top();
}

template<class T>
void Queue<T>::operator= (const Queue<T>* other)
{
    inputStack = other->inputStack;
    outputStack = other->outputStack;
}

#endif
