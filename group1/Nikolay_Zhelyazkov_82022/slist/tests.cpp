#include "shared/specs/specHelper.h"
#include "slist.h"
bool comp(const int &a, const int &b)
{
    return a <= b;
}

TEST_CASE("Insert Test")
{
    Slist test(comp);
    test.pushSorted(10);
    test.pushSorted(0);
    test.pushSorted(20);
    test.pushSorted(10);

    CHECK(test.size() == 4);
}

TEST_CASE("Sorting test")
{
    Slist test(comp);
    test.pushSorted(10);
    test.pushSorted(0);
    test.pushSorted(20);
    test.pushSorted(10);
    for (size_t count = 0; count < 20; count++)
    {
        test.pushSorted(21 + count);
    }
    std::cout << test;
}

TEST_CASE("Member test")
{
    Slist test(comp);
    test.pushSorted(10);
    test.pushSorted(0);
    test.pushSorted(20);
    test.pushSorted(10);
    for (size_t count = 0; count < 20; count++)
    {
        test.pushSorted(21 + count);
    }

    //  test.skipping ();
    bool t = test.member(61);
    CHECK(test.member(0));
    CHECK(test.member(10));
    CHECK(test.member(20));
    CHECK(test.member(21));
    CHECK(test.member(31));
    CHECK(test.member(40));
}
