#include "queue.h"
#include <iostream>

int main()
{
    Queue test;

    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    test.push(6);

    test.pop();
    test.pop();

    std::cout << test.front() << std::endl;
    std::cout << test.tail() << std::endl;

    test.print();
}
