#ifndef TASK_H
#define TASK_H
#include <string>

class Task {

	std::string m_description;

public:
	Task(const std::string&);

	friend std::ostream& operator<<(std::ostream&, const Task&);
};

std::ostream& operator<<(std::ostream&, const Task&);

#endif
