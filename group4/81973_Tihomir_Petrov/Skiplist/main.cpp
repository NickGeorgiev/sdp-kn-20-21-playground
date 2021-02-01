#include <iostream>
#include <cmath>
#include "Skiplist.h"

int main(){
    // g++ main.cpp Skiplist.cpp -o main.exe
    Skiplist list;
    list.push(1);
    list.push(2);
    list.push(27);
    list.push(150);
    list.push(5);
    list.push(67);

    Skiplist list1 = list;
    list1.print();
    std::cout << std::endl;
    list.reverse();
    list.print();

    // std::cout << std::endl << list.member(1) << std::endl;

    // Skiplist list3;
    // list3.getHead() = list1.locate(150);
    // std::cout << list3.getHead()->data << std::endl;
    return 0;
}