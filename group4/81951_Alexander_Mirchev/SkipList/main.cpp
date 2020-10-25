#include "SkipList.h"

int main()
{

    std::vector<int> array = {1, 4, 3, 6, 5, 6, 7, 45, 2};
    SkipList<int> skipList = SkipList<int>(array);

    skipList.printList();

    std::cout << std::endl;
    std::cout << std::boolalpha << skipList.contains(7);
}
