#include "skiplist.h"
#include<iostream>


int main () {
    SkipList skipList;

    skipList.insertAt(2, skipList.locate(2));
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

    skipList.insertAt(17, skipList.locate(17));
    std::cout<<std::endl;
    skipList.print();

    skipList.insertAt(18, skipList.locate(18));
    std::cout<<std::endl;
    skipList.print();

    skipList.insertAt(50, skipList.locate(50));
    std::cout<<std::endl;
    skipList.print();

    skipList.insertAt(1, skipList.locate(1));
    std::cout<<std::endl;
    skipList.print();

    std::cout<<skipList.isMember(47)<<" "<<skipList.isMember(50)<<" "<<skipList.isMember(1)<<std::endl;
    std::cout<<skipList.isMember(48)<<" "<<skipList.isMember(51)<<" "<<skipList.isMember(3)<<std::endl;

    return 0;
}
