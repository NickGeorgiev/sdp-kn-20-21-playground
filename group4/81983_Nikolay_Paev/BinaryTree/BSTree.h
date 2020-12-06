#ifndef __BSTREE_H_
#define __BSTREE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

class BSTree
{
    struct BTreeNode
    {
        int data;
        int height;
        BTreeNode *left;
        BTreeNode *right;
        BTreeNode(const int &_data, BTreeNode *_left = nullptr, BTreeNode *_right = nullptr, int _height = 0) : data{_data}, left{_left}, right{_right}, height{_height} {}
    };

    struct DFSWrapper
    {
        BTreeNode *node;
        bool toReturn;
    };

    BTreeNode *root;
    
    bool member_helper(const int &, const BTreeNode *) const;
    void add_helper(const int &, BTreeNode *&);
    void print_helper(const BTreeNode *) const;
    int height_helper(const BTreeNode *) const;
    int balance(BTreeNode *&) const;
    void leftRotate(BTreeNode *&);
    void rightRotate(BTreeNode *&);

    void visualizeHelp(std::ostream &out, BTreeNode *curr) const;

    void dfs_helper(BTreeNode *) const;
    void bfs_helper(BTreeNode *) const;

public:
    BSTree();
    bool empty() const;
    bool member(const int &) const;
    void add_iter(const int &);
    void add_rec(const int &);
    void print() const;
    int height() const;

    void visualize(std::ostream &) const;

    void DFS() const;
    void BFS() const;

    class Iterator
    {
        std::stack<DFSWrapper> elements;

        void unwind();

    public:
        Iterator(BSTree::BTreeNode *root);
        bool operator!=(const Iterator &other);
        int operator*();
        Iterator &operator++();
    };

    Iterator begin();
    Iterator end();
};

#endif
