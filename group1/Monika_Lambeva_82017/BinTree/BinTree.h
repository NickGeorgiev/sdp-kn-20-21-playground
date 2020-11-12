#ifndef BINTREE_H
#define BINTREE_H
#include<cassert>
#include<fstream>

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

public:
    BinTree();

    void add(const T& x, const char* trace);
    BinTreeNode* locate(const char* trace);
    T get(const char* trace);

    //ex.19.1
    int count();
    int countHelp(BinTreeNode *curr);

    //ex.19.2
    int countEvens();
    //int countEvensHelp(BinTreeNode *curr);

    //ex.19.3
    int searchCount(bool(*pred)(const T&));
    int searchCountHelp(BinTreeNode *curr, bool(*pred)(const T&));

    //ex.19.4
    int height();
    int heightHelp(BinTreeNode *curr);

    void toGv(std::ostream& out);
    void toGvHelp (std::ostream& out, BinTreeNode *curr);
};

template<class T>
BinTree<T>::BinTree():root(nullptr){}

template<class T>
void BinTree<T>::add(const T& x, const char* trace)
{
    if(!root)
    {
        assert (!trace[0]);
        root = new BinTree<T>::BinTreeNode{x, nullptr, nullptr};
        return;
    }
    BinTreeNode *curr = root;
    while(trace[1])
    {
        assert(trace[0] == 'L' || trace[0] == 'R');
        if(trace[0] == 'L')
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
        assert(curr);
        trace++;
    }
    if(trace[0] == 'L')
    {
        assert(!curr->left);
        curr->left = new BinTree<T>::BinTreeNode{x,nullptr,nullptr};
    }
    else if(trace[0] == 'R')
    {
        assert(!curr->right);
        curr->right = new BinTree<T>::BinTreeNode{x,nullptr,nullptr};
    }
    else
    {
        assert(false);
    }  
}

template<class T>
typename BinTree<T>::BinTreeNode* BinTree<T>::locate(const char* trace)
{
    BinTreeNode* curr = root;
    while(trace[0])
    {
        assert(trace[0] == 'L' || trace[0] == 'R');
        if(trace[0]=='L')
        {
            curr = curr->left;
        }
        else
        {
            curr= curr->right;
        }
        assert(curr);
        trace++;        
    }
    assert(curr);
    return curr;
}

template<class T>
T BinTree<T>::get(const char* trace)
{
    BinTreeNode* curr = locate(trace);
    assert(curr);
    return curr->data;
}

template<class T>
int BinTree<T>::count()
{
   return countHelp(root);
}

template<class T>
int BinTree<T>::countHelp(BinTreeNode *curr)
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
    //return countEvensHelp(root);
}

// template<class T>
// int BinTree<T>::countEvensHelp(BinTreeNode *curr)
// {
    //if(!curr)
    //{
    //    return 0;
    //}
    //else if(curr->data % 2 == 0)
    //{
    //    return 1 + countEvensHelp(curr->left) + countEvensHelp(curr->right);
    //}
    //else 
    //{
    //    return countEvensHelp(curr->left) + countEvensHelp(curr->right);
    //}
//}

template<class T>
int BinTree<T>::searchCount(bool(*pred)(const T&))
{
    return searchCountHelp(root, pred);
}

template<class T>
int BinTree<T>::searchCountHelp(BinTreeNode *curr, bool(*pred)(const T&))
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
int BinTree<T>::height()
{
    return heightHelp(root);
}

template <class T>
int BinTree<T>::heightHelp(BinTreeNode *curr)
{
    if(!curr)
    {
        return 0;
    }
    else
    {
        int maxLeft = heightHelp(curr->left);
        int maxRight = heightHelp(curr->right);
        if(maxLeft > maxRight)
        {
            return maxLeft + 1;
        }
        else
        {
            return maxRight + 1;
        }
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
