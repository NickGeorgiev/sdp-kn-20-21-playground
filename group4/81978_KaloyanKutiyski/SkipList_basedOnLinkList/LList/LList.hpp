#pragma once
#include<cstdlib>
#include<functional>

template<class T>
struct Box {
    T data;
    Box<T>* next;
    Box<T>* skip;
    Box() = default;
    Box(const T&);
    Box(const T&, Box<T>*);
};

template<class T>
class LList {
    Box<T> *first, *last;
    size_t size;
 
    void destroy();
    void copy(const LList<T>&);
    bool indexInBounds(const std::size_t)const;
    Box<T>* getBefore(const T&);

    void removeSkips();
    void setSkips();
    void pushBack(const T&);
    void insertAt(const std::size_t, const T&);
    void pushFront(const T&);
    LList<T>& operator+=(const T&);
    void apend(const LList<T>&);
    LList<T> concat(const LList<T>&)const;
    LList<T>& operator+=(const LList<T>&);
    LList<T> operator+(const LList<T>&)const;
    T& operator[](const std::size_t); //throws exceptions
    void reverse();
    void map(const std::function<void(T&)>&);
    void map(const std::function<void(Box<T>&)>&);

    public:
    bool empty();
    LList();
    LList(const LList<T>&);
    LList<T>& operator=(const LList<T>&);
    void pop();
    void deleteAt(const std::size_t);
    void print()const;
    ~LList();
    int count(const T&)const;
    LList(const int&, const int&);

    T getIth(const std::size_t)const; //throws exceptions
    void removeAll(const T&);

    template<class P>
    P reduce(const std::function<void(const T&, P&)>&, const P&);
    template<class P>
    P reduce(const std::function<void(const Box<T>&, P&)>&, const P&);

    class Iterator;

    Iterator begin() {
        return Iterator(first);
    }
    Iterator end() {
        return Iterator(nullptr);
    }

    class Iterator {
        Box<T>* current;
        public:
        Iterator(Box<T>*);
        T& operator*();
        Box<T>& boxForm();
        void operator++();
        bool operator==(const LList<T>::Iterator& other);
        bool operator!=(const LList<T>::Iterator& other);
    };
    

    void add(const T&);
    int find(const T&);
};