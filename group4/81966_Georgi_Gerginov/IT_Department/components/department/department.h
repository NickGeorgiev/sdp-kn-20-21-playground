#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "../programmer/programmer.h"
#include "../task/task.h"
#include "../../data_structures/ordered_set/ordered_set.cpp"
#include "../../data_structures/unordered_set/unordered_set.cpp"
#include "../../data_structures/queue/queue.cpp"

class Department {

	UnorderedSet<Programmer*> m_programmers;
	OrderedSet<Task*> m_tasks;

	const Queue<Task*> q_from_tasks() const;
	const OrderedSet<Task*> worked_on_tasks() const;
	const OrderedSet<Task*> not_worked_on_tasks() const;

public:
	Department(const UnorderedSet<Programmer*>&, const OrderedSet<Task*>&);
	~Department() = default;

	void organize_worksheet();
	void print_worksheet() const;
};

#endif
