#include"skiplist.h"
#include<cmath>

void SkipList::copy(const SkipList& other) {
    level = other.level;
    start = nullptr;

    Node* current = other.start;
    Node* copy = nullptr;

    while(current) {
        if(!start) {
            start = new Node(current->elements,nullptr,nullptr);
            copy = start;
        } else {
            copy->next = new Node(current->elements,nullptr,nullptr);
            copy = copy->next;
        }

        current = current->next;
    }

    optimise(); 
}

void SkipList::deleteSkipList() {
    level = 0;

    while(start) {
        Node* remember = start;
        start = start->next;
        delete remember;
    }
}

void SkipList::addElement(const int& otherElement) {
    Node* previous = member(otherElement);

    if(!previous) {
        start = new Node(otherElement, start, nullptr);
        return;
    }

    previous->next = new Node(otherElement, previous->next,nullptr);
        
    level++;
    optimise(); 
}

SkipList::Node* SkipList::member(const int& searchedElement) {
    if(!start) {
        return nullptr;
    }

    Node* current = start;

    while(current->skip && current->skip->elements < searchedElement) {
        current = current->skip;
    }

    while(current->next && current->elements < searchedElement) {
        current = current->next;
    }

    return current;
}


void SkipList::optimise() {
    int skipNumber = sqrt(level);
    int currentIndex = 1;

    Node* current = start->next,*previousSkip = start;
        
    while(current) {
        current->skip = nullptr;
        if(currentIndex % skipNumber == 0 || currentIndex+1 == level) {
                previousSkip->skip = current;
                previousSkip = current;
            }

        currentIndex++;
        current = current->next;
        }
}

void SkipList::print() const {
    Node* current = start;

    while(current) {
        std::cout << current->elements << " ";
        current = current->next;
    }

}


void SkipList::printSkips() const {
    Node* current = start;

    while(current) {
        std::cout << current->elements << " ";
        current = current->skip;
    }

}