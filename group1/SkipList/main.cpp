#include "SkipList.h"


int main()
{
    SkipList l, l1;

    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);

    std::cout << l.member(2) << std::endl;

     l1 = l;
     std::cout << l1.member(5) << std::endl << l1.member(10) << std::endl;
     l1.print();


    return 0;
}