#pragma once
#include"../ListOrderable/ListOrderable.cpp"

template<class T>
class BalancedBinaryTree {
    template<class E>
    struct Node {
        E val;
        Node<E>* left;
        Node<E>* right;

        Node<E>(): left{nullptr}, right{nullptr} {
        };
        Node<E>(const E& _val): val{_val}, left{nullptr}, right{nullptr} {
        }
    };

    Node<T>* root;

    void destroy(Node<T>*&);
    void loadHelper(Node<T>*&, const ListOrderable<T>&, const std::size_t&, const std::size_t&);
    void printHelper(const Node<T>*)const;
    bool balancedHelper(const Node<T>*)const;
    int countSize(const Node<T>*)const;
    
    public:
    BalancedBinaryTree(): root{nullptr} {
    }
    BalancedBinaryTree(const ListOrderable<T>&);
    ~BalancedBinaryTree();
    
    bool empty()const;
    void load(const ListOrderable<T>&);
    void print()const ;
    bool isBalanced()const;
};