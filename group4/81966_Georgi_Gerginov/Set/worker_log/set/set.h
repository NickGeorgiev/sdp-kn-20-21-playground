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
	void copy(const Set&);
	void swap(Set&);

    void push_front(Comparable*);
    void push_back(Comparable*);
    bool is_unique(Comparable*) const;

public:
    Set();
	Set(const Set&);
	Set(const std::initializer_list<Comparable*>&);
    ~Set();

    void pop_front();
    void pop_back();
    void push(Comparable*);

	Set& operator=(const Set&);

    friend std::ostream& operator<<(std::ostream&, const Set&);
};

std::ostream& operator<<(std::ostream&, const Set&);

#endif
