#include"list.h"

int main()
{
  List l;
  l.push(5);
  l.push(4);
  l.push(3);
  l.push(2);
  l.push(1);
  l.push(3);
  l.push(2);
  l.push(3);

 l.print();

 List sec;
 sec.push_back(6);
 sec.push_back(7);
 sec.push_back(8);

l+=sec;
l.print();
l.reverse();
l.print();

    return 0;
}