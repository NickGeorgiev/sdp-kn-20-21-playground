#include <set>
#include <iostream>

int main()
{
    std::set<int> s{1, 2, 3, 4, 5, 6, 8};

    int count = 4;//index koito iskash primerno 4ti
    auto it = s.begin();
    for (int i = 0; i < count; ++i)
    {
        ++it;
    }
    std::cout << *it << std::endl;//izvezhda 5
}