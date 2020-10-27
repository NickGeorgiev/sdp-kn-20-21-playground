#include <iostream>
#include <cmath>

#include "SkipList.h"

void SkipList::copyList(const SkipList& other) {   
    size = other.size;
    first = nullptr;

    Node* current = other.first;
    Node* copy = nullptr;

    while(current) {
        if(!first) {
            first = new Node(current->data,nullptr);
            copy = first;
        }
        else{
            copy->next = new Node(current->data,nullptr);
            copy = copy->next;
        }

        current = current->next;
    }

    optimize(); 
}

void SkipList::deleteList() {
    size = 0;

    while(first) {
        Node* save = first;
        first = first->next;
        delete save;
    }
}

SkipList::SkipList():first{nullptr},size{0} {}

SkipList::SkipList(const SkipList& other) {
    copyList(other);  
}

SkipList& SkipList::operator =(const SkipList& other) {
    if(this != &other) {
        deleteList();
        copyList(other);
    }

    return *this;
}

SkipList::~SkipList() {
    deleteList();
}

void SkipList::optimize() {
    int skipNum = sqrt(size),currIndex = 1;

    Node* current = first->next,*previousSkip = first;
    while(current) {
        
        current->skip = nullptr;
        if(currIndex % skipNum == 0 || currIndex+1 == size) {
            previousSkip->skip = current;
            previousSkip = current;
        }
        
        currIndex++;
        current = current->next;
    }
} 

SkipList::Node* SkipList::locate(const int elem) const {
    Node* current = first;
    if(!first || current->data > elem){
        return nullptr;
    }

    while(current->skip && current->skip->data <= elem){
        current = current->skip;
    }

    while(current->next && current->next->data <= elem){
        current = current->next;
    }

    return current;
}

bool SkipList::member(const int elem) const {
    if(!locate(elem)) {
        return false;
    }
    else {
        return locate(elem)->data == elem;
    }
}

void SkipList::addElement(const int newElem) {
    Node* toAdd = locate(newElem);
    if(!toAdd) {
        first = new Node(newElem,first);
    }
    else {
        toAdd->next = new Node(newElem,toAdd->next);
    }
    size++;
    
    optimize();
}
