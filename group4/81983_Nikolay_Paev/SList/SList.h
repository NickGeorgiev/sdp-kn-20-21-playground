#ifndef S_LIST_H
#define S_LIST_H
#include<iostream>
#include<functional>

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

    void pushElementAt(const T& elem,Node*& place);

    Node* locatePrev(const T& elem, std::function<bool(T,T)> predicate) const;
    void optimize();

    public:
    void clear();

    SList();
    SList(const SList& other);
    SList& operator =(const SList& other);
    ~SList();

    void push(const T& elem);
    void removeElement(const T& elem);

    bool isMember(const T& elem) const;
    bool empty() const; 
    size_t length() const; 

    void print() const;  

};

#endif
