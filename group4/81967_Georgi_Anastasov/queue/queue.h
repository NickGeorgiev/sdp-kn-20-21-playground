#ifndef QUEUE_H
#define QUEUE_H
#include <stack>

class Queue
{
private:
    std::stack<int> first_stack;
    std::stack<int> second_stack;

    void swap_stacks();
    void first_need();
    void second_need();

public:
    int front();
    int tail();
    void push(const int &);
    void pop();

    void print();
};

#endif
