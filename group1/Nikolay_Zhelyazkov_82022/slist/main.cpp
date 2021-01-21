#include "slist.h"
//#include "../specHelper.h"
bool comp(const int &a, const int &b)
{
    return a <= b;
}

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

//   //  test.skipping ();
//     bool t = test.member(61);
//     CHECK(test.member(0));
//     CHECK(test.member(10));
//     CHECK(test.member(20));
//     CHECK(test.member(21));
//     CHECK(test.member(31));
//     CHECK(test.member(40));
// }
int main()
{
    slist test(comp);
    test.pushSorted(1);
    test.pushSorted(2);
    test.pushSorted(3);
    test.pushSorted(4);
    test.pushSorted(5);
    test.pushSorted(6);
    test.pushSorted(7);
    test.pushSorted(8);
    test.skipping();
    std::cout<<test.find(8);
}

// int main()
// {
//doctest::Context().run();
//  slist s1(comp);
// s1.pushSorted(55);
// s1.pushSorted(23);
// s1.pushSorted(78);

// s1.pushSorted(5);
// s1.pushSorted(96);
// s1.pushSorted(55);
// s1+=69;
// slist s2(comp);
// s2 = s1;
// s2+=53;
// s1+=78;
// std::cout<<s2<<std::endl;
// std::cout<<s1;
//   return 0;
// }
