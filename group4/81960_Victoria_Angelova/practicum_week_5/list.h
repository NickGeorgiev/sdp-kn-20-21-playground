#ifndef __LLIST_H
#define __LLIST_H

template <class T>
class LList
{ //unordered list
    struct Node
    {
        T data;
        Node *next, *prev;
        // Node () = default;
    };

    Node *first, *last;
    int size;

    void destroy();
    void copy(const LList<T> &);

public:
    LList();
    LList(const LList<T> &);
    LList &operator=(const LList<T> &);
    ~LList();

    void add(const T &data);
    //void remove (const T& data);

    void print();

    class Iterator
    {

        Node *current;
        Node *start;
        Node *end;

    public:
        Iterator(Node *, Node *, Node *);

        T &operator*();
        Iterator &operator++();
        Iterator &operator--();
        bool operator!=(const Iterator &) const;
        bool operator==(const Iterator &) const;
    };

    Iterator begin() const;
    Iterator end() const;
};

#include "list.cpp"

#endif