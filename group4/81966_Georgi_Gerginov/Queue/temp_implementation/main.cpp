#include "queue/queue.cpp"
#include <iostream>

int main() {
	Queue<int> test{1, 2, 3, 4};
	std::cout << test;

	test.push(5);
	test.pop();
	
	std::cout << test << "\n";
	std::cout << "length: " << test.length() << "\n";
	std::cout << std::boolalpha << "empty: " << test.empty() << "\n";
	std::cout << "front: " << test.front() << "\n";
	std::cout << "back: " << test.back() << "\n"; 
	
	return 0;
}
