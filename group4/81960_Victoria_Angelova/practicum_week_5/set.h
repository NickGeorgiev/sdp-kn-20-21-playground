#ifndef __SET_H
#define __SET_H

template <class T>
class Set
{ //ordered list
    struct Node
    {
        T data;
        Node *next, *prev;
    };

    Node *first, *last;
    int size;

    void destroy();
    void copy(const Set<T> &);

public:
    Set();
    Set(const Set<T> &);
    Set &operator=(const Set<T> &);
    ~Set();

    void add(const T &data);
    void remove(const T &data);

    void print();

    class Iterator
    {

        Node *current;
        Node *start;
        Node *end;

    public:
        Iterator(Node *, Node *, Node *);

        T &operator *();
        Iterator &operator ++ ();
        Iterator &operator--();
        bool operator!=(const Iterator &) const;
        bool operator==(const Iterator &) const;
    };

    Iterator begin() const;
    Iterator end() const;
};

#include "set.cpp"

#endif
