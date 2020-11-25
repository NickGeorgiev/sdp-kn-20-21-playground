#include<iostream>
#include"WildTree.h"

template<class T>
void WildNode<T>::copy(const WildNode& other)
{
    data = other.data;
    childrenSize = other.childrenSize;
    childrenCapacity = other.childrenCapacity;

    children = new WildNode*[childrenCapacity];
    
    for(size_t i = 0 ; i < childrenSize ; ++i )
    {
        children[i] = other.children[i];
    }
}

template<class T>
void WildNode<T>::deleteChildren()
{
    delete children;
}

template<class T>
void WildNode<T>::updateCapacity(size_t newCapacity)
{
    childrenCapacity = newCapacity;
    WildNode<T>** newChildren = new WildNode*[childrenCapacity];
    size_t i = 0;
    
    for( ; i < childrenSize; ++i)
    {
        newChildren[i] = children[i];
    }
    for( ; i < childrenCapacity; ++i)
    {
        newChildren[i] = nullptr;
    }

    deleteChildren();
    children = newChildren;
}

template<class T>
WildNode<T>::WildNode() : children{nullptr}, childrenSize{0}, childrenCapacity{0} {}

template<class T>
WildNode<T>::WildNode(const T& _data) : data{_data}, children{nullptr}, childrenSize{0}, childrenCapacity{0} {}

template<class T>
WildNode<T>::WildNode(const WildNode<T>& other)
{
    copy(other);
}

template<class T>
WildNode<T>& WildNode<T>::operator= (const WildNode& other)
{
    if(this != &other)
    {
        childrenSize = childrenCapacity = 0;
        deleteChildren();
        copy(other);
    }
    return *this;
}

template<class T>
WildNode<T>::~WildNode()
{
    childrenSize = childrenCapacity = 0;
    deleteChildren();
}

template<class T>
void WildNode<T>::addChild(WildNode*& child)
{
    if(childrenSize + 1 > childrenCapacity)
    {
        updateCapacity((childrenSize+1)*2);
    }

    children[childrenSize++] = child;
}

template<class T>
void WildTree<T>::printDotHelper(const WildNode<T>* curr, std::ostream& out) const
{
    if(!curr)
    {
        return;
    }

    out << (long)curr << "[label=\"" << curr->data <<"\"];\n";

    for(size_t i = 0 ; i < curr->childrenSize; ++i)
    {
        if(curr->children[i])
        {
            out << (long)curr << "->" << (long)(curr->children[i]) << ";\n";
            printDotHelper(curr->children[i],out);
        }
    }
}

template<class T>
WildTree<T>::WildTree() : root{nullptr} {}

template<class T>
WildTree<T>::WildTree(WildNode<T>* _root) : root{_root} {}

template<class T>
void WildTree<T>::printDot(std::ostream& out) const
{
    out << "digraph G{\n";
    printDotHelper(root,out);
    out << "}\n";
}
