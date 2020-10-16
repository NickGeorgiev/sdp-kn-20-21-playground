#include "comparable/comparable.h"
#include "engine/engine.h"
#include "student/student.h"
#include "set/set.h"

int main() {
    Comparable* first{new (std::nothrow) Student{81966}};
    Comparable* second{new (std::nothrow) Student{81990}};
    Comparable* third{new (std::nothrow) Student{81973}};

    Set fmi{first, second, third};
    std::cout << "\n$ student set:\n" << fmi;

	delete first;
	delete second;
	delete third;

	//<-------------------------------------------------------------------------->

	Comparable* fourth{new (std::nothrow) Engine{99216}};
	Comparable* fifth{new (std::nothrow) Engine{12763}};
	Comparable* sixth{new (std::nothrow) Engine{80448}};

	Set assembly_line{fourth, fifth, sixth};
	std::cout << "\n$ engine set:\n" << assembly_line;

	delete fourth;
	delete fifth;
	delete sixth;

    return 0;
}