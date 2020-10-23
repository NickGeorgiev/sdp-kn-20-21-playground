#include "queue/queue.cpp"
#include <iostream>

int main() {
	Queue<int> test{1, 2, 3, 4};
	std::cout << test;

	test.push(5);
	test.pop();
	std::cout << test;
	
	return 0;
}
