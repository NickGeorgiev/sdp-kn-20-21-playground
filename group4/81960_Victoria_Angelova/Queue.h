#ifndef __QUEUE_H
#define __QUEUE_H

#include<stack>

template <class T>
class Queue {
private:
    std::stack<T> firstStack, secondStack;

    void moveQueue(std::stack<T>&, std::stack<T>&);

public:
    void push (T);
    T pop ();

    int getSize () const;

    T front ();
    T tail ();
};


#endif
