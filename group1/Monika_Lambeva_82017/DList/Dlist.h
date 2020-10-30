#ifndef DLIST_H
#define LIST_H
#include<iostream>

struct Box
{
int data;
Box* next;
Box* prev;

Box():data(0), next(nullptr), prev(nullptr){}
Box(const int& data):data(data), next(nullptr), prev(nullptr){}
Box(const int& data, Box* next, Box* prev):data(data), next(next), prev(prev){}
};

class DList
{
private:
Box* first;
Box* last;

void copy(const DList& other);
void clear();

public:
DList();
DList(const DList& other);
DList& operator=(const DList& other);
~DList();

void pop();
void push(const int& other);
void push_back(const int& other);
DList& operator+= (const int &x);
DList operator+ (const int& x) const;
friend std::ostream& operator<<(std::ostream& out, const DList& other);

int count(Box* l, int x) const;
int countFromBegin(const int& x)const;
Box* range(int x, int y);
void append(const DList& other);
DList& concat(const DList& l1, const DList& l2);
void removeAll(const int& x);
static void swap(Box* curr, Box* next, Box* prev);
void reverse();
void removeAllDuplicates();
void removeElement(const int& index);
void mergeWithSorted(const DList& other);
};

#endif
