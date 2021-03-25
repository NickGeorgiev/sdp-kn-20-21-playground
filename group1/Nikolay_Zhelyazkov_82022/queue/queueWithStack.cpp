#include "queueWithStack.h"

QueueWithStack::QueueWithStack()
{
}
// QueueWithStack::QueueWithStack(std::initializer_list<int> l) : QueueWithStack()
// {

// }
QueueWithStack::QueueWithStack(const QueueWithStack &other)
    : pushStack(other.pushStack), popStack(other.popStack)
{
}
void QueueWithStack::prePop()
{
    if (popStack.empty())
    {
        while (!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }
}
void QueueWithStack::prePush()
{
    if (pushStack.empty())
    {
        while (!popStack.empty())
        {
            pushStack.push(popStack.top());
            popStack.pop();
        }
    }
}
void QueueWithStack::popFront()
{
    prePop();
    popStack.pop();
}
void QueueWithStack::pushBack(const int &data)
{
    pushStack.push(data);
}
int QueueWithStack::front()
{
    if (empty())
    {
        throw std::runtime_error("No elements");
    }
    prePop();
    return popStack.top();
}
int QueueWithStack::back()
{
    if (empty())
    {
        throw std::runtime_error("No elements");
    }
    prePush();
    return pushStack.top();
}
size_t QueueWithStack::size() const
{
    return pushStack.size() + popStack.size();
}
bool QueueWithStack::empty() const
{
    return pushStack.empty() && popStack.empty();
}

void QueueWithStack::copy(const QueueWithStack &other)
{
    pushStack = other.pushStack;
    popStack = other.popStack;
}
void QueueWithStack::clear()
{
    while (!pushStack.empty())
    {
        pushStack.pop();
    }
    while (!popStack.empty())
    {
        popStack.pop();
    }
}
QueueWithStack &QueueWithStack::operator=(const QueueWithStack &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, QueueWithStack &q)
{
    while (!q.empty())
    {
        out << q.front() << " ";
        q.popFront();
    }
    return out;
}
