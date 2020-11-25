#include <iostream>
#include <stack>
#include "queue.h"


int main()
{
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    std::cout << queue.front();
    queue.pop();
    std::cout << queue.front();
    std::cout << queue.tail();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    std::cout<< queue.tail();

    return 0;
}
