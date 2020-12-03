#include "programmer.h"
#include <iostream>

Programmer::Programmer(const std::string& name, const Type& spec, const unsigned short int& workhours, const Role& role) : m_name{name}, m_spec{spec}, m_role{role}, m_is_available{true} {
	if(workhours < 20 || workhours > 80) {
		throw std::runtime_error("Workhours not within limit");
	}

	m_workhours = workhours;
}

void Programmer::make_unavailable() {
	m_is_available = false;
}

const Type Programmer::get_specialization() const {
	return m_spec;
}

const unsigned short int Programmer::get_workhours() const {
	return m_workhours;
}

const unsigned short int Programmer::get_role_multiplier() const {
	if(m_role == Role::junior) {
		return 4;
	} else if(m_role == Role::middle) {
		return 2;
	} else {
		return 1;
	}
}

bool Programmer::is_available() const {
	return m_is_available;
}

bool Programmer::operator==(const Programmer& other) const {
	return m_name == other.m_name;
}

std::ostream& operator<<(std::ostream& out, const Programmer& programmer) {
	out << programmer.m_name;
	return out;
}
