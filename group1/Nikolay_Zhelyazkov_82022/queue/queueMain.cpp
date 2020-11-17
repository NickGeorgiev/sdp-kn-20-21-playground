//g++ queueMain.cpp queueWithStack.cpp
#include "queueWithStack.h"
#include <vector>
#include <utility>
#include <queue>
int main()
{
    QueueWithStack q1;
    std::queue<std::pair<int, int>> memory;

    // q1.pushBack(1);
    // q1.pushBack(2);
    // q1.pushBack(3);
    // q1.pushBack(4);
    // q1.pushBack(5);
    // std::cout << q1.front() << std::endl;

    //int n;
    // std::cin >> n;
    int type, x;
    std::pair<int, int> el;
    do
    {
        std::cin >> type;
        x = 0;
        if (type == 1)
        {
            std::cin >> x;
        }
        if (type > 1 && type <= 3)
        {
            el = std::make_pair(type, x);
            memory.push(el);
        }
    } while (el.first != 0);
    while (!memory.empty())
    {
        switch (memory.front().first)
        {
        case 1:
            q1.pushBack(memory.front().second);
            break;
        case 2:
            q1.popFront();
            break;
        case 3:
            std::cout << q1.front();
            break;
        default:
            std::cout << "Error\n";
            break;
        }
        memory.pop();
    }

    //   std::vector<std::vector<int>>space;
    //     for (size_t i = 0; i < n; i++)
    //     {
    //         std::cin >> type >> x;
    //         if (type == 1)
    //         {
    //             q1.pushBack(x);

    //         }
    //         else if(type==2){
    //             q1.popFront();
    //         }
    //         else if(type==3){
    //             std::cout<<q1.front()
    //         }
    //     }
    // }