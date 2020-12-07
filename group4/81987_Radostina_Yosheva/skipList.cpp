#include <iostream>
#include <cmath>
#include "skipList.h"

SkipList::SkipList() : start(nullptr), end(nullptr), size(0) {}

SkipList::~SkipList() {
    Node *save;
    Node *curr = start;

    while (curr != nullptr) {
        save = curr;
        curr = curr->next;
        delete save;
    }
}


void SkipList::add(const int& data) {

    Node *prev = locate(data);

    if (prev == nullptr)
    {
        start = new Node(data, start);
        if (size == 0)
            end = start;
        
    } else {
        prev->next = new Node(data, prev->next);
    }

    size++;

    // reassigning the end pointer
    Node *curr = start;
    while (curr->next != nullptr && start != nullptr) {
        curr = curr->next;
    }
    end = curr;

    optimize();
}


Node *SkipList::locate(const int& data){

    if (start == nullptr){
        return nullptr;
    }

    if (start->data >= data){
        return nullptr;
    }

    Node *curr = start->next;
    Node *prev = start;

    while (curr != nullptr){
        if (curr->data >= data) {
            return prev;
        }

        prev = curr;
        curr = curr->next;
    }

    return prev;
}


void SkipList::optimize() {
    clearSkips();

    Node *curr = start;
    Node *save = start;
    int step = sqrt(size);
    int count = 0;
    int numElement = 0;

    while (curr != nullptr) {
        if (count == step || numElement == size){
            save->skip = curr;
            save = curr;
            count = 0;
        }
        curr = curr->next;
        count++;
        numElement++;
    }  

    save->skip = end;  
}


void SkipList::printSkips(){
    Node *curr = start;

    while (curr != nullptr) {
        if (curr->skip != nullptr) {
            std::cout << curr->skip->data << " ";
        }
        curr = curr->next;
    }

    std::cout << std::endl;
}

void SkipList::clearSkips() {
    Node *curr = start;

    while (curr != nullptr) {
        curr->skip = nullptr;
        curr = curr->next;
    }
}

std::ostream& operator<<(std::ostream& out, const SkipList& list) {
    Node *curr = list.start;

    while (curr != nullptr) {
        out << curr->data << ' ';
        curr = curr->next;
    }

    return out;
}



int main () {
    SkipList l;
    l.add(1);
    l.add(0);
    l.add(12);
    l.add(33);
    l.add(6);
    l.add(12);

    std::cout << "skips: ";
    l.printSkips();
    std::cout << "list: " << l << std::endl;

    l.add(31);
    l.add(9);
    l.add(34);

    std::cout << "skips: ";
    l.printSkips();
    std::cout << "list: " << l << std::endl;
}