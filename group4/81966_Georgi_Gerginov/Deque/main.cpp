#include "patient_implementation/deque.h"
#include "patient/patient.h"

int main() {
	Deque waiting_room;
	waiting_room.push_emergency({28913, 1});
	std::cout << waiting_room;
}