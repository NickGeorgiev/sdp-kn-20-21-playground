#include <iostream>
#include <cmath>
#include "Skiplist.h"

void Skiplist::copy(const Skiplist& other){
    if(this != &other){
        Skiplist::Skipnode *curr = other.head;
        this->head = nullptr;
        this->tail = nullptr;
        
        this->clear();

        while(curr){
            this->push(curr->data);
            curr = curr->next;
        }
        this->placeTail();
    }
}

void Skiplist::clear(){
    Skiplist::Skipnode *curr = this->head; 
    Skiplist::Skipnode *save;
    
    while(curr){
        save = curr;
        curr = curr->next;
        delete save;
    }

    this->head = nullptr;
    this->tail = nullptr;
    // std::cout << "here" << std::endl;
}

void Skiplist::optimize(){
    Skiplist::Skipnode *save = this->head;
    size_t count = 0;

    while(save){
        count++;
        save = save->next;
    }    

    save = this->head;

    while(save){
        // save->skip = save + sqrt(count);
        
        if(save->skip = nullptr){
            save->skip = this->tail;
        }

        save = save->skip;
    }
}

void Skiplist::print(){
    Skiplist::Skipnode *curr = this->head;

    while(curr){
        std::cout << curr->data << " ";
        curr = curr->next;
    }
}

Skiplist::Skiplist(): head(nullptr), tail(nullptr) {}

Skiplist::Skiplist(const Skiplist& other){
    this->copy(other);
}

Skiplist::~Skiplist(){
    this->clear();
}

Skiplist& Skiplist::operator= (const Skiplist& other){
    if (this != &other){
        this->clear();
        this->copy(other);
    }

    return *this;
}

Skiplist& Skiplist::operator+= (const int& _data){
    this->head = new Skiplist::Skipnode {_data, head, nullptr, nullptr};

    if(head->next != nullptr){
        head->next->prev = head;
    }

    return *this;
}

void Skiplist::push(const int& _data) {
    // this->operator+=(_data);
    // this->placeTail();
    // this->tail = new Skiplist::Skipnode {_data, nullptr, tail, nullptr};

    // if(tail->prev != nullptr){
    //     tail->prev->next = tail;
    // }
    if(this->head == nullptr){
        this->head = new Skiplist::Skipnode {_data, nullptr, nullptr, nullptr};
        this->tail = this->head;
        
        return;
    } else {
        if(_data < this->head->data){
            this->head = new Skiplist::Skipnode {_data, this->head, nullptr, nullptr};
            if(this->head->next){
                this->head->next->prev = this->head;

                return;
            }
        }

        this->placeTail();

        if(_data > this->tail->data){
            this->tail = new Skiplist::Skipnode {_data, nullptr, this->tail, nullptr};
            if(this->tail->prev){
                this->tail->prev->next = this->tail;

                return;
            }
        }

        Skiplist::Skipnode *curr = this->head;

        while(curr){
            if(curr->data >= _data){
                Skiplist::Skipnode *save = new Skiplist::Skipnode {_data, curr, curr->prev, nullptr};
                save->prev->next = save;
                curr->prev = save;

                return;
            }

            curr = curr->next;
        }
    } 
}

bool Skiplist::member(const int& _data) {
    Skiplist::Skipnode *save = this->head;
    
    while(save != nullptr){
        if(save->data == _data) {
            return true;
        }

        // save = save->skip;
        save = save->next;
    }

    return false;
}

typename Skiplist::Skipnode* Skiplist::locate(const int& _data) {
    if(this->member(_data)){
        Skiplist::Skipnode *save = this->head;
        while(save != nullptr){
            if(save->data == _data){
                return save;
            }

            // save = save->skip;
            save = save->next;
        }
    }

    return nullptr;
}

void Skiplist::placeTail(){
    Skiplist::Skipnode *save = this->head;

    while(save){
        this->tail = save;
        save = save->next;
    }
}

void Skiplist::reverse(){
    Skiplist temp;
    Skiplist::Skipnode *curr = this->head;

    while(curr){
        temp += curr->data;
        curr = curr->next;
    }

    curr = this->head;
    Skiplist::Skipnode  *helper = temp.head;
    while(curr){
        curr->data = helper->data;
        curr = curr->next;
        helper = helper->next;
    }    
}

// typename Skiplist::Skipnode* Skiplist::getHead(){
//     return this->head;
// }
