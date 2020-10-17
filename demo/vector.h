#include<iostream>
#include<exception>

class Vector {
    size_t size;
    size_t capacity;
    int* array;
    public:
    Vector(): size{4}, capacity{4}, array{new int[capacity]} {}
    Vector(const Vector& other): size{other.size}, capacity{other.capacity}, array{new int[capacity]} {
        for(int i=0;i< size; i++) {
            array[i] = other.array[i];
        }
    }
    Vector(const std::initializer_list<int> list): size{0}, capacity{list.size()*2}, array{new int[capacity]} {
        for(int element : list) {
            array[size++] = element;
        }
    }
    ~Vector() {
        delete [] array;
    }
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete [] array;
            size = other.size;
            capacity = other.capacity;
            array = new int [capacity];
            for(int i=0;i< size; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }
    int& operator[] (size_t index) {
        if(!array || index >= size) {
            throw std::out_of_range("No such element!");
        }
        return array[index];
    }
};