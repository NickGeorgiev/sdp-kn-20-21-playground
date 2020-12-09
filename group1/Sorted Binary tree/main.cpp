#include "bstree.h"
#include <fstream>


int main() 
{
    BSTree<int> t;
    t.add(7);
    t.add(4);
    t.add(9);
    t.add(8);
    t.add(11);
    t.add(6);
    t.add(7);
    t.add(-3);
    t.add(14);
    t.add(10);
    t.add(-2);
    t.add(18);
    t.add(5);
    t.add(12);

    // std::ofstream file("viztree.dot");
    // t.printDot(file);
    // file.close();

    for(int x : t)
    {
        std::cout << x << " ";
    }

    return 0;    
}