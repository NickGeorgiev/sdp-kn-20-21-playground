#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <iostream>
class skipList
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

    void find_size();
    void delete_helper();
    void copy_helper(const skipList &);

public:
    skipList();
    skipList(const skipList &);
    ~skipList();

    skipList &operator=(const skipList &);

    void add_element(const int &);
    int position(const int &) const;
    void print() const;

    void optimise();
    void skip_print() const;
};

#endif
