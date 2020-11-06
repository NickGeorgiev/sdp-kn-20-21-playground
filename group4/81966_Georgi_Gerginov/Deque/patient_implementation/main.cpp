// This example shows the bonus problem
#include "deque/deque.h"
#include "patient/patient.h"
#include "doctor/doctor.h"
#include <vector>

int main() {
	std::vector<Doctor> doctors{
		Doctor{"Velasquez"},
		Doctor{"Papadopulous"},
		Doctor{"Stevens"},
		Doctor{"Figueroa"},
		Doctor{"Xu"},
		Doctor{"Vladimirov"}
	};

	std::vector<Patient> patients{
		Patient{37812, 0},  // 3rd
		Patient{43274, 0},  // 4th
		Patient{12395, 1},  // 1st
		Patient{43782, 0},  // 5th
		Patient{86787, 1},  // 2nd
		Patient{76501, 0}   // 6th
	};

	Deque prob3_waitlist;
	size_t prob3_counter{0};

	for(const Patient& curr : patients) {
		if(curr.is_in_critical_condition()) {
			prob3_waitlist.push_emergency(curr);
		} else {
			prob3_waitlist.push_back(curr);
		}
	}

	if(doctors.size() >= prob3_waitlist.length()) {
		while(!prob3_waitlist.empty()) {
			std::cout << "$ " << doctors[prob3_counter] << " has to tend to " << prob3_waitlist.front() << "\n";
			prob3_waitlist.pop_front();
			prob3_counter++;
		}

		while(prob3_counter < doctors.size()) {
			std::cout << "$ " << doctors[prob3_counter] << " has no patient to tend to\n";
			prob3_counter++;
		}
	} else {
		while(prob3_counter < doctors.size()) {
			std::cout << "$ " << doctors[prob3_counter] << " has to tend to " << prob3_waitlist.front() << "\n";
			prob3_waitlist.pop_front();
			prob3_counter++;
		}

		std::cout << "\n$ Patients that have nobody to take care of them:\n" << prob3_waitlist;
	}
}