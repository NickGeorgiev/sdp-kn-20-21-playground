#include "QueueWithTwoStacks.h"

template <class T>
Queue<T>::Queue()
{
    dataStack = std::stack<T>();
    helperStack = std::stack<T>();
}

template <class T>
void Queue<T>::push(const T &element)
{
    while (!dataStack.empty())
    {
        helperStack.push(dataStack.top());
        dataStack.pop();
    }

    dataStack.push(element);

    while (!helperStack.empty())
    {
        dataStack.push(helperStack.top());
        helperStack.pop();
    }
}

template <class T>
T Queue<T>::pop()
{
    T &result = dataStack.top();
    dataStack.pop();
    return result;
}

template <class T>
T Queue<T>::top() const
{
    return dataStack.top();
}

template <class T>
size_t Queue<T>::size() const
{
    return dataStack.size();
}

template <class T>
bool Queue<T>::empty() const
{
    return dataStack.empty();
}