#ifndef BINTREE_H
#define BINTREE_H
#include<iostream>
#include<fstream>
#include<functional>
#include<exception>

template<class T>
class BinTree
{
private:
    struct BinTreeNode
    {
        T data;
        BinTreeNode *left, *right;
    };    
    BinTreeNode *root;

    int countHelp(BinTreeNode *curr) const;
    int searchCountHelp(BinTreeNode *curr, std::function<bool(const T&)> pred);
    int heightHelp(BinTreeNode *curr) const;
    void toGvHelp (std::ostream& out, BinTreeNode *curr);
    BinTreeNode* locate(std::string trace) const;

public:
    BinTree();

    void add(const T& x, std::string trace);    
    T get(std::string trace) const;

    //ex.19.1
    int count() const;

    //ex.19.2
    int countEvens();

    //ex.19.3
    int searchCount(std::function<bool(const T&)> pred);

    //ex.19.4
    int height() const;

    void toGv(std::ostream& out);
};

template<class T>
BinTree<T>::BinTree():root(nullptr){}

template<class T>
void BinTree<T>::add(const T& x, std::string trace)
{
    try
    {
        if(!root)
        {
            if(trace.front())
            {
                throw std::runtime_error ("Invalid data!");
            }
            root = new BinTree<T>::BinTreeNode{x, nullptr, nullptr};
            return;
        }
        BinTreeNode *curr = root;
        while(trace.size() > 1)
        {
            if(trace.front() == 'L')
            {
                curr = curr->left;
            }
            else if(trace.front() == 'R')
            {
                curr = curr->right;
            }
            else
            {
                throw std::runtime_error ("Invalid data!");
            }
            if(!curr)
            {
                throw std::runtime_error ("Something wrong with data!");
            }
            trace.erase(trace.begin());
        }
        if(trace.front() == 'L')
        {
            if(curr->left)
            {
                throw std::runtime_error ("Something wrong with data! Cannot add element to the left!");
            }
            curr->left = new BinTree<T>::BinTreeNode{x,nullptr,nullptr};
        }
        else if(trace.front() == 'R')
        {
            if(curr->right)
            {
                throw std::runtime_error ("Something wrong with data! Cannot add element to the right!");
            }
            curr->right = new BinTree<T>::BinTreeNode{x,nullptr,nullptr};
        }
        else
        {
            throw std::runtime_error ("Wrong trace!");
        }  
    }
    catch(std::runtime_error e)
    {
        std::cout << e.what() << '\n';
    }    
}

template<class T>
typename BinTree<T>::BinTreeNode* BinTree<T>::locate(std::string trace) const
{
    try
    {
        BinTreeNode* curr = root;
        while(trace.front())
        {
            if(trace.front() == 'L')
            {
                curr = curr->left;
            }
            else if(trace.front() == 'R')
            {
                curr= curr->right;
            }
            else
            {
                throw std::runtime_error ("Invalid data!");
            }
            if(!curr)
            {
                throw std::runtime_error ("Something wront with data!");
            }
            trace.erase(trace.begin());        
        }
        if(!curr)
        {
            throw std::runtime_error ("Something wront with data!");
        }
        return curr;
    }
    catch(std::runtime_error e)
    {
        std::cout << e.what() << '\n';
        return nullptr;
    }   
}

template<class T>
T BinTree<T>::get(std::string trace) const
{
    BinTreeNode* curr = locate(trace);
    if(!curr)
    {
        throw ("Invalid data!");
    }
    return curr->data;
}

template<class T>
int BinTree<T>::count() const
{
   return countHelp(root);
}

template<class T>
int BinTree<T>::countHelp(BinTreeNode *curr) const
{
    if(!curr)
    {
        return 0;
    }
    return (1 + countHelp(curr->left) + countHelp(curr->right));
}

template<class T>
int BinTree<T>::countEvens()
{
    return searchCount([](const int& x){return x % 2 == 0;});
}

template<class T>
int BinTree<T>::searchCount(std::function<bool(const T&)> pred)
{
    return searchCountHelp(root, pred);
}

template<class T>
int BinTree<T>::searchCountHelp(BinTreeNode *curr, std::function<bool(const T&)> pred)
{
    if(!curr)
    {
        return 0;
    }
    else if(pred(curr->data))
    {
        return 1 + searchCountHelp(curr->left, pred) + searchCountHelp(curr->right, pred);
    }
    else 
    {
        return searchCountHelp(curr->left, pred) + searchCountHelp(curr->right, pred);
    }
}

template <class T>
int BinTree<T>::height() const
{
    return heightHelp(root);
}

template <class T>
int BinTree<T>::heightHelp(BinTreeNode *curr) const
{
    if(!curr)
    {
        return 0;
    }
    else
    {
        int maxLeft = heightHelp(curr->left);
        int maxRight = heightHelp(curr->right);
        return (maxLeft > maxRight ? maxLeft + 1 : maxRight + 1);
    }
}

template <class T>
void BinTree<T>::toGv(std::ostream& out)
{
    out << "digraph G{\n";
    toGvHelp(out, root);
    out << "}";
}

template <class T>
void BinTree<T>::toGvHelp (std::ostream& out, BinTreeNode *curr)
{
    if (curr)
    {     
        out << (long)curr << "[label=\"" << curr->data << "\"];\n";

        if (curr->left)
        {
            out << (long)curr << "->" << (long)(curr->left) << "[color=blue];\n";
        } 
        if (curr->right)
        {
            out << (long)curr << "->" << (long)(curr->right) << "[color=red];\n";
        }
        toGvHelp (out, curr->left);
        toGvHelp (out, curr->right);
    }
}

#endif
