#ifndef _SKIPLIST_HH
#define _SKIPLIST_HH
#include <iostream>

template <class T>
struct Node
{
    T value;
    Node<T> *next;
    Node<T> *skip;

    Node(const T &_value, Node<T> *_next, Node<T> *_skip) : value{_value}, next{_next}, skip{_skip} {}
};

template <class T>
class SkipList
{
private:
    Node<T> *start;
    Node<T> *end;

    void copyList(const SkipList &);
    void redefineSkipper(); ///Redefines the elements we skip from and to
    void destroyList();

public:
    SkipList();
    SkipList(const SkipList &);
    ~SkipList();
    SkipList<T> &operator=(const SkipList &);

    size_t size() const;
    void toStart(const T &);
    void toEnd(const T &);
    Node<T> *member(const T &) const; ///Returns the member with the max value <= of the one we are searching for, aka the member after the new Value should be added
    void addElement(const T &);       ///Adds element

    void printSkips() const; ///Prints all elements that have skip!=nullptr
    void print() const;      ///Prints all elements
};

#endif
