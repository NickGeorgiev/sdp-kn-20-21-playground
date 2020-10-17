#include "vector.h"

Vector::Vector(): size{4}, capacity{4}, array{new int[capacity]} {}

Vector::Vector(const Vector& other): size{other.size}, capacity{other.capacity}, array{new int[capacity]} {
    for(int i=0;i< size; i++) {
        array[i] = other.array[i];
    }
}

Vector::Vector(const std::initializer_list<int>& list): size{0}, capacity{list.size()*2}, array{new int[capacity]} {
    for(int element : list) {
        array[size++] = element;
    }
}

Vector::~Vector() {
    delete [] array;
}

Vector& Vector::operator=(const Vector& other) {
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

int& Vector::operator[] (const size_t& index) {
    if(!array || index >= size) {
        throw std::out_of_range("No such element!");
    }
    return array[index];
}
