#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H
#include<iostream>
#include<stack>

template<class T>
class StackQueue
{
private:
    std::stack<T> pushStack{}, popStack{};

public:
    void push_back(const T& x);
    void pop_front();

    T front();
    T back();

    bool empty() const;
    size_t size() const;
};

//============ IMPLEMENTATION

template<class T>
void StackQueue<T>::push_back(const T& x)
{
    pushStack.push(x);
}

template<class T>
void StackQueue<T>::pop_front()
{
    if(size() == 0) return;

    if(popStack.empty())
    {
        while(!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }

    popStack.pop();
}

template<class T>
T StackQueue<T>::front()
{
    if(size() == 0) throw "Empty queue!\n";

    if(popStack.empty())
    {
        while(!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }

    return popStack.top();
}

template<class T>
T StackQueue<T>::back()
{
    if(size() == 0) throw "Empty queue!\n";

    if(pushStack.empty())
    {
        while(!popStack.empty())
        {
            pushStack.push(popStack.top());
            popStack.pop();
        }
    }
    
    return pushStack.top();    
}

template<class T>
bool StackQueue<T>::empty() const
{
    return size() == 0;
}

template<class T>
size_t StackQueue<T>::size() const
{
    return pushStack.size() + popStack.size();
}

#endif