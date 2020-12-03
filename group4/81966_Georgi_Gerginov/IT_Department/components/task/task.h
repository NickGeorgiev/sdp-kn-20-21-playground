#ifndef TASK_H
#define TASK_H
#include "../dev_task_types.h"
#include "../programmer/programmer.h"
#include <string>

class Task {
public:
	enum Priority {
		top,
		middle,
		bottom
	};

private:
	std::string m_name;
	Type m_type;
	unsigned short int m_time_to_do;
	Priority m_priority;
	Programmer* m_associated_prog;

public:
	Task(const std::string&, const Type&, const unsigned short int&, const Priority&);

	void assign_programmer(Programmer*);

	const Type get_type() const;
	const unsigned short int get_time_to_do() const;
	const Programmer* get_associated_prog() const;
	bool is_worked_on() const;

	bool operator==(const Task&) const;
	bool operator<=(const Task&) const;
	bool operator>=(const Task&) const;
	bool operator<(const Task&) const;
	bool operator>(const Task&) const;

	friend std::ostream& operator<<(std::ostream&, const Task&);
};

std::ostream& operator<<(std::ostream&, const Task&);

#endif
