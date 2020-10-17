#include<iostream>
#include<exception>

class Vector {
    size_t size;
    size_t capacity;
    int* array;
    public:
    Vector();
    Vector(const Vector&);
    Vector(const std::initializer_list<int>&);
    ~Vector();
    Vector& operator=(const Vector&);
    int& operator[] (const size_t&);
};