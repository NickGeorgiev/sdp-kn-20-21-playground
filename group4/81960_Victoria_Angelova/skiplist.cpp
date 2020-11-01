#include<iostream>
#include<cmath>
#include "skiplist.h"

void SkipList::destroy () {
    size = 0;
    while (start)
    {
        Node* save = start;
        start = start->next;
        delete save;
    }
}

SkipList::~SkipList () { 
    destroy ();
}

SkipList::Node* SkipList::locate (const int &_data) {
    Node *current = start;

    if (start == nullptr || start->data > _data) {
        return nullptr;
    }

    while (current->forward != nullptr && current->forward->data <= _data) {
        current = current->forward;
    }

    while (current->next != nullptr && current->next->data <= _data) {
        current = current->next;
    }

    return current;
}

bool SkipList::isMember (const int& _data) {
    return locate(_data) != nullptr && locate(_data)->data == _data;
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
