#include "slist.h"
#include "../usefulFunctions/specHelper.h"
bool comp(const int &a, const int &b)
{
    return a <= b;
}
// int main()
// {
//     slist test(comp);
//     test.pushSorted(1);
//     test.pushSorted(2);
//     test.pushSorted(3);
//     test.pushSorted(4);
//     test.pushSorted(5);
//     test.pushSorted(6);
//     test.pushSorted(7);
//     test.pushSorted(8);
//     std::cout << test;
// }
// TEST_CASE("Insert Test")
// {
//     slist test(comp);
//     test.pushSorted(10);
//     test.pushSorted(0);
//     test.pushSorted(20);
//     test.pushSorted(10);

//     CHECK (test.size () == 4);
// }

// TEST_CASE("Sorting test")
// {
//     slist test(comp);
//     test.pushSorted(10);
//     test.pushSorted(0);
//     test.pushSorted(20);
//     test.pushSorted(10);
//     for (size_t count = 0; count < 20; count++)
//     {
//         test.pushSorted (21+count);
//     }
//     std::cout<<test;
// }

// TEST_CASE("Member test")
// {
//     slist test(comp);
//     test.pushSorted(10);
//     test.pushSorted(0);
//     test.pushSorted(20);
//     test.pushSorted(10);
//     for (size_t count = 0; count < 20; count++)
//     {
//         test.pushSorted(21 + count);
//     }

//     test.skipping ();
//     bool t = test.member(61);
//     CHECK(test.member(0));
//     CHECK(test.member(10));
//     CHECK(test.member(20));
//     CHECK(test.member(21));
//     CHECK(test.member(31));
//     CHECK(test.member(40));
// }
