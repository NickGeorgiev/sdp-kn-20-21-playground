#include <iostream>
#include <vector>
#include <exception>

template<class T>
class Stack
{
private:
    std::vector<T> data;
    size_t length;

    void clear();
public:
    Stack();
    Stack(const Stack&);
    ~Stack();

    void push(const T);
    void pop();
    T top();

    const bool empty() const;
    const size_t size() const;

    void operator=(const Stack&);
};

template<class T>
Stack<T>::Stack(): data(), length(0) {}

template<class T>
Stack<T>::Stack(const Stack& other): data(other.data), length(other.length) {}

template<class T>
Stack<T>::~Stack()
{
    clear();
}

template<class T>
void Stack<T>::clear()
{
    data.clear();
}

template<class T>
void Stack<T>::push(const T toAdd)
{
    data.push_back(toAdd);
    length++;
}

template<class T>
void Stack<T>::pop()
{
    try
    {
        if(!empty())
        {
            data.pop_back();
            length--;
        }
        else
        {
            throw std::runtime_error("Stack Empty!");
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template<class T>
T Stack<T>::top()
{
    try
    {
        if(!length)
        {
            throw std::runtime_error("Stack Empty!");
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    return data.back();
}

template<class T>
const bool Stack<T>::empty() const
{
    return !length;
}

template<class T>
const size_t Stack<T>::size() const
{
    return length;
}

template<class T>
void Stack<T>::operator=(const Stack& other)
{
    data = other.data;
    length = other.length;
}
