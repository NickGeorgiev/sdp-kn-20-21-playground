#ifndef LLIST_H
#define LLIST_H

#include <iostream>

template <class T>
class LList
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(const T& _data, Node* _next) : data(_data), next(_next) {}
    };

    Node *first, *last;

    Node* at(size_t);

public:
    LList();
    LList(const LList&);
    ~LList();

    size_t size();

    void push_front(const T&);
	void pop_front();

	void insertAfter(const T&, size_t);
	void deleteAfter(size_t);

	void push_back(const T&);

    void copy(const LList&);
    void clear();

	T& operator [] (const size_t);
	T operator [] (const size_t) const;

    LList& operator=(const LList&);

    void print() const;
};

/*
box* locate(size_t index);

void insertAt(const int& other, size_t index);
void deleteAt(size_t index);

int count(int x);

void operator+=(const int& other);
int get_ith(int n);
void removeAll(int x);
void append(const List& list2);
List concat(const List& other);
void operator+=(const List& other);
List operator+(const List& other);
void reverse();
*/


#endif