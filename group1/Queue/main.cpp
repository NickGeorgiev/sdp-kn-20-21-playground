#include "stackQueue.h"


int main()
{
    StackQueue<int> q;

    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    q.push_back(6);

    std::cout << q.front() << std::endl << q.back() << std::endl;
    std::cout << q.size() << std::endl;
    std::cout << q.empty()<< std::endl;

    q.pop_front();
    q.pop_front();

    std::cout << q.front() << std::endl << q.back() << std::endl;
    std::cout << q.size() << std::endl;
    std::cout << q.empty() << std::endl;


    return 0;
}