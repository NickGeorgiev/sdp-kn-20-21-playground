#include "Queue.h"
#include<iostream>

template <class T>
void Queue<T>::moveQueue(std::stack<T> &from, std::stack<T> &to) {
    while (!from.empty()) {
        to.push(from.top());
        from.pop();
    }
}

template <class T>
void Queue<T>::push (T data) {
    firstStack.push(data);
}

template <class T>
T Queue<T>::pop () {
    if (firstStack.empty() && secondStack.empty()) {
        throw "The queue is empty. Nothing to pop.\n";
    }

    moveQueue(firstStack, secondStack);

    T data = secondStack.top();
    secondStack.pop();

    moveQueue(secondStack, firstStack);

    return data;
}

template <class T>
int Queue<T>::getSize () const {
    return firstStack.size();
}

template <class T>
T Queue<T>::front () {
    if (firstStack.empty() && secondStack.empty()) {
        throw "The queue is empty.\n";
    }

    moveQueue(firstStack, secondStack);

    T data = secondStack.top();

    moveQueue(secondStack, firstStack);

    return data;
}

template <class T>
T Queue<T>::tail () {
    if (firstStack.empty() && secondStack.empty()) {
        throw "The queue is empty.\n";
    }

    return firstStack.top();
}
