#ifndef __SKIPLIST_H
#define __SKIPLIST_H

class SkipList {

    struct Node {
        int data;
        Node *next;
        Node *forward;
        Node (const int &_data, Node *_next, Node *_forward) : data{_data}, next{_next}, forward{_forward} {}
    };

    Node* start;
    Node* last;
    int size;

    //void copy (const SkipList&);
    void destroy ();

    public:
    SkipList() : start{nullptr}, last{nullptr}, size{0} {}
    //SkipList (const SkipList&);
    ~SkipList ();

    Node* isMember (const int& _data);

    void optimise ();

    void addToEnd (const int& _data);
    void addToStart (const int& _data);
    void insertAt (const int& _data, Node* _prevNode);

    void print () const;
};

#endif