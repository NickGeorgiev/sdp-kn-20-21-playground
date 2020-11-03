#include "SkipList.h"
int main()
{
    SkipList test_list;
    test_list.add_element(1);
    test_list.add_element(4);
    test_list.add_element(5);
    test_list.add_element(2);
    test_list.add_element(4);
    test_list.add_element(0);
    test_list.add_element(6);
    test_list.add_element(3);
    test_list.add_element(9);
    test_list.add_element(8);

    test_list.print();


    test_list.skip_print();
}
