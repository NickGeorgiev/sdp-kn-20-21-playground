#include "queue.h"
#include <iostream>

void Queue::swap_stacks()
{
    if (second_stack.empty())
    {
        while (!first_stack.empty())
        {
            second_stack.push(first_stack.top());
            first_stack.pop();
        }
    }
    else
    {
        while (!second_stack.empty())
        {
            first_stack.push(second_stack.top());
            second_stack.pop();
        }
    }
}

void Queue::first_need()
{
    if (first_stack.empty())
    {
        swap_stacks();
    }
}

void Queue::second_need()
{
    if (second_stack.empty())
    {
        swap_stacks();
    }
}

int Queue::front()
{
    second_need();

    return second_stack.top();
}

int Queue::tail()
{
    first_need();

    return first_stack.top();
}
void Queue::push(const int &new_element)
{
    first_need();

    first_stack.push(new_element);
}
void Queue::pop()
{
    second_need();

    second_stack.pop();
}

void Queue::print()
{
    first_need();

    while (!first_stack.empty())
    {
        std::cout << first_stack.top() << std::endl;
        first_stack.pop();
    }
}
