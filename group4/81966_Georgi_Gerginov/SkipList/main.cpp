#include "skipList.h"

int main() {
	SkipList test{1, 2, 3, 5, 6, 7, 8, 9, 10, 11};

	test.print();
	test.print_skip();
	test.push(4);
	test.print();
	test.print_skip();

	std::cout << "\n";

	test.pop_front();
	test.pop_back();
	test.print();
	test.print_skip();

	std::cout << "\n";

	test.push_front(1);
	test.push_back(11);
	test.print();
	test.print_skip();

	return 0;
}