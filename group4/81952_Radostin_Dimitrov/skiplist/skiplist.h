#pragma once
#include <iostream>

struct Element
{

    int data;
    Element *next;
    Element *skip_step;

    Element(const int &_data, Element *_next, Element *_skip_step)
    {
        data = _data;
        next = _next;
        skip_step = _skip_step;
    }
};

class Skip_List
{

    Element *start;
    Element *last;
    int size;

    void copy(const Skip_List &other);
    void destroy();

public:
    Skip_List();
    Skip_List(const Skip_List &other);
    ~Skip_List();
    Skip_List &operator=(const Skip_List &other);
    Element *find_prev_member(const int &_data);

    void optimise_skip_list();
    void add_to_start(const int &_data);
    void insert(const int &_data);
    void print() const;
    void print_skip() const;
};