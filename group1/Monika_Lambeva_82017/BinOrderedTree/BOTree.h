#ifndef BOTREE_H
#define BOTREE_H
#include<iostream>
#include<stack>
#include<queue>

template<class T>
class BOTree {

private:

    struct BOTreeNode {
        T data;
        BOTreeNode* left;
        BOTreeNode* right;
        BOTreeNode(const T& _data):data{_data}, left{nullptr}, right{nullptr} {}
    };

    struct toPrintNode{
        BOTreeNode* node;
        bool toPrint;
    };
    
    BOTreeNode* root;

    void addHelper(const T&, BOTree<T>::BOTreeNode*& curr);
    bool memberHelper(const T&, const BOTree<T>::BOTreeNode* curr) const;
    BOTreeNode* findLeftmostInRightSubtree(BOTreeNode* curr);    
    void removeHelper(const T&, BOTree<T>::BOTreeNode*& curr);
    void printHelper(const BOTree<T>::BOTreeNode* curr) const;
    int heightHelper(const BOTree<T>::BOTreeNode* curr) const;
    void toGvHelp (std::ostream& out, BOTree<T>::BOTreeNode* curr);
    void dfsHelperRootLeftRight(BOTree<T>::BOTreeNode* curr) const;
    void dfsHelperRootRightLeft(BOTree<T>::BOTreeNode* curr) const;
    void dfsHelperLeftRootRight(BOTree<T>::BOTreeNode* curr) const;
    void dfsHelperRightRootLeft(BOTree<T>::BOTreeNode* curr) const;
    void dfsHelperLeftRightRoot(BOTree<T>::BOTreeNode* curr) const;
    void dfsHelperRightLeftRoot(BOTree<T>::BOTreeNode* curr) const;
    void bfsHelper(BOTree<T>::BOTreeNode* curr) const;

public:
    BOTree();
    void add(const T& x);
    void add_iter(const T& x);
    bool member(const T& x) const;
    bool empty() const;
    void remove(const T& x);
    void print() const;
    int height() const;
    void toGv(std::ostream& out);

    void dfsRootLeftRight() const;
    void dfsRootRightLeft() const;
    void dfsLeftRootRight() const;
    void dfsRightRootLeft() const;
    void dfsLeftRightRoot() const;
    void dfsRightLeftRoot() const;
    void bfs() const;
};

template<class T>
void BOTree<T>::addHelper(const T& x, BOTree<T>::BOTreeNode*& curr)
{
    if(!curr)
    {
        curr = new BOTree<T>::BOTreeNode(x);
        return;
    }
    if(x < curr->data)
    {
        addHelper(x, curr->left);
    }
    else if(x > curr->data)
    {
        addHelper(x, curr->right);
    }
    else
    {
        throw "Cannot x==curr->data!";
    }        
}

template<class T>
bool BOTree<T>::memberHelper(const T& x, const BOTree<T>::BOTreeNode* curr) const
{
    if(!curr)
    {
        return false;
    }
    if(x == curr->data)
    {
        return true;
    }
    if(x < curr->data)
    {
        return memberHelper(x, curr->left);
    }
    else
    {
        return memberHelper(x, curr->right);
    }   
}

template<class T>
typename BOTree<T>::BOTreeNode* BOTree<T>::findLeftmostInRightSubtree(BOTree<T>::BOTreeNode* curr)
{
    while(curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

template<class T>
void BOTree<T>::removeHelper(const T& x, BOTree<T>::BOTreeNode*& curr)
{
    if(!curr)
    {
        return;
    }
    if(x < curr->data)
    {
        removeHelper(x, curr->left);
    }
    else if(x > curr->data)
    {
        removeHelper(x, curr->right);
    }
    else
    {
        if(!curr->left && !curr->right)
        {
            BOTreeNode* saver = curr;
            curr = nullptr;
            delete saver;
        }
        else if(!curr->left && curr->right)
        {
            BOTreeNode* saver = curr;
            curr = curr->right;
            delete saver;
        }
        else if(curr->left && !curr->right)
        {
            BOTreeNode* saver = curr;
            curr = curr->left;
            delete saver;
        }
        else
        {
            BOTreeNode* minRightNode = findLeftmostInRightSubtree(curr->right);
            std::swap(curr->data, minRightNode->data);
            removeHelper(x, curr->right);
        }        
    }   
}

template<class T>
void BOTree<T>::printHelper(const BOTree<T>::BOTreeNode* curr) const
{
    if(!curr)
    {
        return;
    }
    std::cout << curr->data << " ";
    printHelper(curr->left);
    printHelper(curr->right);
}

template<class T>
int BOTree<T>::heightHelper(const BOTree<T>::BOTreeNode* curr) const
{
    if(!curr)
    {
        return 0;
    }
    return std::max(heightHelper(curr->left), heightHelper(curr->right)) + 1;
}

template <class T>
void BOTree<T>::toGvHelp (std::ostream& out, BOTree<T>::BOTreeNode *curr)
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

template<class T>
void BOTree<T>::dfsHelperRootLeftRight(BOTree<T>::BOTreeNode* curr) const
{
    //root->left->right
    if(curr)
    {
        std::stack<BOTreeNode*> stack;
        stack.push(curr);
        while(!stack.empty())
        {
            BOTreeNode* saver = stack.top();
            stack.pop();

            std::cout << saver->data << " ";
            if(saver->right)
            {
                stack.push(saver->right);
            }
            if(saver->left)
            {
                stack.push(saver->left);
            }
        }    
    }
}

template<class T>
void BOTree<T>::dfsHelperRootRightLeft(BOTree<T>::BOTreeNode* curr) const
{
    if(curr)
    {
        std::stack<BOTreeNode*> stack;
        stack.push(curr);
        while(!stack.empty())
        {
            BOTreeNode* saver = stack.top();
            stack.pop();
            std::cout << saver->data << " ";
            if(saver->left)
            {
                stack.push(saver->left);
            }
            if(saver->right)
            {
                stack.push(saver->right);
            }
        }
    }    
}

template<class T>
void BOTree<T>::dfsHelperLeftRootRight(BOTree<T>::BOTreeNode* curr) const
{
    if(curr)
    {
        std::stack<toPrintNode> stack;
        stack.push({curr, false});
        while(!stack.empty())
        {
            toPrintNode saver = stack.top();
            stack.pop();
            if(saver.toPrint)
            {
                std::cout << saver.node->data << " ";
            }
            else
            {
                if(saver.node->right)
                {
                    stack.push({saver.node->right, false});
                }
                stack.push({saver.node, true});
                if(saver.node->left)
                {
                    stack.push({saver.node->left, false});
                }
            }           
        }
    }
}

template<class T>
void BOTree<T>::dfsHelperRightRootLeft(BOTree<T>::BOTreeNode* curr) const
{
    if(curr)
    {
        std::stack<toPrintNode> stack;
        stack.push({curr, false});
        while(!stack.empty())
        {
            toPrintNode saver = stack.top();
            stack.pop();
            if(saver.toPrint)
            {
                std::cout << saver.node->data << " ";
            }
            else
            {
                if(saver.node->left)
                {
                stack.push({saver.node->left, false});
                }
                stack.push({saver.node, true});
                if(saver.node->right)
                {
                stack.push({saver.node->right, false});
                }
            }            
        }
    }
}

template<class T>
void BOTree<T>::dfsHelperLeftRightRoot(BOTree<T>::BOTreeNode* curr) const
{
    if(curr)
    {
        std::stack<toPrintNode> stack;
        stack.push({curr, false});
        while(!stack.empty())
        {
            toPrintNode saver = stack.top();
            stack.pop();
            if(saver.toPrint)
            {
                std::cout << saver.node->data << " ";
            }
            else
            {
                stack.push({saver.node, true});
                if(saver.node->right)
                {
                    stack.push({saver.node->right, false});
                }
                if(saver.node->left)
                {
                    stack.push({saver.node->left, false});
                }
            }            
        }
    }
}

template<class T>
void BOTree<T>::dfsHelperRightLeftRoot(BOTree<T>::BOTreeNode* curr) const
{
    if(curr)
    {
        std::stack<toPrintNode> stack;
        stack.push({curr, false});
        while(!stack.empty())
        {
            toPrintNode saver = stack.top();
            stack.pop();
            if(saver.toPrint)
            {
                std::cout << saver.node->data << " ";
            }
            else
            {
                stack.push({saver.node, true});
                if(saver.node->left)
                {
                    stack.push({saver.node->left, false});
                }
                if(saver.node->right)
                {
                    stack.push({saver.node->right, false});
                }
            }
        }
    }
}

template<class T>
void BOTree<T>::bfsHelper(BOTree<T>::BOTreeNode* curr) const
{
    std::queue<BOTreeNode*> q;
    q.push(curr);
    while(!q.empty())
    {
        BOTreeNode* saver = q.front();
        q.pop();
        std::cout << saver->data << " ";
        if(saver->left)
        {
            q.push(saver->left);
        }
        if(saver->right)
        {
            q.push(saver->right);
        }
    }
}

template<class T>
BOTree<T>::BOTree():root{nullptr} {}

template<class T>
void BOTree<T>::add(const T& x)
{
    addHelper(x, root);   
}

template<class T>
void BOTree<T>::add_iter(const T& x)
{
    if(!root)
    {
        root = new BOTree<T>::BOTreeNode(x);
        return;
    }
    BOTreeNode* curr = root;
    while(curr)
    {
        if(x < curr->data)
        {
            if(!curr->left)
            {
                curr->left = new BOTree<T>::BOTreeNode(x);
                return;
            }
            curr = curr->left;
        }
        else if(x > curr->data)
        {
            if(!curr->right)
            {
                curr->right = new BOTree<T>::BOTreeNode(x);
                return;
            }
            curr = curr->right;
        }
        else
        {
            throw "Cannot add!";
        }
    }    
}

template<class T>
bool BOTree<T>::member(const T& x) const
{
    return memberHelper(x, root);
}

template<class T>
bool BOTree<T>::empty() const
{
    return !root;
}

template<class T>
void BOTree<T>::remove(const T& x)
{
    removeHelper(x, root);
}

template<class T>
void BOTree<T>::print() const
{
    printHelper(root);
}

template<class T>
int BOTree<T>::height() const
{
    return heightHelper(root);
}

template <class T>
void BOTree<T>::toGv(std::ostream& out)
{
    out << "digraph G{\n";
    toGvHelp(out, root);
    out << "}";
}

template <class T>
void BOTree<T>::dfsRootLeftRight() const
{
    dfsHelperRootLeftRight(root);
}

template <class T>
void BOTree<T>::dfsRootRightLeft() const
{
    dfsHelperRootRightLeft(root);
}

template <class T>
void BOTree<T>::dfsLeftRootRight() const
{
    dfsHelperLeftRootRight(root);
}

template <class T>
void BOTree<T>::dfsRightRootLeft() const
{
    dfsHelperRightRootLeft(root);
}

template <class T>
void BOTree<T>::dfsLeftRightRoot() const
{
    dfsHelperLeftRightRoot(root);
}

template <class T>
void BOTree<T>::dfsRightLeftRoot() const
{
    dfsHelperRightLeftRoot(root);
}

template <class T>
void BOTree<T>::bfs() const
{
    bfsHelper(root);
}

#endif