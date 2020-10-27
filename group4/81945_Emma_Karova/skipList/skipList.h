#ifndef __SkipList__HH__
#define __SkipList__HH__
#include <iostream>

class SkipList {

    struct Node {
        int data;
        Node* next;
        Node* skip;

        Node(const int _data,Node* _next):data{_data},next{_next},skip{nullptr} {}
    };

    Node* first;
    size_t size;

    void copyList(const SkipList& other);
    void deleteList();

    public: 

    SkipList();
    SkipList(const SkipList& other);
    SkipList& operator =(const SkipList& other);
    ~SkipList();

    void optimize();
    Node* locate(const int elem) const;
    bool member(const int elem) const;
    void addElement(const int newElem);
};

#endif
