#ifndef DEQUE_H
#define DEQUE_H
#include "../patient/patient.h"
#include <iostream>

class Deque {

	struct Node {
		Patient patient;
		Node* next;
		Node* prev;

		Node(const Patient&, Node*, Node*);
	};

	size_t m_length;
	Node* m_start;
	Node* m_end;
	Node* m_last_critical_patient;

	void del();
	void update_last_crit();

public:
	Deque();
	Deque(const std::initializer_list<const Patient>&);
	~Deque();

	void push_front(const Patient&);
	void pop_front();
	void push_back(const Patient&);
	void pop_back();
	void push_emergency(const Patient&);

	friend std::ostream& operator<<(std::ostream&, const Deque&);
};

std::ostream& operator<<(std::ostream&, const Deque&);

#endif
