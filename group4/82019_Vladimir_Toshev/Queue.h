#ifndef _Queue_Stacks_HH
#define _Queue_Stacks_HH
#include <iostream>
#include <stack>

template <class T>

class Queue
{
private:
    std::stack<T> proper, reversed;

    void reverse(std::stack<T> &first, std::stack<T> &second)
    {

        while (!first.empty())
        {
            second.push(first.top());
            first.pop();
        }
    }
    void verify()
    {
        if (empty())
        {
            throw std::out_of_range("No more elements");
        }
    }

public:
    Queue(){};

    bool empty()
    {
        return proper.empty();
    }

    T front()
    {
        verify();

        reverse(proper, reversed);
        T toReturn = reversed.top();
        reverse(reversed, proper);

        return toReturn;
    }

    T tail()
    {
        verify();

        return proper.top();
    }

    void push(const T &element)
    {
        proper.push(element);
    }

    void pop()
    {
        verify();

        reverse(proper, reversed);
        reversed.pop();
        reverse(reversed, proper);
    }
};

#endif