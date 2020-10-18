#include "skipList.h"

int main() {

    skipList list;

    list.addElement(5);
    list.addElement(12);
    list.addElement(3);
    list.addElement(17);
    list.addElement(8);
    list.addElement(34);
    list.addElement(29);
    list.addElement(2);
    list.addElement(16);
    // list.addElement(21);
    // list.addElement(45);
    // list.addElement(82);
    // list.addElement(7);
    // list.addElement(0);
    // list.addElement(0);
    // list.addElement(0);
    // list.addElement(0);
    // list.addElement(44);
    // list.addElement(86);

   
    list.printList();
    list.printSkips();

    // list2.printList();
    // list2.printSkips();
    // skipList copy(list);
    // copy.printList();
    // copy.printSkips();
    

    return 0;
}