#include "QueueWithTwoStacks.h"
#include <iostream>

int main()
{
    Queue<int> queue = Queue<int>();
    std::cout << queue.size() << std::endl;
    
    queue.push(1);
    queue.push(2);

    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
}