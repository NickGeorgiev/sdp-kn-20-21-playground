#include "components/programmer/programmer.h"
#include "components/task/task.h"
#include "components/department/department.h"
#include "data_structures/ordered_set/ordered_set.cpp"
#include "data_structures/unordered_set/unordered_set.cpp"

int main() {
	Programmer* prog1{new Programmer{"Ivan", Type::backend, 20, Programmer::Role::senior}};
	Programmer* prog2{new Programmer{"Dimitar", Type::mobile, 60, Programmer::Role::middle}};
	Programmer* prog3{new Programmer{"Georgi", Type::web, 80, Programmer::Role::junior}};

	Task* task1{new Task{"task1", Type::backend, 20, Task::Priority::top}};
	Task* task2{new Task{"task2", Type::mobile, 20, Task::Priority::middle}};
	Task* task3{new Task{"task3", Type::web, 20, Task::Priority::bottom}};

	OrderedSet<Task*> tasks{task1, task2, task3};
	UnorderedSet<Programmer*> progs{prog1, prog2, prog3};

	Department dep{progs, tasks};
	dep.organize_worksheet();
	dep.print_worksheet();

	delete task1;
	delete task2;
	delete task3;

	delete prog1;
	delete prog2;
	delete prog3;

	return 0;
}
