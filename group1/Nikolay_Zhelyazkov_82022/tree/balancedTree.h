#ifndef _BalancedTree_INCL
#define _BalancedTree_INCL
#include <iostream>
#include <stack>
template <class T>
class BalancedTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        int height;
        Node(const T &_data, Node *_left = nullptr, Node *_right = nullptr, int _height = -1) : data(_data), left(_left), right(_right), height(_height) {}
    };
    struct Wrapper
    {
        Node *node;
        bool toProduce;
    };
    Node *root;
    void addHelper(const T &, Node *&);
    bool memberHelper(const T &, const Node *) const;
    void printHelper(Node *) const;
    void printDotHelper(std::ostream &, Node *) const;
    void eraseHelper(const T &, Node *&);
    typename Node *findMaxInLeftSubBalancedTree(Node *);
    int countHelper(Node *) const;
    int countFHelper(Node *, bool (*f)(T)) const;
    int heightHelper(Node *) const;
    int countHelperLeaves(Node *) const;
    T maxHelperLeave(Node *) const;
    T maxLeaveNewHelper(Node *, T);
    T &theLeftestLeaf(Node *) const;
    typename Node *locate(const char *) const;
    void clear();
    void clearHelper(Node *&);
    void leftRotate(Node *&);
    void rightRotate(Node *&);
    void dfsHelper(Node *) const;
    void DFSrlr(Node *) const;
    void BFSHelper(Node *) const;
    int balance(Node *&) const;

public:
    BalancedTree();
    void add(const T &data);
    bool member(const T &) const;
    bool empty() const;
    void print() const;
    void printDot(std::ostream &) const;
    void erase(const T &);
    int count() const;
    int countEvens() const;
    int height() const;
    int countLeaves() const;
    T maxLeave() const;
    T maxLeaveNew();
    T operator[](const char *) const;
    void set(T, const char *);

    void bfs() const;
    void dfs() const;
    ~BalancedTree();

    class Iterator
    {
        std::stack<BalancedTree::Wrapper> elements;
        void unwind();

    public:
        Iterator(BalancedTree::Node *root);
        bool operator!=(const Iterator &other);
        Iterator &operator++();
        T operator*() const;
    };
    Iterator begin();
    Iterator end();
};

#endif