#include"DList.h"


int main()
{
DList l;
   l.push(7);
   l.push(6);
   l.push(5);
   l.push(3);
   l.push(2);
   l.push(1);

 DList list;   
    list += 8;
    list += 4;
    list += 1;

//l.append(list);
//std::cout << l << std::endl;
//box* newBox = new box(1);
//std::cout << l.count(newBox,3) << std::endl;
//DList helper;
//std::cout << helper.range(1,5);

//l.removeAllDuplicates();
//std::cout<<l;
//l.reverse();
//std::cout<<l;
//l.removeElement(5);
//std::cout<<l;

std::cout << l << " " << list << std::endl;
l.mergeWithSorted(list);
std::cout<<l;

return 0;
}