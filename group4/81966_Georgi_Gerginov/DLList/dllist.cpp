#include "dllist.h"

DLList::Node::Node(const int& _value, Node* _next = nullptr, Node* _prev = nullptr) : value{_value}, next{_next}, prev{_prev} {}

void DLList::del() {
    while(m_start -> next) {
        m_start = m_start -> next;
        delete m_start -> prev;
    }

    delete m_start;
    m_length = 0;
}

void DLList::copy(const DLList& other) {
    m_length = 0;
    m_start = m_end = nullptr;

    Node* other_curr{other.m_start};
    while(other_curr) {
        push_back(other_curr -> value);
        other_curr = other_curr -> next;
    }
}

void DLList::move(DLList&& other) {
    m_length = other.m_length;
    m_start = other.m_start;
    m_end = other.m_end;

    other.m_length = 0;
    other.m_start = other.m_end = nullptr;
}

void DLList::swap(DLList& other) {
    std::swap(m_length, other.m_length);
    std::swap(m_start, other.m_start);
    std::swap(m_end, other.m_end);
}

DLList::DLList() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

DLList::DLList(const DLList& other) {
    copy(other);
}

DLList::DLList(DLList&& other) {
    move(std::move(other));
}

DLList::DLList(const std::initializer_list<int>& init_list) : m_length{0}, m_start{nullptr}, m_end{nullptr} {
    for(const int curr : init_list) {
        push_back(curr);
    }
}

DLList::~DLList() {
    del();
}

void DLList::push_front(const int& new_elem) {
    m_length++;
    m_start = new (std::nothrow) Node{new_elem, m_start};

    if(!m_start -> next) {
        m_end = m_start;
    } else {
        m_start -> next -> prev = m_start;
    }
}

void DLList::pop_front() {
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
        std::cout << "error: list is empty $\n";
    }
}

void DLList::push_back(const int& new_elem) {
    m_length++;
    m_end = new (std::nothrow) Node{new_elem, nullptr, m_end};

    if(!m_end -> prev) {
        m_start = m_end;
    } else {
        m_end -> prev -> next = m_end;
    }
}

void DLList::pop_back() {
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
        std::cout << "error: list is empty $\n";
    }
}

DLList& DLList::operator=(const DLList& other) {
    DLList temp{other};
    swap(temp);
    return *this;
}

DLList& DLList::operator=(DLList&& other) {
    DLList temp{std::move(other)};
    swap(temp);
    return *this;
}

DLList DLList::operator+(const int& new_elem) const {
    DLList new_list{*this};
    new_list += new_elem;
    return new_list;
}

DLList& DLList::operator+=(const int& new_elem) {
    push_back(new_elem);
    return *this;
} 

std::ostream& operator<<(std::ostream& out, const DLList& list) {
    out << "[ ";
    
    DLList::Node* curr{list.m_start};
    while(curr) {
        out << curr -> value << ", ";
    }
    
    out << "]\n\n";
    return out;
}