#include "skiplist.h"
#include<iostream>


int main () {
    SkipList skipList;

    skipList.insertAt(2, skipList.isMember(2));
    skipList.addToEnd(5);
    skipList.addToEnd(11);
    skipList.addToEnd(12);
    skipList.addToEnd(19);
    skipList.addToEnd(31);
    skipList.addToEnd(45);
    skipList.addToEnd(46);
    skipList.addToEnd(47);
    skipList.addToEnd(49);
    skipList.print();

    skipList.insertAt(17, skipList.isMember(17));
    std::cout<<std::endl;
    skipList.print();

    skipList.insertAt(18, skipList.isMember(18));
    std::cout<<std::endl;
    skipList.print();

    skipList.insertAt(50, skipList.isMember(50));
    std::cout<<std::endl;
    skipList.print();

    skipList.insertAt(1, skipList.isMember(1));
    std::cout<<std::endl;
    skipList.print();

    return 0;
}