#ifndef SET_H
#define SET_H
#include "../comparable/comparable.h"
#include <iostream>

class Set {

    struct Node {
        Comparable* data;
        Node* next;
        Node* prev;

        Node(Comparable*, Node*, Node*);
    };

    size_t m_length;
    Node* m_start;
    Node* m_end;

    void del();
    bool is_unique(Comparable*) const;

public:
    Set();
	Set(const std::initializer_list<Comparable*>&);
    ~Set();

    void push_front(Comparable*);
    void pop_front();
    void push_back(Comparable*);
    void pop_back();
    void push(Comparable*);

    friend std::ostream& operator<<(std::ostream&, const Set&);
};

std::ostream& operator<<(std::ostream&, const Set&);

#endif