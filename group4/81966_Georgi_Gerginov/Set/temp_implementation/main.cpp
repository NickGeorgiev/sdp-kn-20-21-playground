#include "engine/engine.h"
#include "student/student.h"
#include "set/set.cpp"

int main() {
    Student first{81966};
    Student second{81990};
    Student third{81973};

    Set<Student> fmi{first, second, third};
    std::cout << "\n$ student set:\n" << fmi;

	//<-------------------------------------------------------------------------->

	Engine fourth{99216};
	Engine fifth{12763};
	Engine sixth{80448};

	Set<Engine> assembly_line{fourth, fifth, sixth};
	std::cout << "\n$ engine set:\n" << assembly_line;

    return 0;
}