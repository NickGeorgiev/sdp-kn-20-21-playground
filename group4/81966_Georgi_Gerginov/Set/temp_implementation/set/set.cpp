#ifndef SET_CPP
#define SET_CPP
#include <iostream>

template <class T>
class Set {

    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T&, Node* = nullptr, Node* = nullptr);
    };

    size_t m_length;
    Node* m_start;
    Node* m_end;

    void del();
    bool is_unique(const T&) const;

public:
    Set();
	Set(const std::initializer_list<const T>&);
    ~Set();

    void push_front(const T&);
    void pop_front();
    void push_back(const T&);
    void pop_back();
    void push(const T&);

	template <class U>
    friend std::ostream& operator<<(std::ostream&, const Set<U>&);
};

template <class T>
std::ostream& operator<<(std::ostream&, const Set<T>&);

template <class T>
Set<T>::Node::Node(const T& _data, Node* _next, Node* _prev) : data{_data}, next{_next}, prev{_prev} {}

template <class T>
void Set<T>::del() {
    while(m_start -> next) {
        m_start = m_start -> next;
        delete m_start -> prev;
    }

    delete m_start;
}

template <class T>
bool Set<T>::is_unique(const T& _data) const {
    Node* curr{m_start};

    while(curr) {
        if(curr -> data == _data) { 
            return false;
        }
        curr = curr -> next;
    }

    return true;
}

template <class T>
Set<T>::Set() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

template <class T>
Set<T>::Set(const std::initializer_list<const T>& init_list) : Set{} {
	for(const T& curr : init_list) {
		push(curr);
	}
}

template <class T>
Set<T>::~Set() {
    del();
}

template <class T>
void Set<T>::push_front(const T& new_data) {
    if(is_unique(new_data)) {

        m_length++;
        m_start = new (std::nothrow) Node{new_data, m_start};

        if(!m_start -> next) {
            m_end = m_start;
        } else {
            m_start -> next -> prev = m_start;
        }

    } else {
        std::cout << "$ error: element is not unique\n";
    }
}

template <class T>
void Set<T>::pop_front() {
    if(m_start) {

        m_length--;

        if(m_start -> next) {
            m_start = m_start -> next;
            delete m_start -> prev;
            m_start -> prev = nullptr;
        } else {
            delete m_start;
        }
        
    } else {
        std::cout << "$ error: list is empty\n";
    }
}

template <class T>
void Set<T>::push_back(const T& new_data) {
    if(is_unique(new_data)) {

        m_length++;
        m_end = new (std::nothrow) Node{new_data, nullptr, m_end};

        if(!m_end -> prev) {
            m_start = m_end;
        } else {
            m_end -> prev -> next = m_end;
        }

    } else {
        std::cout << "$ error: element is not unique\n";
    }
}

template <class T>
void Set<T>::pop_back() {
    if(m_end) {
		
        m_length--;

        if(m_end -> prev) {
            m_end = m_end -> prev;
            delete m_end -> next;
            m_end -> next = nullptr;
        } else {
            delete m_end;
        }
        
    } else {
        std::cout << "$ error: list is empty\n";
    }
}

template <class T>
void Set<T>::push(const T& new_data) {
    Node* curr{m_start};
    while(curr && curr -> data < new_data) {
        curr = curr -> next;
    }

    if(curr == m_start) {
        push_front(new_data);
    } else if(curr == m_end -> next) {
        push_back(new_data);
    } else {
        if(is_unique(new_data)) {

            m_length++;
            curr -> prev = new (std::nothrow) Node{new_data, curr, curr -> prev};
            curr -> prev -> prev -> next = curr -> prev;

        } else {
            std::cout << "$ error: element is not unique\n";
        }
    }
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Set<T>& _set) {
	typename Set<T>::Node* curr{_set.m_start};
	out << "$ ";

    while(curr) {
        out << "[" << curr -> data << "]";

        if(curr -> next) {
            out << " <-> ";
        }

        curr = curr -> next;
    }

    out << "\n";
    return out;
}

#endif