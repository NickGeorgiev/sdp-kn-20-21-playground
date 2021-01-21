#ifndef HASHMAP
#define HASHMAP
#include <functional>
#include <exception>
#include<iostream>
template <class Keys, class Values>
class HashMap
{
private:
    struct Box
    {
        Keys key;
        Values val;
        Box *next;
    };
    Box **table;
    size_t size;
    std::function<size_t(const Keys &)> hash;
    Box *locate(size_t, const Keys &) const;
    void clear();
    void pop(size_t);

public:
    class Iterator
    {
    private:
        Box **table;
        size_t size;
        size_t row;
        Box *column;

    public:
        Iterator(Box **, size_t);
        Keys operator*() const;
        Iterator &operator++();
        bool operator!=(const Iterator &) const;
    };

    HashMap(size_t, std::function<size_t(const Keys &)>);
    Values &operator[](const Keys &);
    Values operator[](const Keys &) const;
    bool hasKey(const Keys &) const;
    Iterator begin() const;
    Iterator end() const;
    ~HashMap();
};

#endif