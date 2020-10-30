#include "patient_implementation/deque.h"
#include "patient/patient.h"
#include "doctor/doctor.h"
#include <vector>

int main() {
	std::vector<Patient> patients{
		Patient{37812, 0},
		Patient{43274, 0},
		Patient{12395, 1},
		Patient{43782, 0},
		Patient{86787, 1},
		Patient{76501, 0}
	};

	Deque prob2_waitlist;

	for(const Patient& curr : patients) {
		if(curr.is_in_critical_condition()) {
			prob2_waitlist.push_front(curr);
		} else {
			prob2_waitlist.push_back(curr);
		}
	}

	//<--------------------------------------------------->

	Deque prob3_waitlist;

	for(const Patient& curr : patients) {
		if(curr.is_in_critical_condition()) {
			prob3_waitlist.push_emergency(curr);
		} else {
			prob3_waitlist.push_back(curr);
		}
	}

}