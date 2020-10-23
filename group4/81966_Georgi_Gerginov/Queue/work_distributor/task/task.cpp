#include "task.h"

Task::Task(const std::string& description) : m_description{description} {}

std::ostream& operator<<(std::ostream& out, const Task& task) {
	out << task.m_description;
	return out;
}
