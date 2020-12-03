#include "task.h"

Task::Task(const std::string& name, const Type& type, const unsigned short int& time_to_do, const Priority& priority) : m_name{name}, m_type{type}, m_time_to_do{time_to_do}, m_priority{priority}, m_associated_prog{nullptr} {}

void Task::assign_programmer(Programmer* prog) {
	m_associated_prog = prog;
}

const Type Task::get_type() const {
	return m_type;
}

const unsigned short int Task::get_time_to_do() const {
	return m_time_to_do;
}

const Programmer* Task::get_associated_prog() const {
	return m_associated_prog;
}

bool Task::is_worked_on() const {
	return m_associated_prog;
}

bool Task::operator==(const Task& other) const {
	return m_name == other.m_name;
}

bool Task::operator>=(const Task& other) const {
	return m_priority >= other.m_priority;
}

bool Task::operator<=(const Task& other) const {
	return m_priority <= other.m_priority;
}

bool Task::operator<(const Task& other) const {
	return m_priority < other.m_priority;
}

bool Task::operator>(const Task& other) const {
	return m_priority > other.m_priority;
}

std::ostream& operator<<(std::ostream& out, const Task& task) {
	out << task.m_name;
	return out;
}
