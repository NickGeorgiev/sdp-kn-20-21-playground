#include <iostream>
#include "dllist.h"
//g++ main.cpp dllist.cpp
int main()
{
  DLList<int> list2;
  DLList<int> list;
  DLList<int> res;

  list += 1;
  list += 2;
  list += 3;
  list.pushInFront(2);
  list2.pushInFront(20);
  list2 += 55;
  list2.setData(35);
  list2 += 99;
  list2.setData(18);
  list2 += 52;
  list2 += 88;
  list += 88;
  list2 += 8656;
  list += 95;
  //list2.setData(7);
  //std::cout << list2 << std::endl;
  list.append(list2);
  list.append(list2);
  list += list2;
  list.pushInFront(85);

  //list.append(list2);
  //list2 = list;
  //operator+=(list, list2);
  //list += list2;
  //append(list, list2);

  //list2 = list;
  //  res = list2;
  //std::cout << res.getBox()->data << std::endl;
  // std::cout<<list.count(3)<<std::endl;
  // std::cout << res << std::endl;
  //std::cout<<list.range(2,3)->data<<std::endl;

  // std::cout << list << std::endl;
  //list+=list2;
  std::cout << list << std::endl;
  //  list.reverse();

  DLList<int> list3;
  list3 += 1;
  list3 += 3;
  list3 += 5;
  list3 += 6;
  list3 += 8;
  list3 += 10;

  DLList<int> list4;
  list4 += 2;
  list4 += 2;
  list4 += 3;
  list4 += 7;
  list4 += 8;
  list4 += 12;

  list.deleteAll(2);
  list.deleteAll(88);

  std::cout << list << std::endl;
  std::cout << list2 << std::endl;
  std::cout << DLList<int>::insertion(list3, list4) << std::endl;
  return 0;
  //std::cout << l << std::endl;
}