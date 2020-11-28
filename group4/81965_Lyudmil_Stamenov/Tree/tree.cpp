#ifndef _TREE_CPP
#define _TREE_CPP
#include <iostream>
#include "tree.h"


template <class T>
Tree<T>::Node::~Node()
{
    if (!this->next)
    {
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        delete this->next[i];
    }
}


template <class T>
Tree<T>::Tree() : root(nullptr) {}


template <class T>
Tree<T>::~Tree()
{
    if (!root)
    {
        return;
    }
    delete root;
}


template <class T>
void Tree<T>::print() const
{
    printHelp(root);
}


template <class T>
void Tree<T>::printHelp(Tree<T>::Node *root) const
{
    if (!root)
    {
        return;
    }
    std::cout << root->data << " ";
    if (root->next == nullptr)
        return;

    if (root->next)
    {
        for (int i = 0; i < 10; ++i)
        {
            printHelp(root->next[i]);
        }
    }
}


template <class T>
void Tree<T>::addFirstNode(const T &data)
{
    if (root)
    {
        delete root;
    }
    root = new Tree<T>::Node(data);
}


template <class T>
void Tree<T>::addToNode(const T &parentData, const T &childData)
{ 
    Tree<T>::Node *parentNode = this->findNode(parentData);
 
    if (!parentNode)
    {
        std::cout << "There is no such node.\n";
        return;
    }
    bool added = false;
    int i = 0;
    if (!parentNode->next)
    {
        parentNode->next = new Tree<T>::Node *[10];
        for (int i = 0; i < 10; ++i)
        {
            parentNode->next[i] = nullptr;
        }
    }
    while (!added && i < 10)
    {

        if (parentNode->next[i] == nullptr)
        {
            added = true;
            parentNode->next[i] = new Node(childData, nullptr);
            
        }
        ++i;
    }
}


template <class T>
typename Tree<T>::Node *Tree<T>::findNode(const T &searchData)
{ 
    if (empty())
    {
        return nullptr;
    }
    return this->findNodeHelp(searchData, root);
}


template <class T>
typename Tree<T>::Node *Tree<T>::findNodeHelp(const T &searchData, Tree<T>::Node *parentNode)
{ 
    if (!parentNode)
    {
        return nullptr;
    }
    if (parentNode->data == searchData)
    {
        return parentNode;
    }
    if (!parentNode->next)
    {
        return nullptr;
    }
    Tree<T>::Node *nextNode;
    for (int i = 0; i < 10; ++i)
    {
        nextNode = this->findNodeHelp(searchData, parentNode->next[i]);
        if (nextNode)
        {
            return nextNode;
        }
    }
    return nullptr;
}


template <class T>
bool Tree<T>::empty() const
{
    return root == nullptr;
}

#endif
