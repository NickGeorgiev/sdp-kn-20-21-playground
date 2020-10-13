#ifndef DLLIST_H
#define DLLIST_H
#include <iostream>

class DLList {

    struct Node {
        int value;
        Node* next;
        Node* prev;

        Node(const int&, Node*, Node*);
    };

    size_t m_length;
    Node* m_start;
    Node* m_end;

    void del();
    void copy(const DLList&);
    void move(DLList&&);
    void swap(DLList&);

public:
    DLList();
    DLList(const size_t&, Node*, Node*);
    DLList(const DLList&);
    DLList(DLList&&);
    ~DLList();

    void push_front(const int&);
    void pop_front();
    void push_back(const int&);
    void pop_back();

    DLList& operator=(const DLList&);
    DLList operator+(const int&) const;
    DLList& operator+=(const int&);

    friend std::ostream& operator<<(std::ostream&, const DLList&);
};

std::ostream& operator<<(std::ostream&, const DLList&);

#endif
