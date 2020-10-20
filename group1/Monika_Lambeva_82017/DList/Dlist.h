#ifndef DLIST_H
#define LIST_H
#include<iostream>

struct box
{
int data;
box* next;
box* prev;

box():data(0), next(nullptr), prev(nullptr){}
box(const int& data):data(data), next(nullptr), prev(nullptr){}
};

class DList
{
private:
//struct box
//{
//int data;
//box* next;
//box* prev;
//
//box():data(0), next(nullptr), prev(nullptr){}
//box(const int& data):data(data), next(nullptr), prev(nullptr){}
//};
box* first;

void copy(const DList& other);
void clear();

public:
DList();
DList(const DList& other);
DList& operator=(const DList& other);
~DList();

//box* getFirst()const;

void pop();
void push(const int& other);
void push_back(const int& other);
DList& operator+= (const int &x);
DList operator+ (const int& x) const;
friend std::ostream& operator<<(std::ostream& out, const DList& other);

int count(box* l, int x);
int countFromBegin(const int& x);
box* range(int x, int y);
void append(const DList& other);
DList& concat(const DList& l1, const DList& l2);
void removeAll(const int& x);
void reverse();
void removeAllDuplicates();
void removeElement(const int& index);
void mergeWithSorted(const DList& other);
};












#endif