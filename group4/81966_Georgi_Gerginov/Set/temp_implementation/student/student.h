#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {

    unsigned int m_facnum;

public:
    Student(const unsigned int&);

    const unsigned int get_data() const;
	bool operator<(const Student&) const;
	bool operator==(const Student&) const;

	friend std::ostream& operator<<(std::ostream&, const Student&);
};

std::ostream& operator<<(std::ostream&, const Student&);

#endif