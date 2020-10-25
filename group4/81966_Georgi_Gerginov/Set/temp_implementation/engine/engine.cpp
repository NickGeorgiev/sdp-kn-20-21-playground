#include "engine.h"

Engine::Engine(const unsigned int& serialnum) : m_serialnum{serialnum} {}

const unsigned int Engine::get_data() const {
    return m_serialnum;
}

bool Engine::operator<(const Engine& other) const {
	return m_serialnum < other.m_serialnum;
}

bool Engine::operator==(const Engine& other) const {
	return m_serialnum == other.m_serialnum;
}

std::ostream& operator<<(std::ostream& out, const Engine& eng) {
	out << eng.m_serialnum;
	return out;
}
