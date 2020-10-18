#ifndef _SKIPLIST_H
#define _SKIPLIST_H

struct Node {
    int data;
    Node *next;
    Node *skip;

    Node(const int& _data, Node *_next) : data{_data}, next{_next}, skip{nullptr} {}
};

class SkipList {
    private:
    Node *start;
    Node *end;
    int size;

    public:
    SkipList();
    ~SkipList();
    void add(const int& data);
    void optimize();
    Node* locate(const int& data);

    // helpers
    void clearSkips();
    void printSkips();
    friend std::ostream& operator<< (std::ostream& out, const SkipList& list);

};

#endif