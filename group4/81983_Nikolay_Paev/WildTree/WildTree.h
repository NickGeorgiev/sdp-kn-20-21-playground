#ifndef __WILD_TREE_H_
#define __WILD_TREE_H_

#include<iostream>

template<class T>
struct WildNode
{
    T data;
    WildNode<T>** children;// overkill е знам, но исках да си упражня каноничното представяне

    size_t childrenSize;
    size_t childrenCapacity;

    void copy(const WildNode& other);
    void deleteChildren();
    void updateCapacity(size_t newCapacity);


    WildNode();
    WildNode(const T& _data);
    WildNode(const WildNode& other);
    WildNode& operator= (const WildNode& other);
    ~WildNode();

    void addChild(WildNode*& child);
    // много не разбрах концепцията на метода на дървото да закачаме директно наследник 
    //и по-точно не разбрах,как ще покажем къде точно да го закачим,
    //затова направих add да е метод на Node
};

template<class T>
class WildTree
{
    
    WildNode<T>* root;

    void printDotHelper(const WildNode<T>*, std::ostream&) const;

    public:
    WildTree();
    WildTree(WildNode<T>* _root);

    void printDot(std::ostream&) const;
};

#endif
