#include "tree.h"
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <exception>
Tree::Tree() : root(nullptr)
{
}

bool Tree::empty() const
{
    return !root;
}
bool Tree::memberHelper(const int &data, const Tree::Node *_root) const
{
    if (!_root)
    {
        return false;
    }
    if (data < root->data)
    {
        return memberHelper(data, _root->left);
    }
    else if (data > root->data)
    {
        return memberHelper(data, _root->right);
    }
    return true;
}
bool Tree::member(const int &data) const
{
    return memberHelper(data, root);
}
void Tree::addHelper(const int &data, Tree::Node *&_root)
{
    if (!_root)
    {
        _root = new Tree::Node{data};
        return;
    }
    if (data < _root->data)
    {
        addHelper(data, _root->left);
    }
    else if (data > _root->data)
    {
        addHelper(data, _root->right);
    }
}
void Tree::add(const int &data)
{
    addHelper(data, root);
}
void Tree::printHelper(Tree::Node *_root) const
{
    if (!_root)
    {
        return;
    }
    printHelper(_root->left);
    std::cout << _root->data << " ";
    printHelper(_root->right);
}
void Tree::printDotHelper(std::ostream &out, Tree::Node *_root) const
{
     if (!_root)
    {
        return;
    }
    printDotHelper(out, _root->left);
    out << (long)_root << "[label=\"" << _root->data << "\"];\n";
    if (_root->left)
    {
        out << (long)_root << "->" << (long)_root->left <<"[color=blue];\n";
    }
    if (_root->right)
    {
        out << (long)_root << "->" << (long)_root->right << "[color=red];\n";
    }
    printDotHelper(out, _root->right);
}
void Tree::print() const
{
    printHelper(root);
}
void Tree::printDot(std::ostream &out) const
{
    out << "digraph G{\n";

    printDotHelper(out, root);
    out << "}";
}

void Tree::eraseHelper(const int &data, Tree::Node *&_root)
{
    
    if (!_root)
    {
        return;
    }
    if (data < _root->data)
    {
        eraseHelper(data, _root->left);
    }
    else if (data > _root->data)
    {
        eraseHelper(data, _root->right);
    }
    else
    {
        if (!_root->left && !_root->right)
        {
            Tree::Node *save = _root;
            _root = nullptr;
            delete save;
        }
        else if (!_root->left && _root->right)
        {
            Tree::Node *save = _root;
            _root = _root->right;
            delete save;
        }
        else if (_root->left && !_root->right)
        {
            Tree::Node *save = _root;
            _root = _root->left;
            delete save;
        }
        else
        {
            Tree::Node *maxLeftSubTree = findMaxInLeftSubtree(_root->left);
            std::swap(_root->data, maxLeftSubTree->data);
            eraseHelper(data, _root->left);
        }
    }
}
Tree::Node *Tree::findMaxInLeftSubtree(Tree::Node *_root)
{
    while (_root->right)
    {
        _root = _root->right;
    }
    return _root;
}
void Tree::erase(const int &data)
{
    eraseHelper(data, root);
}
int Tree::count() const
{
    //return countHelper(root);
    return countFHelper(root, [](int el) -> bool { return true; });
}
int Tree::countHelper(Tree::Node *_root) const
{
    if (!_root)
    {
        return 0;
    }
    return 1 + countHelper(_root->left) + countHelper(_root->right);
}
int Tree::countFHelper(Tree::Node *_root, bool (*f)(int)) const
{
    if (!_root)
    {
        return 0;
    }
    if (f(_root->data))
    {
        return 1 + countFHelper(_root->left, f) + countFHelper(_root->right, f);
    }
    return countFHelper(_root->left, f) + countFHelper(_root->right, f);
}
int Tree::countEvens() const
{
    return countFHelper(root, [](int el) -> bool { return el % 2 == 0; });
}
int Tree::heightHelper(Tree::Node *_root) const
{
    if (!_root)
    {
        return -1;
    }
    return 1 + std::max(heightHelper(_root->left), heightHelper(_root->right));
}
int Tree::height() const
{
    return heightHelper(root);
}
int Tree::countHelperLeaves(Tree::Node *_root) const
{
    if (!_root)
    {
        return 0;
    }
    if (!_root->left && !_root->right && _root)
    {
        return 1;
    }
    return countHelperLeaves(_root->left) + countHelperLeaves(_root->right);
}
int Tree::countLeaves() const
{
    return countHelperLeaves(root);
}

int Tree::maxHelperLeave(Tree::Node *_root) const
{

    if (!_root->left && !_root->right && _root)
    {
        return _root->data;
    }
    else if (!_root->right && root && _root->left)
    {
        return maxHelperLeave(_root->left);
    }
    else
    {
        return maxHelperLeave(_root->right);
    }
}
int Tree::maxLeave() const
{
    if (empty())
    {
        throw std::out_of_range("Empty Balanced Tree");
        return INT_MIN;
    }
    return maxHelperLeave(root);
}
int &Tree::theLeftestLeaf(Tree::Node *current) const
{
    while (current->left || current->right)
    {
        if (!current->left && current->right)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
        if (!current->left && !current->right)
        {
            return current->data;
        }
    }
    return current->data;
}
int Tree::maxLeaveNewHelper(Tree::Node *current, int data)
{
    if (!current)
    {
        return data;
    }
    if (current && !current->left && !current->right)
    {
        data = std::max(data, current->data);
    }
    return std::max(maxLeaveNewHelper(current->left, data), maxLeaveNewHelper(current->right, data));
}
int Tree::maxLeaveNew()
{
    int data = theLeftestLeaf(root);
    return maxLeaveNewHelper(root, data);
}
Tree::Node *Tree::locate(const char *s) const
{
    if (empty())
    {
        throw std::out_of_range("Empty tree at the locate method -> 273 line");
    }

    if (s[0] == 0)
    {
        return root;
    }
    Tree::Node *current = root;
    while (current && s[0] != 0)
    {
        if (s[0] != 'L' && s[0] != 'R')
        {
            throw "Error symbol at the locate method -> 285 line";
        }
        if (s[0] == 'L')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
        ++s;
    }
    if (!current)
    {
        throw std::out_of_range("Error road in locate on 299 line");
    }
    return current;
}
int Tree::operator[](const char *s) const
{
    return locate(s)->data;
}
void Tree::set(int element, const char *s)
{
    locate(s)->data = element;
}
void Tree::clearHelper(Tree::Node *&current)
{
    if (!current)
    {
        return;
    }
    if (current && !current->left && !current->right)
    {
        //std::cout << "deleted " << current->data << std::endl;
        Tree::Node *save = current;
        current = nullptr;
        delete save;
        return;
    }
    clearHelper(current->left);
    clearHelper(current->right);
    if (current && !current->left && !current->right)
    {
        // std::cout << "deleted " << current->data << std::endl;
        Tree::Node *save = current;
        current = nullptr;
        delete save;
    }
}
void Tree::clear()
{
    clearHelper(root);
}
Tree::~Tree()
{
    clear();
}

void Tree::DFS(Tree::Node *t) const
{
    std::stack<Tree::Node *> stack;
    stack.push(t);

    while (!stack.empty())
    {
        Tree::Node *curr = stack.top();
        stack.pop();

        std::cout << curr->data << " -> ";

        if (!curr->left && !curr->right)
        {
            continue;
        }

        stack.push(curr->left);
        stack.push(curr->right);
    }
}
void Tree::BFS(Tree::Node *root) const
{
    std::queue<Tree::Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree::Node *cur = q.front();
        q.pop();
        std::cout << cur->data << " -> ";
        if (!cur->left && !cur->right)
        {
            continue;
        }

        q.push(cur->left);
        q.push(cur->right);
    }
}
