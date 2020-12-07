#include<iostream>
#include<functional>
#include<cmath>
#include"SList.h"

template<class T>
void SList<T>::copy(const SList<T>& other) {
    size = other.size;
    
    if(other.first) {
        Node* curr = first = new Node{other.first->data,nullptr,nullptr};
        Node* otherCurr = other.first;


        while(otherCurr->next) {
            curr = curr->next = new Node{otherCurr->next->data,nullptr,nullptr};
            otherCurr = otherCurr->next;
        }

        optimize();
    }
    else {
        first = nullptr;
    }
}

template<class T>
void SList<T>::pushElementAt(const T& elem,Node*& place) {
    place = new Node{elem,place,nullptr};

    optimize();
    ++size;
}

template<class T>
typename SList<T>::Node* SList<T>::locatePrev(const T& elem,std::function<bool(T,T)> predicate) const {
    Node* curr = first;
    Node* prev = nullptr;

    while(curr && curr->skip && predicate(curr->skip->data,elem)) {
        curr = curr->skip;
    }

    while(curr && predicate(curr->data,elem)) {
        prev = curr;
        curr = curr->next;
    }
    
    return prev;
}

template<class T>
void SList<T>::optimize() {
    size_t elementsToSkip = size/sqrt(2);

    if(elementsToSkip > 1) {
        Node* curr = first;
        Node* prev = first;
        Node* end;
        int i = 0;

        while(curr) {
            if(i % elementsToSkip == 0) {
                prev->skip = curr;
                prev = curr;
            }
            else {
                prev->skip = nullptr;
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
    size = 0;
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
void SList<T>::push(const T& elem) {

    Node* prev = locatePrev(elem, [](T first,T second)->bool{
        return first <= second;});

    if(!prev) {
        pushElementAt(elem,first);
    }
    else {
        pushElementAt(elem,prev->next);
    }
}

template<class T>
void SList<T>::removeElement(const T& elem) {
    if(first) {
        Node* prev = locatePrev(elem, [](T first,T second)->bool{
            return first < second;});
        
        if(!prev) {

            if(first->data == elem) {
                Node* temp = first;
                first = first->next;
                delete temp;

                --size;
            }
        }
        else {
            if(prev->next) {
                if(prev->next->data == elem) {
                    Node* current = prev->next;
                    prev->next = current->next;
                    delete current;
                    --size;
                }
            }
        }
        optimize();
    }
}

template<class T>
bool SList<T>::isMember(const T& elem) const {
    Node* prev = locatePrev(elem, [](T first,T second)->bool{
        return first <= second;});

    if(!prev) {
        return false;
    }

    return prev->data == elem;
}

template<class T>
bool SList<T>::empty() const {
    return !first;
}

template<class T>
size_t SList<T>::length() const {
    return size;
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
