#ifndef __QUEUE_H
#define __QUEUE_H

#include<stack>


class Queue
{
    std::stack<int> main;
    std::stack<int> help;

    void tomain();
    void tohelp();

public:
    int front();
    int tail();
    void push(int el);
    void pop();
};


#endif
