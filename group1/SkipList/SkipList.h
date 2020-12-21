#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <iostream>
#include <cmath>

class SkipList
{
private:
    struct box
    {
        int data;
        box* next, * prev, *skip;

        box(const int& _data = 0, box* _next = nullptr, box* _prev = nullptr, box* _skip = nullptr) :
            data(_data), next(_next), prev(_prev), skip(_skip) {}
    };
    box* first, *last;
    int list_size;

    void copy(const SkipList& other);
    box* locate(const int& element) const;
    void clear_skip_steps();
    void optimize();

public:
    SkipList(const SkipList& other);
    SkipList();
    ~SkipList();

    void push(const int& element);
    void reverse();
    void print() const;
    void clear();
    int size();
    bool member(const int& element) const;
    void sort();

    SkipList& operator= (const SkipList& other);
};


#endif