#ifndef __SKIPLIST__HH
#define __SKIPLIST__HH

#include <iostream>

class SkipList
{   
    private:
    struct Node
    {
        int data;
        Node* next;
        Node* skip;

        Node (const int& _data, Node* _next): 
              data {_data}, next {_next}, skip {nullptr} {}
    };

    Node* start;
    size_t size;

    void copySkipList (const SkipList& other);
    void deleteSkipList ();

    public:
    SkipList ();
    SkipList (const SkipList& other);
    ~SkipList ();

    SkipList& operator = (const SkipList& other);

    size_t getSize () const;
    size_t getNumSkipElements () const;

    Node* locate (const int& elem) const;
    void optimize ();
    void addElementAt (const int& elem, Node*& at);
    void addElement (const int& elem);

    void printSkipList () const;
    void printSkipping () const;
};

#endif