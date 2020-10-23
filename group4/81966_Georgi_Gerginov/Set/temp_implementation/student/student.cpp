#include "student.h"

Student::Student(const unsigned int& facnum) : m_facnum{facnum} {}

const unsigned int Student::get_data() const {
    return m_facnum;
}

bool Student::operator<(const Student& other) const {
	return m_facnum < other.m_facnum;
}

bool Student::operator==(const Student& other) const {
	return m_facnum == other.m_facnum;
}

std::ostream& operator<<(std::ostream& out, const Student& stu) {
	out << stu.m_facnum;
	return out;
}
