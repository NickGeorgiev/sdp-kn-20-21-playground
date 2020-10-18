#ifndef __SKIPLIST__HH__
#define __SKIPLIST__HH__
#include <iostream>

class skipList {

    struct Node {
        int data;
        Node* next;
        Node* skip;

        Node(const int _data,Node* _next):data{_data},next{_next},skip{nullptr} {}
    };

    Node* first;
    size_t size;

    void copyList(const skipList& other);
    void deleteList();

    public: 

    skipList();
    skipList(const skipList& other);
    skipList& operator =(const skipList& other);
    ~skipList();

    void optimize();
    Node* locate(const int elem);
    void addElement(const int newElem);
    
    void printList() const;
    void printSkips() const;
};

#endif