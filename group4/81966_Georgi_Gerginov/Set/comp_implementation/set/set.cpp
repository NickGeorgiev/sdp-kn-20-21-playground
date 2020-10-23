#include "set.h"

Set::Node::Node(Comparable* _data, Node* _next = nullptr, Node* _prev = nullptr) : data{_data}, next{_next}, prev{_prev} {}

void Set::del() {
    while(m_start -> next) {
        m_start = m_start -> next;
        delete m_start -> prev;
    }

    delete m_start;
}

void Set::push_front(Comparable* new_data) {
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

void Set::push_back(Comparable* new_data) {
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

bool Set::is_unique(Comparable* _data) const {
    Node* curr{m_start};

    while(curr) {
        if(curr -> data -> compareTo(_data) == 0) { 
            return false;
        }
        curr = curr -> next;
    }

    return true;
}

Set::Set() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

Set::Set(const std::initializer_list<Comparable*>& init_list) : Set{} {
	for(Comparable* curr : init_list) {
		push(curr);
	}
}

Set::~Set() {
    del();
}

void Set::pop_front() {
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

void Set::pop_back() {
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

void Set::push(Comparable* new_data) {
    Node* curr{m_start};
    while(curr && curr -> data -> compareTo(new_data) == -1) {
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

std::ostream& operator<<(std::ostream& out, const Set& _set) {
    Set::Node* curr{_set.m_start};
	out << "$ ";

    while(curr) {
        out << "[" << curr -> data -> get_data() << "]";

        if(curr -> next) {
            out << " <-> ";
        }

        curr = curr -> next;
    }

    out << "\n";
    return out;
}
