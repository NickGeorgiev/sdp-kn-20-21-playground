#ifndef __TREE_H_
#define __TREE_H_

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<stack>
#include<queue>

template <class T>
class BSTree {
    struct BTreeNode {
        T data;
        BTreeNode* left;
        BTreeNode* right;
        int height;
        BTreeNode() = default;
        BTreeNode(const T&, BTreeNode*, BTreeNode*, int);
    };

    struct Wrapper{
        BTreeNode* node;
        bool shouldStop;
    };

    void addHelper(const T&, BSTree::BTreeNode*&);
    bool memberHelper(const T&, const BSTree::BTreeNode*) const;
    void removeHelper(const T&, BSTree::BTreeNode*&);
    int height_helper(const BSTree::BTreeNode*) const;
    int balance(const BSTree::BTreeNode*) const;
    void leftRotation(BSTree::BTreeNode*&);
    void rightRotation(BSTree::BTreeNode*&);
    void visualizeHelp (std::ostream& out, BTreeNode *curr) const;
    void bfsHelper(BSTree::BTreeNode*) const;
    void dfsHelper(BSTree::BTreeNode*) const;
    BTreeNode* findMinInRightSubtree(BTreeNode*);
    BTreeNode* root;

    public:
    class Iterator {
        void unwind();
        std::stack<Wrapper> elements;

        public:
        Iterator(BSTree::BTreeNode*);
        bool operator !=(const Iterator&);
        T operator*();
        Iterator& operator++();
    };
    BSTree();
    void add(const T&);
    bool member(const T&) const;
    bool empty() const;
    void remove(const T&);
    int height() const;
    void visualize(std::ostream&) const;
    void dfs() const;
    void bfs() const;
    Iterator begin();
    Iterator end();
};

#include "tree.cpp"

#endif