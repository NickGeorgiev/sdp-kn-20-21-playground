#include "BOTree.h"
#include<fstream>
#include<vector>
#include<exception>

int main()
{
    BOTree<int> tree;
    std::vector<int> elements = {1,2,3,4,5,6,7,8,9,10};
    for(int element: elements) {
        tree.addWithBalance(element);
    }
    std::ofstream out("iter.gv");
    tree.toGv(out);
    out.close();
    try
    {
        //for(BOTree<int>::Iterator it = first.begin(); it != first.end(); ++it)
        for(int elem: tree)
        {
            std::cout << elem << " ";
        }
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }  
    
    return 0;
}
