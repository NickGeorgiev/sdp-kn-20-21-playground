#include "Stack.h"

template <class T>
Stack<T>::Stack() : topOfStack{-1} {}

template <class T>
void Stack<T>::push(const T &element)
{
    container.push_back(element);
    topOfStack++;
}

template <class T>
T Stack<T>::pop()
{
    if (topOfStack == -1)
    {
        throw std::out_of_range("No more elements!");
    }
    T removedElement = container[topOfStack--];
    container.pop_back();
    return removedElement;
}

template <class T>
T Stack<T>::top() const
{
    return container[topOfStack];
}

template<class T>
size_t Stack<T>::size() const
{
    return container.size();
}

template <class T>
bool Stack<T>::empty() const
{
    return container.empty();
}