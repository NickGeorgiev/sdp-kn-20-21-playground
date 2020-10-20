#ifndef LIST_H
#define LIST_H
#include<iostream>

struct box
{
    int data;
    box* next;

    box():data(0), next(nullptr){}
    box(int& data):data(data), next(nullptr){}
};

class List
{
private:
box* first;

public:
List();
List(const List& other);
List& operator=(const List& other);
~List();

void copy(const List& other);
void clear();

void push(const int& other);
void pop();

void print() const;

box* locate(size_t index);

void insertAt(const int& other, size_t index);
void deleteAt(size_t index);

int count(int x);
void push_back(const int& other);
void operator+=(const int& other);
int get_ith(int n);
void removeAll(int x);
void append(const List& list2);
List concat(const List& other);
void operator+=(const List& other);
List operator+(const List& other);
void reverse();

};

#endif