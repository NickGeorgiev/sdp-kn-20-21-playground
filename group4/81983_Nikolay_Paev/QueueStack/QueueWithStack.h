#include<iostream>
#include<stack>

template<class T>
class Queue {
    std::stack<T> toPush;
    std::stack<T> toPop;
    bool readyToPush;

    void copyFromTo(std::stack<T>& first, std::stack<T>& second);
    void prepareToPop();
    void prepareToPush();

    public:
    void push(const T& el);
    T back();
    T front();
    void pop();
    bool empty();
};
