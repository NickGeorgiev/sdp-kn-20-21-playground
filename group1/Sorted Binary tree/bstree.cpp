#ifndef __BSTREE__CPP
#define __BSTREE__CPP
#include "bstree.h"


template <class T>
bool BSTree<T>::empty() const {
    return !root;
}

template <class T>
bool BSTree<T>::member(const T& element) const {
    return memberHelper(element, root);
}

template <class T>
bool BSTree<T>::memberHelper(const T& element, const BSTree<T>::BTreeNode* _root) const {
    if (empty()) {
        return false;
    }

    if (element > _root->data) {
        return memberHelper(element, _root->right);
    }

    if (element < _root->data) {
        return memberHelper(element, _root->left);
    }

    return true;
}

template <class T>
void BSTree<T>::add(const T& element) {
    addHelper(element, root);
}

template <class T>
void BSTree<T>::addHelper(const T& element, BSTree<T>::BTreeNode*& _root) {
    if (!_root) {
        _root = new BSTree<T>::BTreeNode{element}; 
        return;
    } 
    else if (element > _root->data) {
        addHelper(element, _root->right);
    } 
    else if (element < _root->data) {
        addHelper(element, _root->left);
    }

    _root->height = std::max(heightHelper(_root->left), heightHelper(_root->right)) + 1;
    int rootBalance = balance(_root);

    if(rootBalance < -1 && element > _root->right->data)
    {
        leftRotation(_root);
    }
    else if(rootBalance < -1 && element < _root->right->data)
    {
        rightRotation(_root->right);
        leftRotation(_root);
    }
    else if(rootBalance > 1 && element < _root->left->data)
    {
        rightRotation(_root);
    }
    else if(rootBalance > 1 && element > _root->left->data)
    {
        leftRotation(_root->left);
        rightRotation(_root);
    }
}

template <class T>
void BSTree<T>::print() const
{
    printHelper(root);
    std::cout << std::endl;
}

template <class T>
void BSTree<T>::printHelper(BSTree<T>::BTreeNode* curr) const
{
    if(!curr)
    {
        return;
    }

    printHelper(curr->left);
    std::cout << curr->data << " ";
    printHelper(curr->right);
}

template <class T>
void BSTree<T>::printDot(std::ostream& out) const
{
    out << "digraph G{\n";
    printDotHelp(out,root);
    out << "}";
}

template <class T>
void BSTree<T>::printDotHelp(std::ostream& out, BSTree<T>::BTreeNode* curr) const
{
    if(curr == nullptr)
    {
        return;
    }

    printDotHelp(out,curr->left);

    out << (long)curr << "[label=\"" << curr->data << "\"]\n";
    
    if(curr->left != nullptr)
    {
        out << (long)curr << "->" << (long)curr->left << "[color=red]"<< ";\n";
    }

    if(curr->right != nullptr)
    {
        out << (long)curr << "->" << (long)curr->right << "[color=blue]"<< ";\n";
    }

    printDotHelp(out,curr->right); 
}

template <class T>
void BSTree<T>::remove(const T& element) {
    removeHelper(element, root);
}

template <class T>
void BSTree<T>::removeHelper(const T& element, BSTree<T>::BTreeNode*& _root) {
    if (!_root) {
        return;
    }
    if (element < _root->data) {
        removeHelper(element, _root->left);
    }

    if (element > _root->data) {
        removeHelper(element, _root->right);
    }

    if (element == _root->data) {
        if (!_root->left && !_root->right) {
            BTreeNode* save = _root;
            _root = nullptr;
            delete save;
        }
        if (!_root->left && _root->right) {
            BTreeNode* save = _root;
            _root = _root->right;
            delete save;
        }
        if (_root->left && !_root->right) {
            BTreeNode* save = _root;
            _root = _root->left;
            delete save;
        } else {
            BTreeNode* minRightNode = findMinInRightSubtree(_root->right);
            std::swap(_root->data, minRightNode->data);
            removeHelper(element, _root->right);
        }
    }
}

template <class T>
int BSTree<T>::height() const
{
    return heightHelper(root);
}

template <class T>
int BSTree<T>::heightHelper(BSTree<T>::BTreeNode* _root) const
{
    if(!_root)
    {
        return -1;
    }

    return std::max(heightHelper(_root->right), heightHelper(_root->left)) + 1;
}

template <class T>
int BSTree<T>::balance(const BSTree<T>::BTreeNode* curr) const
{
    return heightHelper(curr->left) - heightHelper(curr->right);
}

template <class T>
void BSTree<T>::leftRotation(BSTree<T>::BTreeNode*& _root)
{
    BTreeNode* rightChild = _root->right;
    
    if(rightChild->left)
    {
        BTreeNode* leftGrandChild = rightChild->left;
        _root->right = leftGrandChild;
    }

    rightChild->left = _root;
    _root = rightChild;
}

template <class T>
void BSTree<T>::rightRotation(BSTree<T>::BTreeNode*& _root)
{
    BTreeNode* leftChild = _root->left;
    
    if(leftChild->right)
    {
        BTreeNode* rightGrandChild = leftChild->right;
        _root->left = rightGrandChild;
    }

    leftChild->right = _root;
    _root = leftChild;
}

template <class T>
typename BSTree<T>::BTreeNode* BSTree<T>::findMinInRightSubtree(BSTree<T>::BTreeNode* _root) {
    while(_root->left) {
        _root = _root->left;
    }
    return _root;
}


//====ITERATOR====
template <class T>
void BSTree<T>::Iterator::proceed()
{
    while(!s.empty() && !s.top().shouldStop && s.top().node)
    {
        IteratorWrapper current = s.top();
        s.pop();

        if(current.node)
        {
            if(current.node->right)
            {
                s.push({current.node->right, false});
            }

            s.push({current.node, true});

            if(current.node->left)
            {
                s.push({current.node->left, false});
            }
        }
    }
}

template <class T>
BSTree<T>::Iterator::Iterator(BSTree<T>::BTreeNode* _node)
{
    if(_node)
    {
        s.push({nullptr,false});
    }

    s.push({_node,false});
    proceed();
}

template <class T>
T BSTree<T>::Iterator::operator * ()
{
    if(s.empty())
    {
        throw std::runtime_error("No more elements!\n");
    }

    return s.top().node->data;
}

template <class T>
typename BSTree<T>::Iterator::Iterator& BSTree<T>::Iterator::operator ++ ()
{
    s.pop();
    proceed();

    return *this;
}

template <class T>
bool BSTree<T>::Iterator::operator != (const Iterator& other) const
{
    return s.top().node != other.s.top().node;
}

template <class T>
typename BSTree<T>::Iterator BSTree<T>::begin()
{
    return Iterator(root);
}

template <class T>
typename BSTree<T>::Iterator BSTree<T>::end()
{
    return Iterator(nullptr);
}


#endif