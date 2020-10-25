#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <iostream>
class SkipList
{
private:
    struct Node
    {
        int data;
        Node *next, *skip;

        Node(const int &data_, Node *next_, Node *skip_) : data(data_), next(next_), skip(skip_) {}
    };

    Node *first;
    int size;

    void delete_helper();
    void copy_helper(const SkipList &);

public:
    SkipList();
    SkipList(const SkipList &);
    ~SkipList();

    SkipList &operator=(const SkipList &);

    void add_element(const int &);
    Node *position(const int &) const;
    bool member(const int &) const;
    void print() const;

    size_t get_size() const;

    void optimise();
    void skip_print() const;
};

#endif
