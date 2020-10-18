#ifndef S_LIST_H
#define S_LIST_H
#include<iostream>

template<class T>
class SList {

    struct Node {
		T data;
		Node* next = nullptr;
		Node* skip = nullptr;
	};

    Node* first;
	size_t size;

    void copy(const SList& other);

    Node* locatePrev(const T& elem) const;
    void optimize();


    public:
    void clear();

    SList();
    SList(const SList& other);
    SList& operator =(const SList& other);
    ~SList();

    SList& push(const T& elem);
    SList& removeElement(const T& elem);

    bool isMember(const T& elem) const;
    bool empty() const;  

    void print() const;  

};

#endif