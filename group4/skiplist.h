#ifndef __SKIPLIST_HH__
#define __SKIPLIST_HH__
#include<iostream>


class SkipList {
    struct Node {
        int elements;
        Node* next;
        Node* skip;

        //a constructor for the Node
        Node(const int& otherElements, Node* nextElement, Node* skippingElement): 
            elements(otherElements), next(nextElement), skip(skippingElement) {}
    };

    Node* start;
    size_t level; 
    
    //a copy constructor and a destructor for the SkipList
    void copy(const SkipList& other);
    void deleteSkipList();

    public:
    //a default constructor, a parametric constructor, a copy constructor and a destructor
    SkipList(): start(nullptr), level(0) {}
    SkipList(size_t otherLevel, Node* otherStart): level(otherLevel), start(otherStart) {}
    SkipList(const SkipList& other) {
        copy(other);
    }
    ~SkipList() {
        deleteSkipList();
    }

    //adds an element to the list
    void addElement(const int& otherElement);


    //checks for existence
    Node* member(const int& searchedElement);

    //the optimisation method
    void optimise();
Node* locate(const int elem);
//a printing function for the whole list
void print() const;

//a printing function for the skips
void printSkips() const;
};
#endif