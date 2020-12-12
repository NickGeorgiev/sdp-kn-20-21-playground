#include "queue/queue.cpp"

int main() {
	Queue<int> test{1, 2, 3, 4};
	std::cout << test;

	test.push(5);
	std::cout << test;

	test.pop();
	std::cout << test;
	
	return 0;
}
