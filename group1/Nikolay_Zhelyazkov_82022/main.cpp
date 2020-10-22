#include "slist.h"
bool comp(const int &a, const int &b)
{
    return a <= b;
}
int main()
{
    slist s1(comp);
    s1.pushSorted(55);
    s1.pushSorted(23);
    s1.pushSorted(78);

    s1.pushSorted(5);
    s1.pushSorted(96);
    s1.pushSorted(55);
    s1 += 69;
    slist s2(comp);
    s2 = s1;
    s2 += 53;
    s1 += 78;
    std::cout << s2 << std::endl;
    std::cout << s1;
    return 0;
}