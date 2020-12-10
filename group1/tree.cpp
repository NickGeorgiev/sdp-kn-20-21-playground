#ifndef __TREE_CPP_
#define __TREE_CPP_

#include "tree.h"

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<stack>
#include<queue>

template <class T>
BSTree<T>::BTreeNode::BTreeNode(const T& _data, BTreeNode* _left, BTreeNode* _right, int _height): data{_data}, left{_left}, right{_right}, height{_height} {}

template <class T>
void BSTree<T>::dfs() const {
    dfsHelper(root);
}

template <class T>
void BSTree<T>::bfs() const {
    bfsHelper(root);
}

template <class T>
void BSTree<T>::dfsHelper(BSTree<T>::BTreeNode* _root) const {
    // left root right
    std::stack<Wrapper> stack;
    stack.push({_root, false});

    while (!stack.empty()){
        Wrapper cur = stack.top();
        stack.pop();

        if(cur.toProcess) {
            std::cout << cur.node->data;
        } else {
            if(cur.node->right) {
                stack.push({cur.node->right, false});
            }

            stack.push({cur.node, true});

            if(cur.node->left) {
                stack.push({cur.node->left, false});
            }
        }
    }
    

}

template <class T>
void BSTree<T>::bfsHelper(BSTree<T>::BTreeNode* _root) const {
    std::queue<BSTree<T>::BTreeNode*> nodes;
	nodes.push(_root);

    while(!nodes.empty()){
        BSTree<T>::BTreeNode* current = nodes.front();
        nodes.pop();
        std::cout << current->data << " ";

        if(current->left){
            nodes.push(current->left);
        }

        if(current->right){
            nodes.push(current->right);
        }
    }
}

template <class T>
int BSTree<T>::height() const {
    return height_helper(root);
}

template <class T>
int BSTree<T>::height_helper(const BSTree<T>::BTreeNode* _root) const {
    if(!_root) {
        return -1;
    }
    return std::max(height_helper(_root->left), height_helper(_root->right)) + 1;
}

template <class T>
int BSTree<T>::balance(const BSTree<T>::BTreeNode* _root) const {
    return height_helper(_root->left) - height_helper(_root->right);
}

template <class T>
void BSTree<T>::leftRotation(BSTree<T>::BTreeNode*& _root) {
    BSTree<T>::BTreeNode* rightChild = _root->right;
    BSTree<T>::BTreeNode* leftGrandChild = rightChild->left;
    BSTree<T>::BTreeNode* rootCopy = _root;
    _root = rightChild;
    _root->left = rootCopy;
    _root->left->right = leftGrandChild;
}

template <class T>
void BSTree<T>::rightRotation(BSTree<T>::BTreeNode*& _root) {
    BSTree<T>::BTreeNode* leftChild = _root->left;
    BSTree<T>::BTreeNode* rightGrandChild = leftChild->right;
    BSTree<T>::BTreeNode* rootCopy = _root;
    _root = leftChild;
    _root->right = rootCopy;
    _root->right->left = rightGrandChild;
}

template <class T>
void BSTree<T>::visualizeHelp (std::ostream& out, BTreeNode *curr) const{
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
        visualizeHelp (out, curr->left);
        visualizeHelp (out, curr->right);
    }
}

template <class T>
void BSTree<T>::visualize(std::ostream& out) const
{
    out << "digraph G{\n";
    visualizeHelp(out, root);
    out << "}";
}

template <class T>
bool BSTree<T>::empty() const {
    return !root;
}

template <class T>
bool BSTree<T>::member(const T& element) const {
    return memberHelper(element, root);
}

#endif

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
BSTree<T>::BSTree(): root{nullptr} {}

template <class T>
void BSTree<T>::add(const T& element) {
    addHelper(element, root);
}

template <class T>
void BSTree<T>::addHelper(const T& element, BSTree<T>::BTreeNode*& _root) {
    if (!_root) {
        _root = new BSTree<T>::BTreeNode{element, nullptr, nullptr, 0};
    } else if (element > _root->data) {
        addHelper(element, _root->right);
    } else if (element < _root->data) {
        addHelper(element, _root->left);
    }

    _root->height = std::max(height_helper(_root->left), height_helper(_root->right)) + 1;

    int rootBalance = balance(_root); // hL - hR

    if(rootBalance < -1 && element > _root->right->data) {
        //right right
        leftRotation(_root);
    }
    if(rootBalance < -1 && element < _root->right->data) {
        //right left
        rightRotation(_root->right);
        leftRotation(_root);
    }
    if(rootBalance > 1 && element < _root->left->data) {
        //left left
        rightRotation(_root);
    }
    if(rootBalance > 1 && element > _root->left->data) {
        //left right
        leftRotation(_root->left);
        rightRotation(_root);
    }
}

template <class T>
void BSTree<T>::remove(const T& element) {
    removeHelper(element, root);
}

template <class T>
void BSTree<T>::removeHelper(const T& element, BTreeNode*& _root) {
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
typename BSTree<T>::BTreeNode* BSTree<T>::findMinInRightSubtree(BSTree<T>::BTreeNode* _root) {
    while(_root->left) {
        _root = _root->left;
    }
    return _root;
}

template<class T>
typename BSTree<T>::Iterator BSTree<T>::begin() {
    return Iterator(root);
}

template <class T>
typename BSTree<T>::Iterator BSTree<T>::end () {
    return Iterator(nullptr);
}

template <class T>
void BSTree<T>::Iterator::unwind() {
    while(!elements.empty() && elements.top().node && !elements.top().shouldStop) {
        Wrapper current = elements.top();
        elements.pop();
        if(current.node) {
            if(current.node->right) {
                elements.push({current.node->right, false});
            }

            elements.push({current.node, true});

            if(current.node->left) {
                elements.push({current.node->left, false});
            }
        }
    }
}

template <class T>
BSTree<T>::Iterator::Iterator(BSTree<T>::BTreeNode* _node) {
    if(_node) {
            elements.push({nullptr, false});
    }
    elements.push({_node, false});
    unwind();
}

template <class T>
bool BSTree<T>::Iterator::operator !=(const Iterator& other) {
    return elements.top().node != other.elements.top().node;
}

template <class T>
T BSTree<T>::Iterator::operator*() {
    if(elements.empty()){
        throw std::runtime_error("No elements");
    }
    return elements.top().node->data;
}

template <class T>
typename BSTree<T>::Iterator& BSTree<T>::Iterator::operator++() {
    elements.pop();
    unwind();
    return *this;
}  

namespace utils{
    std::string generateStepLogName(int stepCount) {
        std::string result = "step_";
        return (result+(char)('a'+ stepCount)+".dot");
    }
}


