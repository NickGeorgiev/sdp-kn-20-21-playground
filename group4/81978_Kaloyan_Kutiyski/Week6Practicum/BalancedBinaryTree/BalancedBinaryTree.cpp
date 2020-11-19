#pragma once
#include"BalancedBinaryTree.hpp"

template<class T>
void BalancedBinaryTree<T>::load(const ListOrderable<T>& list) {
    if (!empty()) {
        destroy(root);
    }
    ListOrderable<T>* orderedList = new ListOrderable<T>([](const T& l, const T& r) -> bool { return l < r; });
    orderedList->copyInOrder(list);
    root = new Node<T>;
    loadHelper(root, *orderedList, 0, list.getSize() - 1);
    delete orderedList;
}

template<class T>
void BalancedBinaryTree<T>::loadHelper(Node<T>*& node, const ListOrderable<T>& list, const std::size_t& leftIndex, const std::size_t& rightIndex) {
    // this case handles leaves
    if (leftIndex == rightIndex) {
        node->val = list[leftIndex];
        return;
    }
    // this case is for when the node has one child which is a leaf
    // the child is allways smaller than the parent and is therefore a left child
    if (leftIndex == rightIndex - 1) {
        node->val = list[rightIndex];
        node->left = new Node<T>(list[leftIndex]);
        return;
    }
    // general case: node has two children which are may or may not be leaves 
    int mid = (leftIndex + rightIndex) / 2;
    node->val = list[mid];
    node->left = new Node<T>;
    node->right = new Node<T>;

    loadHelper(node->left, list, leftIndex, mid - 1);
    loadHelper(node->right, list, mid+1, rightIndex);
}

template<class T>
void BalancedBinaryTree<T>::print()const {
    if (!empty()) {
        printHelper(root);
    }
}

template<class T>
void BalancedBinaryTree<T>::printHelper(const Node<T>* node)const {
    if (node == root) {
        std::cout << "root ";
    }
    else {
        std::cout << "node ";
    }
    std::cout << node->val;
    if (!node->left && !node->right) {
        std::cout << " leaf\n";
    }
    else {
        if (node->left) {
            std::cout << " left " << node->left->val << ' ';
        }
        if (node->right) {
            std::cout << " right " << node->right->val;
        }
        std::cout << '\n';
    }
    
    if (node->left) {
        printHelper(node->left);
    }
    if (node->right) {
        printHelper(node->right);
    }
}

template<class T>
BalancedBinaryTree<T>::~BalancedBinaryTree() {
    if (!empty()) {
        destroy(root);
    }
}

template<class T>
void BalancedBinaryTree<T>::destroy(Node<T>*& node) {
    if (node->left) {
        destroy(node->left);
    }
    if (node->right) {
        destroy(node->right);
    }
    delete node;
}

template<class T>
bool BalancedBinaryTree<T>::empty()const {
    return root == nullptr;
}

template<class T>
BalancedBinaryTree<T>::BalancedBinaryTree(const ListOrderable<T>& list): root{nullptr} {
    load(list);
}

template<class T>
int BalancedBinaryTree<T>::countSize(const Node<T>* node)const {
    if (!node) {
        return 0;
    }
    int count = 1;
    if (node->left) {
        count += countSize(node->left);
    }
    if (node->right) {
        count += countSize(node->right);
    }
    return count;
}

template<class T>
bool BalancedBinaryTree<T>::isBalanced()const {
    return balancedHelper(root);
}

template<class T>
bool BalancedBinaryTree<T>::balancedHelper(const Node<T>* node)const {
    if (!node) {
        return true;
    }

    int diff = countSize(node->left) - countSize(node->right);
    // in simple terms: the left and the right sub-trees must be (almost)equally large and also balanced
    return -1 <= diff && diff <= 1 && balancedHelper(node->left) && balancedHelper(node->right);
}