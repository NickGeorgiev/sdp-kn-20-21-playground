#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <iostream>
class SkipList
{
    struct Node
    {
        int value;
        Node *next;
        Node *skip;
        Node(const int &_value, Node *_next = nullptr, Node *_skip = nullptr) : value{_value}, next{_next}, skip{_skip} {}
    };

   Node *first;

    Node *last;

    void copy(const SkipList&);
    
    void clear();

public:
    SkipList(); 

    SkipList(const SkipList&);
    SkipList& operator=(const SkipList&);

    ~SkipList();

    void addMember(const int &);

    int membersNumber() const;

    SkipList::Node *locateNewElement(const int &) const;

    void deleteSkips();

    void addSkips(const int&);

    void printList()const;

    void printSkips()const; 
};
#endif