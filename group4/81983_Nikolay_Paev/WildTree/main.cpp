#include<iostream>
#include<fstream>
#include"WildTree.cpp"

int main()
{
    WildNode<int> *greatGrandParent = new WildNode<int>(1);

    WildNode<int> *firstGrandParent = new WildNode<int>(2);
    WildNode<int> *secondGrandParent = new WildNode<int>(3);
    WildNode<int> *thirdGrandParent = new WildNode<int>(4);

    WildNode<int> *firstParent = new WildNode<int>(5);
    WildNode<int> *secondParent = new WildNode<int>(6);
    WildNode<int> *thirdParent = new WildNode<int>(7);
    WildNode<int> *fourthParent = new WildNode<int>(8);
    WildNode<int> *fifthParent = new WildNode<int>(9);
    
    WildNode<int> *firstChild = new WildNode<int>(10);
    WildNode<int> *secondChild = new WildNode<int>(11);
    WildNode<int> *thirdChild = new WildNode<int>(12);
    WildNode<int> *fourthChild = new WildNode<int>(13);
    WildNode<int> *fifthChild = new WildNode<int>(14);
    WildNode<int> *sixthChild = new WildNode<int>(15);
    WildNode<int> *seventhChild = new WildNode<int>(16);
    WildNode<int> *eightChild = new WildNode<int>(17);
    WildNode<int> *ninethChild = new WildNode<int>(18);
    WildNode<int> *tenthChild = new WildNode<int>(19);

    firstParent->addChild(firstChild);
    firstParent->addChild(secondChild);
    secondParent->addChild(thirdChild);
    secondParent->addChild(fourthChild);
    thirdParent->addChild(fifthChild);
    thirdParent->addChild(sixthChild);
    fourthParent->addChild(seventhChild);
    fourthParent->addChild(eightChild);
    fifthParent->addChild(ninethChild);
    fifthParent->addChild(tenthChild);

    firstGrandParent->addChild(firstParent);
    firstGrandParent->addChild(secondParent);
    secondGrandParent->addChild(thirdParent);
    thirdGrandParent->addChild(fourthParent);
    thirdGrandParent->addChild(fifthParent);

    greatGrandParent->addChild(firstGrandParent);
    greatGrandParent->addChild(secondGrandParent);
    greatGrandParent->addChild(thirdGrandParent);

    WildNode<int> *root = greatGrandParent;
    WildTree<int> tree(root);

    std::ofstream file("tree.dot");
    tree.printDot(file);
}
