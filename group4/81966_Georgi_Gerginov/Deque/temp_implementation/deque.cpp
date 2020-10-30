#ifndef DEQUE_CPP
#define DEQUE_CPP
#include <iostream>

template <class T>
class Deque {

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

public:
	Deque();
	Deque(const std::initializer_list<const T>&);
	~Deque();

	void push_front(const T&);
	void pop_front();
	void push_back(const T&);
	void pop_back();
	void push_emergency(const T&);

	template <class U>
	friend std::ostream& operator<<(std::ostream&, const Deque<U>&);
};

template <class T>
Deque<T>::Node::Node(const T& _data, Node* _next, Node* _prev) : data{_data}, next{_next}, prev{_prev} {}

template <class T>
void Deque<T>::del() {
	if(m_start) {
		while(m_start -> next) {
			m_start = m_start -> next;
			delete m_start -> prev;
			m_start -> prev = nullptr;
		}
	
		delete m_start;
		m_start = m_end = nullptr;
		m_length = 0;
	}
}

template <class T>
Deque<T>::Deque() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

template <class T>
Deque<T>::Deque(const std::initializer_list<const T>& init_list) : Deque{} {
	for(const T& curr : init_list) {
		push_back(curr);
	}
}

template <class T>
Deque<T>::~Deque() {
	del();
}

template <class T>
void Deque<T>::push_front(const T& new_data) {
	m_start = new (std::nothrow) Node{new_data, m_start};
	m_length++;

	if(!m_start -> next) {
		m_end = m_start;
	} else {
		m_start -> next -> prev = m_start;
	}
}

template <class T>
void Deque<T>::pop_front() {
	if(m_start) {
		if(m_start != m_end) {
			m_start = m_start -> next;
			delete m_start -> prev;
			m_start -> prev = nullptr;
		} else {
			delete m_start;
			m_start = m_end = nullptr;
		}

		m_length--;
	}
}

template <class T>
void Deque<T>::push_back(const T& new_data) {
	m_end = new (std::nothrow) Node{new_data, nullptr, m_end};
	m_length++;

	if(!m_end -> prev) {
		m_start = m_end;
	} else {
		m_end -> prev -> next = m_end;
	}
}

template <class T>
void Deque<T>::pop_back() {
	if(m_end) {
		if(m_start != m_end) {
			m_end = m_end -> prev;
			delete m_end -> next;
			m_end -> next = nullptr;
		} else {
			delete m_end;
			m_start = m_end = nullptr;
		}

		m_length--;
	}
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Deque<T>& _deque) {
	typename Deque<T>::Node* curr{_deque.m_start};
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
