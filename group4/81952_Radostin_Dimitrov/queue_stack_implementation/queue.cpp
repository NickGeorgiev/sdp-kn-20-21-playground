#include <iostream>
#include <stack>
#include "queue.h"

void Queue::tomain()
{
    while (!help.empty())
    {
        main.push(help.top());
        help.pop();
    }
}

void Queue::tohelp()
{
    while (!main.empty())
    {
        help.push(main.top());
        main.pop();
    }
}

int Queue::front()
{
    if (main.empty())
    {
        std::cout << "Queue is empty!\n";
        return -1;
    }
    return main.top();
}

int Queue::tail()
{
    if (main.empty())
    {
        std::cout << "Queue is empty!\n";
        return -1;
    }
    tohelp();
    int end = help.top();
    tomain();
    return end;
}

void Queue::push(int el)
{
    tohelp();
    main.push(el);
    tomain();
}

void Queue::pop()
{
    main.pop();
}
