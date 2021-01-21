#include "list.cpp"

//#include <iostream>
int main()
{
    // Node<int> *el = new Node<int>(3, new Node<int>(5, new Node<int>(7, new Node<int>(2, nullptr))));
    // //printNode(reverse(el));
    // // Node<int> newEl = pushN(el);
    // printNode(el);
    // pushN(el);
    std::cout << "\n";
    ListNode *elem = new ListNode(2, new ListNode(4, new ListNode(3, nullptr)));
    ListNode *elem2 = new ListNode(5, new ListNode(6, new ListNode(4, nullptr)));
    ListNode *el3 = oddEvenList(elem);
    printNode(el3);
    ListNode *el4 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, nullptr))));
    printNode(addTwoNumbers(el3, el4));

    Node<int> *el = new Node<int>(1024, new Node<int>(16, new Node<int>(4, new Node<int>(2, nullptr))));
    std::cout << reduce(el, +[](const int&a,const int&b)->int {return a/b;})<<std::endl;
    //std::cout << reduce(el, del)<<std::endl;
    Node<int> *el2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, nullptr)))));
    shuffle(el2);

    std::stack<int> s1;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    std::stack<int> s2;
    s2.push(7);
    s2.push(6);

    std::stack<int> s3;
    s3.push(11);
    s3.push(10);
    s3.push(9);
    s3.push(8);
    std::stack<int> s4;
    s4.push(12);

    Node<std::stack<int>> *s = new Node<std::stack<int>>(s1, new Node<std::stack<int>>(s2, new Node<std::stack<int>>(s3, new Node<std::stack<int>>(s4, nullptr))));
    equalize(s);
    std::cout << s->next->data.top();

    clear(el);
    clear(el2);
    clear(s);
}