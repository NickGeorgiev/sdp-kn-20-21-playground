#pragma once
#include"LList.hpp"
#include<iostream>
#include<exception>
#include<cmath>

template<class T>
Box<T>::Box(const T& _data): data{_data}, next{nullptr}, skip{nullptr} {
}

template<class T>
Box<T>::Box(const T& _data, Box<T>* _next): data{_data}, next{_next}, skip{nullptr} {
}

template<class T>
void LList<T>::destroy() {
    while(first) {
        Box<T>* next = first->next;
        delete first;
        first = next;
    }
}

template<class T>
void LList<T>::copy(const LList<T>& other) {
    first = new Box<T>(other.first->data);
    Box<T>* current = first;
    Box<T>* otherCurrent = other.first;
    while (otherCurrent->next) {
        current->next = new Box<T>(otherCurrent->next->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    return;
}

template<class T>
bool LList<T>::indexInBounds(const std::size_t index)const {
    return index >= 0 && size > 0 && index < size;
}

template<class T>
bool LList<T>::empty() {
    return !first;
}

template<class T>
LList<T>::LList(): first{nullptr}, last{nullptr}, size{0} {
}

template<class T>
LList<T>::LList(const LList<T>& other) {
    copy(other);
}

template<class T>
LList<T>& LList<T>::operator=(const LList<T>& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

template<class T>
void LList<T>::pushBack(const T& value) {
    if (!first) {
        first = last = new Box<T>(value);
    }
    else {
        Box<T>* newBox = new Box<T>(value);
        last->next = newBox;
        last = newBox;
    }
    size++;
}

template<class T>
void LList<T>::pop() {
    Box<T>* current = first;
    if (!first) {
        return;
    }
    if (!first->next) {
        delete first;
        first = last = nullptr;
    }
    else {
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        last = current;
    }
    size--;
    setSkips();
}

template<class T>
void LList<T>::insertAt(const std::size_t index, const T& value) {
    unsigned int counter = 1;
    Box<T>* current = first;

    if (!index) {
        pushFront(value);
        return;
    }

    while (current->next) {
        if (counter == index) {
            break;
        }
        current = current->next;
        counter++;
    }

    if (counter != index) {
        return;
    }

    if (!current->next) {
        pushBack(value);
    }
    else {
        Box<T>* newBox = new Box<T>(value, current->next);
        current->next = newBox;
    }
    return;
}

template<class T>
void LList<T>::deleteAt(const std::size_t index) {
    if (!first) {
        return;
    }

    if (!index) {
        Box<T>* toDelete = first;
        first = first->next;
        delete toDelete;
        size--;
        setSkips();
        return;
    }

    unsigned int counter = 1;
    Box<T>* current = first;

    while (current->next) {
        if (counter == index) {
            break;
        }
        counter++;
        current = current->next;
    }

    if (counter != index || !current->next) {
        return;
    }

    if (!current->next->next) {
        delete current->next;
        current->next = nullptr;
        last = current;
    }
    else {
        Box<T>* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;
    }
    size--;
    setSkips();
    return;
}

template<class T>
void LList<T>::print()const {
    Box<T>* current = first;
    while (current) {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << '\n';
}

template<class T>
LList<T>::~LList() {
    destroy();
}

template<class T>
int LList<T>::count(const T& val)const {
    // Box<T>* current = first;
    // unsigned int count = 0;
    // while (current) {
    //     if (current->data == val) {
    //         count++;
    //     }
    //     current = current->next;
    // }
    // return count;
    return size;
}

template<class T>
LList<T>::LList(const int& beg, const int& end) {
    first = nullptr;
    if (beg <= end) {
        for (int i = beg; i <= end; i++) {
            pushBack(i);
        }
    }
}

template<class T>
void LList<T>::pushFront(const T& val) {
    if (!first){
        first = new Box<T>(val);
    }
    else {
        Box<T>* newBox = new Box<T>(val, first);
        first = newBox;
    }
    size++;
}

template<class T>
LList<T>& LList<T>::operator+=(const T& val) {
    pushBack(val);
    return *this;
}

template<class T>
T LList<T>::getIth(const std::size_t index)const {
    if (!indexInBounds(index)) {
        throw -1;
    }

    unsigned int count = 0;
    Box<T>* current = first;
    while(current->next) {
        if (count == index) {
            break;
        }
        count++;
        current = current->next;
    }
    return current->data;
}

template<class T>
void LList<T>::removeAll(const T& val) {
    Box<T>* current = first;
    Box<T>* prev = nullptr;
    while (current) {
        if (current->data == val) {
            if (current == first) {
                deleteAt(0);
                current = first;
                continue;
            }
            if (!current->next) {
                pop();
                return;
            }

            Box<T>* toDelete = current;
            prev->next = current->next;
            current = current->next;
            delete toDelete;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    setSkips();
    return;
}

template<class T>
void LList<T>::apend(const LList<T>& other) {
    Box<T>* current = other.first;
    while (current) {
        pushBack(current->data);
        current = current->next;
    }
    return;
}

template<class T>
LList<T> LList<T>::concat(const LList<T>& other)const {
    LList<T> result(*this);
    result.apend(other);
    return result;
}

template<class T>
LList<T>& LList<T>::operator+=(const LList<T>& other) {
    return apend(other);
}

template<class T>
LList<T> LList<T>::operator+(const LList<T>& other)const {
    return concat(other);
}

template<class T>
T& LList<T>::operator[](const std::size_t index){
    if (!indexInBounds(index)) {
        throw -1;
    }
    Box<T>* current = first;
    unsigned int count = 0;
    while(current->next) {
        if (count == index) {
            break;
        }
        count++;
        current = current->next;
    }
    return current->data;
}

template<class T>
void LList<T>::reverse() {
    if (!first || !first->next) {
        return;
    }
    Box<T> *curr = first, *prev = nullptr, *_next = nullptr;
    while (curr) {
        _next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = _next;
    }
    first = prev;
    return;
}

template<class T>
void LList<T>::map(const std::function<void(T&)>& func) {
    for (LList<T>::Iterator it(first); it != end(); ++it) {
        func(*it);
    }
    return;
}
template<class T>
void LList<T>::map(const std::function<void(Box<T>&)>& func) {
    Box<T>* curr = first;
    while (curr) {
        func(curr);
        curr->next;
    }
}


template<class T>
template<class P>
P LList<T>::reduce(const std::function<void(const T& element, P& aggregate)>& func, const P& nullVal) {
    P result = nullVal;
    for(LList<T>::Iterator it(first); it!= end(); ++it) {
        func(*(it), result);
    }
    return result;
}
template<class T>
template<class P>
P LList<T>::reduce(const std::function<void(const Box<T>& element, P& aggregate)>& func, const P& nullVal) {
    P result = nullVal;
    Box<T>* curr = first;
    while (curr) {
        func(curr, result);
        curr = curr->next;
    }
    return result;
}

template<class T>
LList<T>::Iterator::Iterator(Box<T>* pointer) {
    current = pointer;
}

template<class T>
T& LList<T>::Iterator::operator*() {
    return current->data;
}

template<class T>
Box<T>& LList<T>::Iterator::boxForm() {
    return *current;
}

template<class T>
void LList<T>::Iterator::operator++() {
    current = current->next;
}

template<class T>
bool LList<T>::Iterator::operator==(const LList<T>::Iterator& other) {
    return current = other.current;
}

template<class T>
bool LList<T>::Iterator::operator!=(const LList<T>::Iterator& other) {
    return current != other.current;
}

template<class T>
void LList<T>::removeSkips() {
    Box<T>* curr = first;
    while (curr) {
        curr->skip = nullptr;
        curr = curr->next;
    }
}

template<class T>
void LList<T>::setSkips() {
    removeSkips();
    if (empty()) {
        return;
    }
    if (size < 4) {
        Box<T>* curr = first;
        while (curr) {
            curr->skip = curr->next;
            curr = curr->skip;
        }
        return;
    }

    int squareRoot = (int)std::sqrt(size);
    Box<T> *prev = first, *curr = first;
    int counter = 0;
    while (curr) {
        if (curr == last) {
            prev->skip = last;
            break;
        }
        if (counter == squareRoot) {
            prev->skip = curr;
            prev = curr;
            counter = 0;
        }
        else {
            counter++;
            curr = curr->next;
        }
    }
}

template<class T>
void LList<T>::add(const T& value) {
    if (!first) {
        first = last = new Box<T>(value);
        size = 1;
        return;
    }

    if (value <= first->data) {
        pushFront(value);
    }
    else if (value >= last->data) {
        pushBack(value);
    }
    else {
        Box<T> *prev = first, *curr = last;
        while (value >= curr->data) {
            prev = curr;
            curr = curr->skip;
        }
        if (curr->data == value) {
            Box<T>* newNode = new Box<T>(value);
            newNode->next = curr->next;
            curr->next = newNode;
        }
        else {
            curr = prev->next;
            while (curr->data <= value) {
                prev = curr;
                curr = curr->next;
            }
            Box<T>* newNode = new Box<T>(value);
            newNode->next = curr;
            prev->next = newNode;
        }
        size++;
    }
    setSkips();
}

template<class T>
int LList<T>::find(const T& value) {
    if (empty()) {
        return - 1;
    } 
    int skipSize = (int)std::sqrt(size);
    int result = 0;

    if (last->data < value || value < first->data) {
        return -1;
    }

    Box<T> *prev = first, *curr = first;

    while (value < curr->data) {
        prev = curr;
        curr = curr->skip;
        result += skipSize;
    }
    if (value == curr->data) {
        return result;
    }
    curr = prev->next;
    result++;
    while (curr->data < value) {
        curr = curr->next;
        result++;        
    }
    if (curr->data == value) {
        return result;
    }
    return -1;
}