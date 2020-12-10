#include "tree.h"
#include"shared/specs/specHelper.h"

TEST_CASE ("BSTREE") {
    BSTree<int> tree;
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);
    tree.add(6);
    tree.add(7);
    tree.add(8);

    int i = 1;
    for (BSTree<int>::Iterator it = tree.begin(); it != tree.end(); ++it) {
        CHECK(*it == i);
        i++;
    }
}