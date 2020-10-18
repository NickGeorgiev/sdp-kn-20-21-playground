#include<iostream>
#include<cmath>
#include "skiplist.h"

void SkipList::destroy () {
    size = 0;
    Node *crr = start;
    while (crr != nullptr)
    {
        Node *save = crr->next;
        delete crr;
        crr = save;
    }
    start = nullptr;
    last = nullptr;
}

SkipList::~SkipList () { 
    destroy ();
}

SkipList::Node* SkipList::isMember (const int &_data) {
    Node *current = start;
    bool isMember = false;
    if (start == nullptr || start->data >= _data) {
        return nullptr;
    }
    if (last->data <= _data) {
        return last;
    }
    while (isMember == false && current != nullptr) {
        if (current->data < _data && current->forward->data > _data) {
            isMember = true;
            while (current->next->data <= _data) {
                current = current->next;
            }
        }
        else if (current->forward != nullptr) {
            current = current->forward;
        }
    }
    return current;
}

void SkipList::optimise() {
    int curNum = 0;
    int sqrtS = sqrt(size);
    Node *current = start;
    Node *prev = start;
    while (current != nullptr) {
        curNum++;
        if (curNum % sqrtS == 0 || curNum == size) {
            prev->forward = current;
            prev = current;
        }
        current = current->next;
    }
}

void SkipList::addToEnd (const int &_data) {
    if (start == nullptr) {
        start = last = new Node(_data, nullptr, nullptr);
    }
    else {
        last->next = new Node(_data, nullptr, nullptr);
        last = last->next;
    }
    size++;
    optimise();
}

void SkipList::addToStart (const int &_data) {
    if (start == nullptr) {
        start = last = new Node(_data, nullptr, nullptr);
    }
    else {
        Node *newNode = new Node(_data, start, nullptr);
        start = newNode;
    }
    size++;
    optimise();
}

void SkipList::insertAt (const int &_data, Node *_prevNode) {
    if (_prevNode == nullptr) {
        addToStart(_data);
        return;
    }
    if(_prevNode == last) {
        addToEnd(_data);
        return;
    }
    Node *newNode = new Node(_data, _prevNode->next, nullptr);
    _prevNode->next = newNode;
    size++;
    optimise();
}

void SkipList::print () const {
    Node *current = start;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}
