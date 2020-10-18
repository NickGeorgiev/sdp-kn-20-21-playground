#include<iostream>
#include<cmath>
#include"SList.h"

template<class T>
void SList<T>::copy(const SList<T>& other) {
    size = other.size;
    
    if(other.first) {

        Node* curr = first = new Node{other.first->data,nullptr,nullptr};
        Node* otherCurr = other.first->next;


        while(otherCurr) {
            curr = curr->next = new Node{otherCurr->data,nullptr,nullptr};
            otherCurr = otherCurr->next;
        }
    }
    else {
        first = nullptr;
    }
    optimize();
}

template<class T>
typename SList<T>::Node* SList<T>::locatePrev(const T& elem) const {

    Node* curr = first;
    Node* prev = nullptr;

    while(curr && curr->skip && curr->skip->data < elem) {
        curr = curr->skip;
    }

    while(curr && curr->data < elem) {
        prev = curr;
        curr = curr->next;
    }
    
    return prev;
}

template<class T>
void SList<T>::optimize() {
    size_t elsToSkip = ceil(size/sqrt(2));

    if(elsToSkip > 1) {
        Node* curr = first;
        Node* prev = first;
        Node* end;
        int i = 0;

        while(curr) {
            if(i % elsToSkip == 0) {
                prev->skip = curr;
                prev = curr;
            }

            ++i;
            end = curr;
            curr = curr->next;
        }
        prev->skip = end;
        end->skip = nullptr;
    }
}

template<class T>
void SList<T>::clear() {
    while(first) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}

template<class T>
SList<T>::SList() : first{nullptr}, size{0} {}

template<class T>
SList<T>::SList(const SList& other){
    copy(other);
}

template<class T>
SList<T>& SList<T>::operator =(const SList& other){
    if(this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

template<class T>
SList<T>::~SList(){
    clear();
}

template<class T>
SList<T>& SList<T>::push(const T& elem) {
    if(!first) {
        first = new Node{elem,nullptr,nullptr};

        optimize();
        ++size;
        return *this;
    }

    Node* prev = locatePrev(elem);
    if(!prev) {
        first = new Node{elem,first,nullptr};

        optimize();
        ++size;
        return *this;
    }

    prev->next = new Node{elem,prev->next,nullptr};

    optimize();
    ++size;
    return *this;
}

template<class T>
SList<T>& SList<T>::removeElement(const T& elem) {
    if(first) {
        Node* prev = locatePrev(elem);
        
        if(!prev) {

            if(first->data == elem) {
                Node* temp = first;
                first = first->next;
                delete temp;  
            }
        }
        else {
            if(prev->next) {
                if(prev->next->data == elem) {
                    Node* current = prev->next;
                    prev->next = current->next;
                    delete current;
                }
            }
        }
        optimize();
    }
    return *this;
}

template<class T>
bool SList<T>::isMember(const T& elem) const {
    if(!first) {
        return false;
    }

    Node* prev = locatePrev(elem);
    if(!prev) {
        return first->data == elem;
    }

    if(prev->next) {
        return prev->next->data == elem;
    }

    return false;
}

template<class T>
bool SList<T>::empty() const {
    return !first;
}

template<class T>
void SList<T>::print() const {
    Node* current = first;

    while (current){
        std::cout << current->data << ' ';
        current = current->next;
    }

    std::cout << std::endl;
}