#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include <assert.h>

template <class T>
class LList
{
protected:
    struct Node
    {
        T data;
        Node* next;

        Node(const T& _data, Node* _next) : data(_data), next(_next) {}

        void print() const
        {
            std::cout << data;
        }
    };

    Node *first, *last;
    size_t length;
    
    Node* at(size_t);

    void copy(const LList&);

public:
    LList();
    LList(const LList&);
    ~LList();

    const size_t size();

    void push_front(const T&);
	void pop_front();

	void insertAfter(const T&, size_t);
	void deleteAfter(size_t);

	void push_back(const T&);
    void pop_back();

    void clear();

	T& operator [] (const size_t);
	T operator [] (const size_t) const;

    LList& operator=(const LList&);

    void print() const;

    void reverse();
};

/*
methods to add:

void insertAt(const int& other, size_t index);
void deleteAt(size_t index);
*/


#endif