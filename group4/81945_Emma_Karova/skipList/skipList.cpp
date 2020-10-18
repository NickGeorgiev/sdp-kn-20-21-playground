#include <iostream>
#include <cmath>

#include "skipList.h"

void skipList::copyList(const skipList& other) {
    
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

void skipList::deleteList() {

    size = 0;

    while(first) {
        Node* save = first;
        first = first->next;
        delete save;
    }

}

skipList::skipList():first{nullptr},size{0} {}

skipList::skipList(const skipList& other) {
    copyList(other);
   
}

skipList& skipList::operator =(const skipList& other) {
    if(this != &other) {
        deleteList();
        copyList(other);
    }

    return *this;
}

skipList::~skipList() {
    deleteList();
}

void skipList::optimize() {
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

skipList::Node* skipList::locate(const int elem) {

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

void skipList::addElement(const int newElem) {

    Node* toAdd = locate(newElem);
    if(!toAdd) {
        first = new Node(newElem,first);
    }
    else {
        Node* newNode = new Node(newElem,toAdd->next);
        toAdd->next = newNode;
    }
    size++;
    
    optimize();

}

void skipList::printList() const {
    Node* current = first;

    while(current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

void skipList::printSkips() const {
    Node* current = first;

    while(current) {
        std::cout << current->data << " ";
        current = current->skip;
    }

    std::cout << std::endl;
}

