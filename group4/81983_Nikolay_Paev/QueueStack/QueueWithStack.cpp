#include<iostream>
#include<stack>

#include"QueueWithStack.h"


template<class T>
void Queue<T>::copyFromTo(std::stack<T>& first, std::stack<T>& second) {
    while(!first.empty()) {
        T curr = first.top(); first.pop();
        second.push(curr);
    }
}

template<class T>
void Queue<T>::prepareToPop() {
    copyFromTo(toPush,toPop);
    readyToPush = false;
}

template<class T>
void Queue<T>::prepareToPush() {
    copyFromTo(toPop,toPush);
    readyToPush = true;
}

template<class T>
void Queue<T>::push(const T& el) {
    if(!readyToPush) {
        prepareToPush();
    }
    toPush.push(el);
}

template<class T>
T Queue<T>::back() {
    if(!readyToPush) {
        prepareToPush();
    }
    if(empty()) {
        throw std::runtime_error("Empty queue!");
    }
    return toPush.top();
}

template<class T>
T Queue<T>::front() {
    if(readyToPush) {
        prepareToPop();
    }
    if(empty()) {
        throw std::runtime_error("Empty queue!");
    }
    return toPop.top();
}

template<class T>
void Queue<T>::pop() {
    if(readyToPush) {
        prepareToPop();
    }
    toPop.pop();
}

template<class T>
bool Queue<T>::empty() {
    return toPush.empty() && toPop.empty();
}
