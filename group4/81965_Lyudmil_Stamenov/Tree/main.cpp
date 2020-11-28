#include "tree.h"
int main(){

Tree<int> myTree;

myTree.addFirstNode(1);

myTree.addToNode(1,11);
myTree.addToNode(1,12);
myTree.addToNode(1,13);
myTree.addToNode(1,14);
myTree.addToNode(12,121);
myTree.addToNode(12,122);
myTree.addToNode(122,1221);

myTree.print();

    return 0;
}