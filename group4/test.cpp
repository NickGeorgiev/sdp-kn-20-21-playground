#include"skiplist.h"

//to compile: g++ test.cpp skiplist.h skiplist.cpp

int main() {

  SkipList aList;
  aList.addElement(5);
  aList.addElement(27);
  aList.addElement(53);
  aList.addElement(67);
  aList.addElement(10);
  aList.addElement(52);
  aList.addElement(256);

  aList.print();

  std::cout<<std::endl;

  aList.printSkips();

  return 0;
}

//I think I have messed up the logic but I'll fix it these days