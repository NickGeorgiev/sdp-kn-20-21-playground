#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "BSTree.h"

void BSTree::Iterator::unwind()
{
    while (!elements.empty() && !elements.top().toReturn)
    {
        DFSWrapper current = elements.top();
        elements.pop();
        if (current.node->right)
        {
            elements.push({current.node->right, false});
        }

        elements.push({current.node, true});

        if (current.node->left)
        {
            elements.push({current.node->left, false});
        }
    }
}

BSTree::Iterator::Iterator(BSTree::BTreeNode *root)
{
    if(root) 
    {
        elements.push({root, false});
        unwind();
    }
}

bool BSTree::Iterator::operator!=(const Iterator &other)
{
    return (other.elements.empty() && !elements.empty()) || //този ред е за да тръгне синтактичния for
           (!other.elements.empty() && !elements.empty() && elements.top().node != other.elements.top().node);
    //последният ред няма отношение към задачата, но го слагам за да запазя горе-долу смисъла на != на итератори
}

int BSTree::Iterator::operator*()
{
    return elements.top().node->data;
}

BSTree::Iterator &BSTree::Iterator::operator++()
{
    elements.pop();    
    unwind();
    return *this;
}

BSTree::Iterator BSTree::begin()
{
    return BSTree::Iterator(root);
}

BSTree::Iterator BSTree::end()
{
    return BSTree::Iterator(nullptr);
}

BSTree::BSTree() : root{nullptr} {}

bool BSTree::empty() const
{
    return !root;
}

bool BSTree::member(const int &element) const
{
    return member_helper(element, root);
}

bool BSTree::member_helper(const int &element, const BSTree::BTreeNode *rootNode) const
{
    if (!rootNode)
    {
        return false;
    }
    if (element == rootNode->data)
    {
        return true;
    }
    if (element < rootNode->data)
    {
        return member_helper(element, rootNode->left);
    }
    else
    {
        return member_helper(element, rootNode->right);
    }
}

void BSTree::add_iter(const int &element)
{
    if (empty())
    {
        root = new BSTree::BTreeNode{element};
    }
    else
    {
        BSTree::BTreeNode *current = root;
        while (current)
        {
            if (element < current->data && current->left)
            {
                current = current->left;
            }
            else if (element < current->data && !current->left)
            {
                current->left = new BSTree::BTreeNode{element};
            }
            else if (element > current->data && current->right)
            {
                current = current->right;
            }
            else
            {
                current->right = new BSTree::BTreeNode{element};
            }
        }
    }
}

void BSTree::add_rec(const int &element)
{
    add_helper(element, root);
}

void BSTree::add_helper(const int &element, BSTree::BTreeNode *&rootNode)
{
    if (!rootNode)
    {
        rootNode = new BSTree::BTreeNode{element};
    }
    else
    {
        if (element < rootNode->data)
        {
            add_helper(element, rootNode->left);
        }
        else
        {
            add_helper(element, rootNode->right);
        }
    }

    int rootBalance = balance(rootNode); // hL - hR
    if (rootBalance < -1 && element > rootNode->right->data)
    {
        //right right
        leftRotate(rootNode);
    }
    if (rootBalance < -1 && element < rootNode->right->data)
    {
        //right left
        rightRotate(rootNode->right);
        leftRotate(rootNode);
    }
    if (rootBalance > 1 && element < rootNode->left->data)
    {
        //left left
        rightRotate(rootNode);
    }
    if (rootBalance > 1 && element > rootNode->left->data)
    {
        //left right
        leftRotate(rootNode->left);
        rightRotate(rootNode);
    }
}

void BSTree::print_helper(const BTreeNode *rootNode) const
{
    if (!rootNode)
    {
        return;
    }
    print_helper(rootNode->left);
    std::cout << rootNode->data << " ";
    print_helper(rootNode->right);
}

int BSTree::height() const
{
    return height_helper(root);
}

int BSTree::height_helper(const BSTree::BTreeNode *rootNode) const
{
    // height ::= max(height(leftSubTree), height(rightSubTree)) + 1
    if (!rootNode)
    {
        return -1;
    }
    return std::max(height_helper(rootNode->left), height_helper(rootNode->right)) + 1;
}

void BSTree::print() const
{
    // We are going to iterate the tree following the Left-Root-Right strategy
    print_helper(root);
}

int BSTree::balance(BSTree::BTreeNode *&_root) const
{   
    return height_helper(_root->left) - height_helper(_root->right);
}

void BSTree::leftRotate(BSTree::BTreeNode *&_root)
{
    BTreeNode *rightChild = _root->right;
    BTreeNode *leftGrandChild = rightChild->left;
    BTreeNode *rootCopy = _root;
    _root = rightChild;
    _root->left = rootCopy;
    _root->left->right = leftGrandChild;
    /* BTreeNode *newRoot = _root->right;
    _root->right = newRoot->left;
    newRoot->left = _root;
    _root = newRoot; */
}

void BSTree::rightRotate(BSTree::BTreeNode *&_root)
{
    BTreeNode *leftChild = _root->left;
    BTreeNode *rightGrandChild = leftChild->right;
    BTreeNode *rootCopy = _root;
    _root = leftChild;
    _root->right = rootCopy;
    _root->right->left = rightGrandChild;
    /* BTreeNode *newRoot = _root->left;
    _root->left = newRoot->right;
    newRoot->right = _root;
    _root = newRoot; */
}

void BSTree::visualize(std::ostream &out) const
{
    out << "digraph G{\n";
    visualizeHelp(out, root);
    out << "}";
}

void BSTree::visualizeHelp(std::ostream &out, BTreeNode *curr) const
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
        visualizeHelp(out, curr->left);
        visualizeHelp(out, curr->right);
    }
}

void BSTree::DFS() const
{
    dfs_helper(root);
}

void BSTree::BFS() const
{
    bfs_helper(root);
}

void BSTree::dfs_helper(BTreeNode *_root) const
{

    std::stack<DFSWrapper> s;

    s.push({_root, false});
    while (!s.empty())
    {
        DFSWrapper curr = s.top();
        s.pop();
        if (curr.node)
        {
            if (curr.toReturn)
            {
                std::cout << curr.node->data << ' ';
            }
            else
            {
                s.push({curr.node->left, false});
                s.push({curr.node, true});
                s.push({curr.node->right, false});
            }
        }
    }
}

void BSTree::bfs_helper(BTreeNode *_root) const
{
    std::queue<BTreeNode *> q;

    q.push(_root);
    while (!q.empty())
    {
        BTreeNode *curr = q.front();
        q.pop();

        if (curr)
        {
            std::cout << curr->data << " ";
            q.push(curr->right);
            q.push(curr->left);
        }
    }
}

namespace utils
{
    std::string generateStepLogName(int stepCount)
    {
        std::string result = "step_";
        return (result + (char)('1' + stepCount) + ".dot");
    }
}; // namespace utils
