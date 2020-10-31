#ifndef __QUEUE_WITH_STACKS__
#define __QUEUE_WITH_STACKS__

#include <stack>

template <class T>
class Queue
{
private:
    std::stack<T> dataStack;
    std::stack<T> helperStack;

public:
    Queue();
    void push(const T &element);
    T pop();
    T top() const;
    size_t size() const;
    bool empty() const;
};

#include "QueueWithTwoStacks.cpp"
#endif
