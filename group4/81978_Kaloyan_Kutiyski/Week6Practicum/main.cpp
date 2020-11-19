#include"BalancedBinaryTree/BalancedBinaryTree.cpp"
#include"ListOrderable/ListOrderable.cpp"
int main() {
    ListOrderable<int> list;
    list.push(100);
    list.push(24);
    list.push(25);
    list.push(20);
    list.push(11);
    list.push(12);
    list.push(23);
    list.push(9);
    list.push(5);
    list.push(7);
    list.push(10);
    list.push(4);
    list.push(3);
    list.push(2);
    list.push(1);

    list.print();
    BalancedBinaryTree<int> bbTree;
    std::cout << std::boolalpha << bbTree.isBalanced() << '\n';
    bbTree.load(list);
    std::cout << std::boolalpha << bbTree.isBalanced() << '\n';
    bbTree.print();

    ListOrderable<int> otherList;
    otherList.push(1);
    otherList.push(3);
    otherList.push(5);
    otherList.push(8);

    otherList.push(16);
    otherList.push(17);
    otherList.push(18);
    otherList.push(19);

    otherList.push(21);
    otherList.push(22);
    otherList.push(23);
    otherList.push(29);

    otherList.push(33);
    otherList.push(36);
    otherList.push(44);
    otherList.push(60);

    otherList.push(67);
    otherList.push(69);
    otherList.push(71);
    otherList.push(72);

    otherList.push(75);
    otherList.push(80);
    otherList.push(81);
    otherList.push(89);

    otherList.print();
    bbTree.load(otherList);
    std::cout << std::boolalpha << bbTree.isBalanced() << '\n';
    bbTree.print();

    ListOrderable<int> anotherList;
    
    anotherList.push(6);
    anotherList.push(13);
    anotherList.push(18);
    anotherList.push(21);
    anotherList.push(24);

    anotherList.push(27);
    anotherList.push(31);
    anotherList.push(33);
    anotherList.push(35);
    anotherList.push(40);

    anotherList.push(44);
    anotherList.push(49);
    anotherList.push(50);

    anotherList.print();
    bbTree.load(anotherList);
    std::cout << std::boolalpha << bbTree.isBalanced() << '\n';
    bbTree.print();



    return 0;
}