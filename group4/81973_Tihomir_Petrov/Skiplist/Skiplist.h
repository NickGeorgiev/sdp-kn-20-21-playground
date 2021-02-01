#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <iostream>

class Skiplist{
    private:
    struct Skipnode{
        int data;
        Skipnode *next;
        Skipnode *prev;
        Skipnode *skip;

        Skipnode(const int el, Skipnode *_next, Skipnode *_prev, Skipnode *_skip): data(el), next(_next), prev(_prev), skip(_skip) {}
    };

    Skipnode *head;
    Skipnode *tail;

    void copy(const Skiplist&);
    void clear();

    public:
    Skiplist();
    Skiplist(const Skiplist&);
    ~Skiplist();
    Skiplist& operator= (const Skiplist&);
    Skiplist& operator+= (const int&);

    void push(const int&);
    bool member(const int&);
    typename Skiplist::Skipnode* locate(const int&);
    void placeTail();
    void optimize();
    void reverse();
    void print();
    typename Skiplist::Skipnode* getHead();

};


// #include "Skiplist.cpp"
#endif