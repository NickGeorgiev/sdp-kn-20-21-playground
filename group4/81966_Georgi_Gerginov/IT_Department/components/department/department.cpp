#include "department.h"

const Queue<Task*> Department::q_from_tasks() const {
	Queue<Task*> from_tasks;

	for(auto curr : m_tasks) {
		from_tasks.push(curr);
	}

	return from_tasks;
}

const OrderedSet<Task*> Department::worked_on_tasks() const {
	OrderedSet<Task*> worked_on;

	for(auto curr : m_tasks) {
		if(curr -> is_worked_on()) {
			worked_on.push(curr);
		}
	}

	return worked_on;
}

const OrderedSet<Task*> Department::not_worked_on_tasks() const {
	OrderedSet<Task*> not_worked_on;

	for(auto curr : m_tasks) {
		if(!curr -> is_worked_on()) {
			not_worked_on.push(curr);
		}
	}

	return not_worked_on;
}

Department::Department(const UnorderedSet<Programmer*>& programmers, const OrderedSet<Task*>& tasks) : m_programmers{programmers}, m_tasks{tasks} {}

void Department::organize_worksheet() {
	Queue<Task*> from_tasks{q_from_tasks()};

	while(!from_tasks.empty()) {
		Task* task_curr{from_tasks.front()};

		for(auto prog_curr : m_programmers) {

			bool is_a_match{
				prog_curr -> is_available() &&
				prog_curr -> get_specialization() == task_curr -> get_type() &&
				(prog_curr -> get_role_multiplier() * task_curr -> get_time_to_do()) <= prog_curr -> get_workhours()
			};

			if(is_a_match) {
				task_curr -> assign_programmer(prog_curr);
				prog_curr -> make_unavailable();

				break;
			}
		}

		from_tasks.pop();
	}
}

void Department::print_worksheet() const {
	OrderedSet<Task*> worked_on{worked_on_tasks()};
	OrderedSet<Task*> not_worked_on{not_worked_on_tasks()};

	if(!worked_on.empty()) {
		for(auto curr : worked_on) {
			std::cout << "$ " << *curr << " : " << *curr -> get_associated_prog() << "\n";
		}
	}


	if(!not_worked_on.empty()) {
		std::cout << "\n";

		for(auto curr : not_worked_on) {
			std::cout << "$ " << *curr << " : " << "nobody\n";
		}
	}
}
