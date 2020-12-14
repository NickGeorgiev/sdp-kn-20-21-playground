#ifndef __BSTREE__H
#define __BSTREE__H
#include <iostream>
#include <stack>
#include <exception>

template<class T>
class BSTree 
{
private:
    struct BTreeNode 
    {
        T data;
        BTreeNode* left;
        BTreeNode* right;
        int height;

        BTreeNode(const T& _data, BTreeNode* _left=nullptr, BTreeNode* _right=nullptr, int _height=0)
            : data{_data}, left{_left}, right{_right}, height{_height} {}
    };
    BTreeNode* root;

    void addHelper(const T&, BSTree<T>::BTreeNode*&);
    bool memberHelper(const T&, const BSTree<T>::BTreeNode*) const;
    void removeHelper(const T&, BSTree<T>::BTreeNode*&);
    void printHelper(BSTree<T>::BTreeNode*) const;
    void printDotHelp(std::ostream& , BSTree<T>::BTreeNode*) const;
    BTreeNode* findMinInRightSubtree(BTreeNode*);
    int heightHelper (BSTree<T>::BTreeNode*) const;
    int balance(const BSTree<T>::BTreeNode*) const;
    void leftRotation(BSTree<T>::BTreeNode*&);
    void rightRotation(BSTree<T>::BTreeNode*&);
    void serializeHelper(BSTree<T>::BTreeNode* _root, std::ostream& out) const;
    BTreeNode* deserializeHelper (std::istream &in);


public:
    class Iterator
    {
    private:
        struct IteratorWrapper
        {
            BTreeNode* node;
            bool shouldStop;
        };

        std::stack<IteratorWrapper> s;

        void proceed();

    public:
        Iterator(BSTree<T>::BTreeNode* _node);

        T operator * ();
        Iterator& operator ++ ();
        bool operator != (const Iterator& other) const;
    };

public:
    BSTree(): root{nullptr} {}
    ~BSTree();

    void deleteTree(BSTree<T>::BTreeNode* _root);
    void add(const T&);
    void remove(const T&);
    void print() const;
    void printDot(std::ostream& out) const;
    bool member(const T&) const;
    bool empty() const;
    int height() const;
    void serialize(std::ostream& out) const;
    void deserialize (std::istream &in);

    Iterator begin();
    Iterator end();
};

#endif

#include "bstree.cpp"