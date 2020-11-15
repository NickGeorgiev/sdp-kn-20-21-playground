#ifndef _TREE_H
#define _TREE_H
#include <iostream>
template <class T>
class Tree
{
    struct Node
    {
        Node **next;
        T data;
        Node(const T &_data, Node **_next = nullptr) : data{_data}
{
    if (!_next)
    {
        this->next = nullptr;
    }
    else
    {
        next = new Node *[10];
        int i=0;
        while (i < 10 && _next)
        {
            this->next[i] = new Node(_next[i]->data);
            _next++;
            ++i;
        }
    }
};
        ~Node();
    };

public:
    Tree();
    ~Tree();
    void addToNode(const T &, const T &);
    void addFirstNode(const T &);
    Node *findNode(const T &searchData);
    void print() const;
    bool empty() const;

private:
    Node *root;
    void printHelp(Tree<T>::Node *) const;
    Node *findNodeHelp(const T &, Node *);
};
#include "tree.cpp"
#endif