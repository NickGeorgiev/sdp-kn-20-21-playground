#pragma once
#include<functional>
#include"ListOrderable.hpp"
#include<iostream>

template<class T>
void ListOrderable<T>::destroy() {
    while (first) {
        ListOrderable<T>::Node<T>* toDelete = first;
        first = first->next;
        delete toDelete;
    }
}

template<class T>
void ListOrderable<T>::copy(const ListOrderable<T>& other) {
    if (other.empty()) {
        return;
    }
    isSorted = other.isSorted;
    orderRelation = other.orderRelation;

    first = new Node<T>(other.first->val);
    Node<T>* thisCurr = first;
    Node<T>* otherCurr = other.first->next;

    while (otherCurr) {
        Node<T>* newNode = new Node<T>(otherCurr->val);
        thisCurr->next = newNode;
        newNode->prev = thisCurr;
        last = newNode;

        thisCurr = newNode;
        otherCurr = otherCurr->next;
    }
    size = other.size;
}

template<class T>
ListOrderable<T>::ListOrderable(): size{0}, first{nullptr}, last{nullptr}, isSorted{false}, orderRelation{nullptr} {
};

template<class T>
ListOrderable<T>::ListOrderable(std::function<bool(const T& l, const T& r)> _orderRelation):
    size{0}, first{nullptr}, last{nullptr}, isSorted{true}, orderRelation{_orderRelation} {
}

template<class T>
ListOrderable<T>::ListOrderable(const ListOrderable<T>& other) {
    copy(other);
}

template<class T>
ListOrderable<T>::~ListOrderable() {
    destroy();
}

template<class T>
ListOrderable<T>& ListOrderable<T>::operator=(const ListOrderable<T>& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

template<class T>
bool ListOrderable<T>::empty()const {
    return !(bool)first;
}

template<class T>
void ListOrderable<T>::push(const T& val) {
    if (empty()) {
        Node<T>* newNode = new Node<T>(val);
        first = last = newNode;
    }
    else if (isSorted) {
        pushSorted(val, orderRelation);
    }
    else {
        pushUnsorted(val);
    }
    size++;
} 

template<class T>
void ListOrderable<T>::pushUnsorted(const T& val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
}

template<class T>
void ListOrderable<T>::pushSorted(const T& val, std::function<bool(const T& l, const T& r)>& comparator) {
    Node<T>* curr = first;
    while (curr) {
        if (!curr->prev && comparator(val, curr->val)) {
            Node<T>* newNode = new Node<T>(val);
            curr->prev = newNode;
            newNode->next = curr;
            first = newNode;
            break;
        }
        else if (!curr->next && comparator(curr->val, val)) {
            Node<T>* newNode = new Node<T>(val);
            curr->next = newNode;
            newNode->prev = curr;
            last = newNode;
            break;
        }
        else if (comparator(curr->val, val) && comparator(val, curr->next->val)) {
            Node<T>* newNode = new Node<T>(val);
            curr->next->prev = newNode;
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next = newNode;
            break;
        }
        curr = curr->next;
    }
}

template<class T>
T ListOrderable<T>::operator[](const std::size_t& index)const {
    if (index < 0 || index >= size) {
        throw std::range_error("index out of bounds");
    }
    Node<T>* curr = first;
    int counter = 0;
    T res;
    while(curr) {
        if (counter == index) {
            res = curr->val;
            break;
        }
        else {
            curr = curr->next;
            counter++;
        }
    }
    return res;
}


template<class T>
void ListOrderable<T>::print()const {
    Node<T>* curr = first;
    while (curr) {
        // (curr->val).print();
        std::cout << curr->val;
        if (curr->next) { 
            std::cout << ", ";
        }
        curr = curr->next;
    }
    std::cout << '\n';
}

template<class T>
std::size_t ListOrderable<T>::getSize()const {
    return size;
}

template<class T>
void ListOrderable<T>::copyInOrder(const ListOrderable<T>& other) {
    if (this != &other) {
        destroy();
        Node<T>* curr = other.first;
        while (curr) {
            push(curr->val);
            curr = curr->next;
        }
    } 
}