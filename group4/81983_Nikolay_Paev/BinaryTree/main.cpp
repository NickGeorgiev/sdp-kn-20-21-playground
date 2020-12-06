#include "BSTree.cpp"
int main()
{
    BSTree tree;
    std::vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int step = 0;
    for (int element : elements)
    {
        // std::string stepName = utils::generateStepLogName(step++);
        // std::ofstream fout(stepName.c_str());
        tree.add_rec(element);
        // tree.visualize(fout);
    }

    for (auto elem : tree)
    {
        std::cout << elem;
    }
    
    /* BSTree::Iterator it = tree.begin();
    while (it != tree.end()) {
        std::cout << *it << std::endl;
        ++it;
    } */
    
    // tree.BFS();
    // std::cout << std::endl;
    // tree.DFS();
    // std::cout << std::endl;
}
