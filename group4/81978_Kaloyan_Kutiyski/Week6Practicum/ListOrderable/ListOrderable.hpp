#pragma once
#include<functional>

template<class T>
class ListOrderable {
    template<class E>
    struct Node {
        E val;
        Node<E>* prev;
        Node<E>* next;
        Node<E>(const E& _val): val{_val}, prev{nullptr}, next{nullptr} {
        }
    };

    Node<T>* first;
    Node<T>* last;
    size_t size;
    bool isSorted;
    std::function<bool(const T& l, const T& r)> orderRelation;

    void destroy();
    void copy(const ListOrderable<T>& other);

    void pushUnsorted(const T&);
    void pushSorted(const T&, std::function<bool(const T&, const T&)>&);

    public:
    ListOrderable();
    ListOrderable(std::function<bool(const T&, const T&)>);
    ListOrderable(const ListOrderable<T>& other);
    ListOrderable<T>& operator=(const ListOrderable<T>& other);
    ~ListOrderable();

    bool empty()const;
    void push(const T& val);
    void print()const;
    void copyInOrder(const ListOrderable<T>& other);

    std::size_t getSize()const;
    T operator[](const size_t&)const;
};