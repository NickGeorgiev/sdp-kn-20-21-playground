#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>

class Patient {

	unsigned int m_patient_id;
	bool m_is_critical;

public:
	Patient(const unsigned int&, const bool&);
	bool is_in_critical_condition() const;

	friend std::ostream& operator<<(std::ostream&, const Patient&);
};

std::ostream& operator<<(std::ostream&, const Patient&);

#endif
