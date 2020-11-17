#include "tree.h"
#include <fstream>
//#include <iostream>
//g++ main.cpp tree.cpp
//dot myTree.dot -Tpdf -o tree.pdf

int main()
{
    try
    {
        Tree t;
        t.add(5);
        t.add(6);
        t.add(2);
        t.add(3);
        t.add(7);
        t.add(-2);
        t.add(1);
        t.add(-1);
        t.add(-5);
        t.add(4);
        t.add(9);
        t.add(12);
        t.add(9);
        t.add(8);
        t.add(10);
        t.add(111);
        t.add(15);
        t.add(6);
        t.add(5);
        t.add(7);

        // t.erase(7);
        // t.print();
        // std::cout << std::endl;
        // std::ofstream output("myTree.dot");
        // t.printDot(output);
        // std::cout << t.count() << std::endl;
        // std::cout << t.countEvens() << std::endl;
        // std::cout << t.height() << std::endl;
        // std::cout << t.countLeaves() << std::endl;
        // std::cout << t.maxLeave() << std::endl;
        // std::cout << t.maxLeaveNew() << std::endl;
        //std::cout << t["RL"];
    }
    catch (const char *err)
    {
        std::cout << err << '\n';
    }

    return 0;
}