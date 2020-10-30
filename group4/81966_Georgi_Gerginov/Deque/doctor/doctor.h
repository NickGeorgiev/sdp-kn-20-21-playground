#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string>

class Doctor {

	std::string m_name;

public:
	Doctor(const std::string&);

	friend std::ostream& operator<<(std::ostream&, const Doctor&);
};

std::ostream& operator<<(std::ostream&, const Doctor&);

#endif