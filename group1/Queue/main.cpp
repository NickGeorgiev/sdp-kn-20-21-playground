#include "stackQueue.h"
#include <queue>
#include <utility>


int main()
{
     int type, x;
    StackQueue<int> q1;
    std::queue<std::pair<int, int>> memory;

    std::pair<int, int> el;
    do
    {
        std::cin >> type;
        x = 0;
        if(type==1)
        {
            std::cin>>x;
        }
        el = std::make_pair(type, x);
        memory.push(el);
    } while (el.first != 0);

    while (!memory.empty())
    {
        switch (memory.front().first)
        {
        case 0:
            break;
        case 1:
            q1.push_back(memory.front().second);
            break;
        case 2:
            q1.pop_front();
            break;
        case 3:
            std::cout << q1.front() << " ";
            break;
        default:
            std::cout << "Error\n";
            break;
        }
        memory.pop();
    }


    return 0;
}