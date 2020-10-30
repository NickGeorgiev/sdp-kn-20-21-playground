#include "patient.h"

Patient::Patient(const unsigned int& patient_id, const bool& condition) : m_patient_id{patient_id}, m_is_critical{condition} {}

bool Patient::is_in_critical_condition() const {
	return m_is_critical;
}

std::ostream& operator<<(std::ostream& out, const Patient& _patient) {
	out << "ID: " << _patient.m_patient_id
		<< " | Condition: ";
	
	if(_patient.m_is_critical) {
		out << "Critical";
	} else {
		out << "Stable";
	}
	
	return out;
}
