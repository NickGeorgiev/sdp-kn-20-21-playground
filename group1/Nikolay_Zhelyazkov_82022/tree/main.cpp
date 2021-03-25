//#include "tree.h"
#include "balancedTree.h"
#include <fstream>

//g++ main.cpp tree.cpp
//g++ main.cpp balancedTree.cpp
//dot myTree.dot -Tpdf -o tree.pdf
//dot myBalancedTree.dot -Tpdf -o balancedTree.pdf

int main()
{

    try
    {
        // Tree t;
        // t.add(-9);
        // t.add(7);
        // t.add(3);
        // t.add(4);
        // t.add(5);
        // t.add(6);
        // t.add(7);
        // t.add(8);
        // t.add(9);
        // t.add(10);
        // t.add(-2);
        // t.add(-1);
        // t.add(-5);
        // t.add(12);
        // t.add(111);
        // t.add(15);

        // t.erase(7);
        // t.print();
        // std::cout << std::endl;
        // std::ofstream output("myTree.dot");
        // t.printDot(output);
        // output.close();
        // std::cout << t.count() << std::endl;
        // std::cout << t.countEvens() << std::endl;
        // std::cout << t.height() << std::endl;
        // std::cout << t.countLeaves() << std::endl;
        // std::cout << t.maxLeave() << std::endl;
        // std::cout << t.maxLeaveNew() << std::endl;
        // std::cout << t["RL"];

        BalancedTree<int> bt;
        bt.add(-9);
        bt.add(7);
        bt.add(3);
        bt.add(4);
        bt.add(5);
        bt.add(6);
        bt.add(7);
        bt.add(8);
        bt.add(9);
        bt.add(10);
        bt.add(-2);
        bt.add(-1);
        bt.add(-5);
        bt.add(12);
        bt.add(111);
        bt.add(15);
        bt.print();
        std::ofstream outputBt("myBalancedTree.dot");
        bt.printDot(outputBt);
        outputBt.close();
    }
    catch (const char *err)
    {
        std::cout << err << '\n';
    }

    return 0;
}