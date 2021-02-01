#pragma once
#include"Stack.cpp"
#include<iostream>

template<class T>
class Queue {
    bool pushMode;
    Stack<T> topAndPopStack;
    Stack<T> pushStack;

    void switchMode() {
        if (pushMode) {
            topAndPopStack.flipCopy(pushStack);
        }
        else {
            pushStack.flipCopy(topAndPopStack);
        }
        pushMode = !pushMode;
    }

    public:
    Queue(): pushMode{true} {
    }
    bool empty() {
        return pushMode && pushStack.empty() || !pushMode && topAndPopStack.empty();
    }
    T top() {
        if (pushMode) {
            switchMode();
        }
        try {
            return topAndPopStack.top();
        }
        catch (std::out_of_range e) {
            throw e;
        }
    }
    void pop() {
        if (pushMode) {
            switchMode();
        }
        topAndPopStack.pop();
    }
    void push(const T& val) {
        if (!pushMode) {
            switchMode();
        }
        pushStack.push(val);
    }
};