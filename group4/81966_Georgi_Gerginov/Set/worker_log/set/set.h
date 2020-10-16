#ifndef SET_H
#define SET_H
#include "../log/log.h"
#include <iostream>

class Set {

    struct Node {
        Log data;
        Node* next;
        Node* prev;

        Node(const Log&, Node*, Node*);
    };

    size_t m_length;
    Node* m_start;
    Node* m_end;

    void del();
    bool is_unique(const Log&) const;

	void print_forward() const;
	void print_backward() const;
	void print_dates() const;

public:
    Set();
	Set(const size_t&);
	Set(const std::initializer_list<const Log>&);
    ~Set();

    void push_back(const Log&);
    void pop_back();

	void print_menu() const;

    friend std::ostream& operator<<(std::ostream&, const Set&);
};

std::ostream& operator<<(std::ostream&, const Set&);

#endif