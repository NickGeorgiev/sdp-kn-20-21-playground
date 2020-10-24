#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include <iostream>

class SkipList {

	struct Node {
		int value;
		Node* next;
		Node* skip;

		Node(const int&, Node*, Node*);
	};

	size_t m_length;
	Node* m_start;
	Node* m_end;

	void del();
	void optimize() const;
	Node* locate(const int&) const;

public:
	SkipList(const std::initializer_list<const int>&);
	~SkipList();

	void push(const int&);
	void push_back(const int&);
	void pop_back();
	void push_front(const int&);
	void pop_front();

	// Methods added for unit testing
	const size_t length() const;
	const Node* start() const;
	const Node* end() const;

	void print() const;
	void print_skip() const;
};
#endif
