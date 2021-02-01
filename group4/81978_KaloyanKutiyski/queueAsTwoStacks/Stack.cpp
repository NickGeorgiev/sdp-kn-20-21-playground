#pragma once
#include<iostream>

template<class T>
class Stack {
    
    template<class E>
    struct Node {
        E val;
        Node<E>* prev;
        Node(const E& _val): val{_val}, prev{nullptr} {
        } 
    };

    Node<T>* stackTop;

    void destroy() {
        while(stackTop) {
            pop();
        }
    }
    void copy(const Stack<T>& other) {
        if (!other.empty()) {
            stackTop = new Node<T>(other.top());
            Node<T>* thisCurr = stackTop;
            Node<T>* otherCurr = other.stackTop->prev;
            
            while (otherCurr) {
                thisCurr->prev = new Node<T>(otherCurr->val);
                thisCurr = thisCurr->prev;
                otherCurr = otherCurr->prev;
            }
        }
    }

    public:
    Stack(): stackTop{nullptr} {
    }
    Stack(const Stack<T>& other) {
        copy(other);
    }
    Stack<T>& operator=(const Stack<T>& other) {
        if (this != &other) {
            destroy();
            copy(other);
        }
        return *this;
    }
    ~Stack() {
        destroy();
    }

    bool empty()const {
        return stackTop == nullptr;
    }
    T top()const {
        if (!stackTop) {
            throw std::out_of_range("bottom of stack");
        }
        return stackTop->val;
    }
    void pop() {
        if (stackTop) {
            Node<T>* toDelete = stackTop;
            stackTop = stackTop->prev;
            delete toDelete;
        }
    }
    void push(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->prev = stackTop;
        stackTop = newNode;
    }
    void flipCopy(Stack<T>& other) {
        if (this != &other && stackTop == nullptr) {
            while (!other.empty()) {
                push(other.top());
                other.pop();
            }
        }
    }
};