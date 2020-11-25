#include <iostream>
#include "skiplist.h"

int main()
{

    Skip_List skip;
    Element *prev_element;

    skip.insert(40);
    skip.insert(18);
    skip.insert(100);
    skip.insert(70);
    skip.insert(123);
    skip.print();

    std::cout << std::endl;

    skip.insert(41);
    skip.insert(19);
    skip.insert(99);
    skip.insert(72);
    skip.insert(1230);
    skip.insert(1229);
    skip.print();

    std::cout << std::endl;
    
    return 0;
}