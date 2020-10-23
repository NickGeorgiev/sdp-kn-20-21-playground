#include "worker.h"

Worker::Worker(const std::string& name) : m_name{name} {}

std::ostream& operator<<(std::ostream& out, const Worker& worker) {
	out << worker.m_name;
	return out;
}
