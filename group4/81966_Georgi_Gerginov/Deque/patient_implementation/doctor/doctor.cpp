#include "doctor.h"

Doctor::Doctor(const std::string& name) : m_name{name} {}

std::ostream& operator<<(std::ostream& out, const Doctor& doc) {
	out << doc.m_name;
	return out;
}