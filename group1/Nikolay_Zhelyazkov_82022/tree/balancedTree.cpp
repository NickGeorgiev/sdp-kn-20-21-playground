#include "balancedTree.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <exception>
template <class T>
BalancedTree<T>::BalancedTree() : root(nullptr)
{
}
template <class T>
bool BalancedTree<T>::empty() const
{
    return !root;
}
template <class T>
bool BalancedTree<T>::memberHelper(const T &data, const BalancedTree<T>::Node *_root) const
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
template <class T>
bool BalancedTree<T>::member(const T &data) const
{
    return memberHelper(data, root);
}
template <class T>
void BalancedTree<T>::addHelper(const T &data, BalancedTree<T>::Node *&_root)
{
    if (!_root)
    {
        _root = new BalancedTree<T>::Node{data};
    }
    else
    {
        if (data < _root->data)
        {
            addHelper(data, _root->left);
        }

        else
        {
            addHelper(data, _root->right);
        }
    }
    _root->height = 1 + std::max(heightHelper(_root->left), heightHelper(_root->right));
    int bal = balance(_root);

    if (bal < -1 && data > _root->right->data)
    {
        leftRotate(_root);
    }
    if (bal < -1 && data < _root->right->data)
    {
        rightRotate(_root->right);
        leftRotate(_root);
    }
    if (bal > 1 && data < _root->left->data)
    {
        rightRotate(_root);
    }
    if (bal > 1 && data < _root->left->data)
    {
        leftRotate(_root->left);
        rightRotate(_root);
    }
}
template <class T>
void BalancedTree<T>::add(const T &data)
{
    addHelper(data, root);
}
template <class T>
int BalancedTree<T>::balance(BalancedTree<T>::Node *&_root) const
{
    return heightHelper(_root->left) - heightHelper(_root->right);
}

template <class T>
void BalancedTree<T>::leftRotate(BalancedTree<T>::Node *&_root)
{
    BalancedTree<T>::Node *rightChild = _root->right;
    BalancedTree<T>::Node *leftGrand = rightChild->left;
    BalancedTree<T>::Node *temp = _root;

    _root = rightChild;
    _root->left = temp;
    _root->left->right = leftGrand;
}
template <class T>
void BalancedTree<T>::rightRotate(BalancedTree<T>::Node *&_root)
{

    BalancedTree<T>::Node *leftChild = _root->left;
    BalancedTree<T>::Node *rightGrand = leftChild->right;
    BalancedTree<T>::Node *temp = _root;

    _root = leftChild;
    _root->right = temp;
    _root->right->left = rightGrand;
}
template <class T>
void BalancedTree<T>::printHelper(BalancedTree<T>::Node *_root) const
{
    if (!_root)
    {
        return;
    }
    printHelper(_root->left);
    std::cout << _root->data << " ";
    printHelper(_root->right);
}
template <class T>
void BalancedTree<T>::printDotHelper(std::ostream &out, BalancedTree<T>::Node *_root) const
{
    if (!_root)
    {
        return;
    }
    printDotHelper(out, _root->left);
    out << (long)_root << "[label=\"" << _root->data << "\"];\n";
    if (_root->left)
    {
        out << (long)_root << "->" << (long)_root->left << "[color=blue];\n";
    }
    if (_root->right)
    {
        out << (long)_root << "->" << (long)_root->right << "[color=red];\n";
    }
    printDotHelper(out, _root->right);
}

template <class T>
void BalancedTree<T>::print() const
{
    printHelper(root);
}
template <class T>
void BalancedTree<T>::printDot(std::ostream &out) const
{
    out << "digraph G{\n";
    printDotHelper(out, root);
    out << "}";
}
template <class T>
void BalancedTree<T>::eraseHelper(const T &data, BalancedTree<T>::Node *&_root)
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
            BalancedTree<T>::Node *save = _root;
            _root = nullptr;
            delete save;
        }
        else if (!_root->left && _root->right)
        {
            BalancedTree<T>::Node *save = _root;
            _root = _root->right;
            delete save;
        }
        else if (_root->left && !_root->right)
        {
            BalancedTree<T>::Node *save = _root;
            _root = _root->left;
            delete save;
        }
        else
        {
            BalancedTree<T>::Node *maxLeftSubBalancedTree = findMaxInLeftSubBalancedTree(_root->left);
            std::swap(_root->data, maxLeftSubBalancedTree->data);
            eraseHelper(data, _root->left);
        }
    }
}
template <class T>
BalancedTree<T>::Node *BalancedTree<T>::findMaxInLeftSubBalancedTree(BalancedTree<T>::Node *_root)
{
    while (_root->right)
    {
        _root = _root->right;
    }
    return _root;
}
template <class T>
void BalancedTree<T>::erase(const T &data)
{
    eraseHelper(data, root);
}
template <class T>
int BalancedTree<T>::count() const
{
    return countFHelper(root, [](T el) -> bool { return true; });
}
template <class T>
int BalancedTree<T>::countHelper(BalancedTree<T>::Node *_root) const
{
    if (!_root)
    {
        return 0;
    }
    return 1 + countHelper(_root->left) + countHelper(_root->right);
}
template <class T>
int BalancedTree<T>::countFHelper(BalancedTree<T>::Node *_root, bool (*f)(T)) const
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
template <class T>
int BalancedTree<T>::countEvens() const
{
    return countFHelper(root, [](int el) -> bool { return el % 2 == 0; });
}
template <class T>
int BalancedTree<T>::heightHelper(BalancedTree<T>::Node *_root) const
{
    if (!_root)
    {
        return -1;
    }
    return 1 + std::max(heightHelper(_root->left), heightHelper(_root->right));
}
template <class T>
int BalancedTree<T>::height() const
{
    return heightHelper(root);
}
template <class T>
int BalancedTree<T>::countHelperLeaves(BalancedTree<T>::Node *_root) const
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
template <class T>
int BalancedTree<T>::countLeaves() const
{
    return countHelperLeaves(root);
}
template <class T>
T BalancedTree<T>::maxHelperLeave(BalancedTree<T>::Node *_root) const
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
template <class T>
T BalancedTree<T>::maxLeave() const
{
    if (empty())
    {
        throw std::out_of_range("Empty Balanced Tree");
        return INT_MIN;
    }
    return maxHelperLeave(root);
}
template <class T>
T &BalancedTree<T>::theLeftestLeaf(BalancedTree<T>::Node *current) const
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
template <class T>
T BalancedTree<T>::maxLeaveNewHelper(BalancedTree<T>::Node *current, T data)
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
template <class T>
T BalancedTree<T>::maxLeaveNew()
{
    T data = theLeftestLeaf(root);
    return maxLeaveNewHelper(root, data);
}
template <class T>
BalancedTree<T>::Node *BalancedTree<T>::locate(const char *s) const
{
    if (empty())
    {
        throw std::out_of_range("Empty Balanced Tree at the locate method -> 315 line");
    }

    if (s[0] == 0)
    {
        return root;
    }
    BalancedTree<T>::Node *current = root;
    while (current && s[0] != 0)
    {
        if (s[0] != 'L' && s[0] != 'R')
        {
            throw std::invalid_argument("Error symbol at the locate method -> 327 line");
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
        throw std::out_of_range("Error road in locate on 342 line");
    }
    return current;
}
template <class T>
T BalancedTree<T>::operator[](const char *s) const
{
    return locate(s)->data;
}
template <class T>
void BalancedTree<T>::set(T element, const char *s)
{
    locate(s)->data = element;
}
template <class T>
void BalancedTree<T>::clearHelper(BalancedTree<T>::Node *&current)
{
    if (!current)
    {
        return;
    }
    if (current && !current->left && !current->right)
    {
        BalancedTree<T>::Node *save = current;
        current = nullptr;
        delete save;
        return;
    }
    clearHelper(current->left);
    clearHelper(current->right);
    if (current && !current->left && !current->right)
    {
        BalancedTree<T>::Node *save = current;
        current = nullptr;
        delete save;
    }
}
template <class T>
void BalancedTree<T>::clear()
{
    clearHelper(root);
}
template <class T>
BalancedTree<T>::~BalancedTree()
{
    clear();
}
template <class T>
void BalancedTree<T>::DFSrlr(BalancedTree<T>::Node *t) const
{
    std::stack<BalancedTree<T>::Node *> stack;
    stack.push(t);

    while (!stack.empty())
    {
        BalancedTree<T>::Node *curr = stack.top();
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
template <class T>
void BalancedTree<T>::BFSHelper(BalancedTree<T>::Node *root) const
{
    std::queue<BalancedTree<T>::Node *> q;
    q.push(root);
    while (!q.empty())
    {
        BalancedTree<T>::Node *cur = q.front();
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
template <class T>
void BalancedTree<T>::bfs() const
{
    BFSHelper(root);
}
template <class T>
void BalancedTree<T>::dfsHelper(BalancedTree<T>::Node *_root) const
{
    std::stack<BalancedTree<T>::Wrapper> s;
    s.push({_root, false});
    while (!s.empty())
    {
        BalancedTree<T>::Wrapper cur = s.top();
        s.pop();
        
        if (cur.toProduce)
        {
            std::cout << cur.node->data;
        }
        else
        {
            if (cur.node->right)
            {
                s.push({cur.node->right, false});
            }
            s.push({cur.node, true});
            if (cur.node->left)
            {
                s.push({cur.node->left, false});
            }
        }
    }
}
template <class T>
void BalancedTree<T>::dfs() const
{
    dfsHelper(root);
}
template <class T>
BalancedTree<T>::Iterator::Iterator(BalancedTree<T>::Node *_node)
{
    elements.push({_node, false});
    unwind();
}
template <class T>
void BalancedTree<T>::Iterator::unwind()
{
    while (!elements.empty() && !elements.top().toProduce)
    {
        BalancedTree<T>::Wrapper cur = elements.top();
        elements.pop();
        if (cur.node)
        {
            if (cur.node->right)
            {
                elements.push({cur.node->right, false});
            }
            elements.push({cur.node, true});
            if (cur.node->left)
            {
                elements.push({cur.node->left, false});
            }
        }
    }
}
template <class T>
bool BalancedTree<T>::Iterator::operator!=(const BalancedTree<T>::Iterator &other)
{
    return other.elements.empty() && !elements.empty();
}
template <class T>
BalancedTree<T>::Iterator &BalancedTree<T>::Iterator::operator++()
{
    elements.pop();
    unwind();
    return *this;
}
template <class T>
T BalancedTree<T>::Iterator::operator*() const
{
    if (elements.empty())
    {
        throw std::runtime_error("No elements");
    }
    return elements.top().node->data;
}
template <class T>
BalancedTree<T>::Iterator BalancedTree<T>::begin()
{
    return BalancedTree<T>::Iterator(root);
}
template <class T>
BalancedTree<T>::Iterator BalancedTree<T>::end()
{
    return BalancedTree<T>::Iterator(nullptr);
}