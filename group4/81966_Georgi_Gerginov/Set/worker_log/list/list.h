#ifndef LIST_H
#define LIST_H
#include "../log/log.h"
#include "../set/set.h"
#include <iostream>

class List {

    struct Node {
        Log* data;
        Node* next;
        Node* prev;

        Node(Log*, Node*, Node*);
    };

    size_t m_length;
    Node* m_start;
    Node* m_end;

    void del();

	void print_forward() const;
	void print_backward() const;

public:
    List();
	List(const size_t&);
	List(const std::initializer_list<Log*>&);
    ~List();

    void push_back(Log*);
    void pop_back();
	Set set_from_list() const;

	void print_menu() const;

    friend std::ostream& operator<<(std::ostream&, const List&);
};

std::ostream& operator<<(std::ostream&, const List&);

#endif
