#ifndef UNORDERED_SET_CPP
#define UNORDERED_SET_CPP
#include <iostream>

template <class T>
class UnorderedSet {

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
	void copy(const UnorderedSet<T>&);
	void swap(UnorderedSet<T>&);

	bool is_unique(const T&) const;

public:
	class Iterator {

        Node* curr;
        Node* start;
		Node* end;
    
	public:
        Iterator(Node*, Node*, Node*);

        T& operator*() const;
        Iterator& operator++();
        Iterator& operator--();
        bool operator!=(const Iterator&) const;
        bool operator==(const Iterator&) const;
    };   

    Iterator begin() const;
    Iterator end() const;

public:
	UnorderedSet();
	UnorderedSet(const UnorderedSet<T>&);
	UnorderedSet(const std::initializer_list<const T>&);
	~UnorderedSet();

	void push_back(const T&);
	bool empty() const;
	const size_t length() const;

	UnorderedSet<T>& operator=(const UnorderedSet<T>&);

	template <class U>
	friend std::ostream& operator<<(std::ostream&, const UnorderedSet<U>&);
};

template <class T>
UnorderedSet<T>::Node::Node(const T& _data, Node* _next, Node* _prev) : data{_data}, next{_next}, prev{_prev} {}

template <class T>
void UnorderedSet<T>::del() {
	if(!m_start) {
		return;
	}

	while(m_start -> next) {
		m_start = m_start -> next;
		delete m_start -> prev;
		m_start -> prev = nullptr;
	}

	delete m_start;
	m_start = m_end = nullptr;
	m_length = 0;
}

template <class T>
void UnorderedSet<T>::copy(const UnorderedSet<T>& other) {
	m_length = 0;
	m_start = m_end = nullptr;

	Node* curr{other.m_start};
	while(curr) {
		push_back(curr -> data);
		curr = curr -> next;
	}
}

template <class T>
void UnorderedSet<T>::swap(UnorderedSet<T>& other) {
	std::swap(m_length, other.m_length);
	std::swap(m_start, other.m_start);
	std::swap(m_end, other.m_end);
}

template <class T>
bool UnorderedSet<T>::is_unique(const T& new_data) const {
	Node* curr{m_start};

	while(curr) {
		if(curr -> data == new_data) {
			return false;
		}

		curr = curr -> next;
	}

	return true;
}

template <class T>
UnorderedSet<T>::UnorderedSet() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

template <class T>
UnorderedSet<T>::UnorderedSet(const UnorderedSet<T>& other) {
	copy(other);
}

template <class T>
UnorderedSet<T>::UnorderedSet(const std::initializer_list<const T>& list) : UnorderedSet{} {
	for(const T& curr : list) {
		push_back(curr);
	}
}

template <class T>
UnorderedSet<T>::~UnorderedSet() {
	del();
}

template <class T>
T& UnorderedSet<T>::Iterator::operator*() const {
    if (curr == start -> prev || curr == end -> next) {
    	throw std::out_of_range("Out of range");
    }

    return curr -> data;
}

template <class T>
typename UnorderedSet<T>::Iterator& UnorderedSet<T>::Iterator::operator++() {
    if (curr == start -> prev || curr == end -> next) {
    	throw std::out_of_range("Out of range");
    }

    curr = curr -> next;
    return *this;
}

template <class T>
typename UnorderedSet<T>::Iterator& UnorderedSet<T>::Iterator::operator--() {
    if (curr == start -> prev || curr == end -> next) {
    	throw std::out_of_range("Out of range");
    }

    curr = curr -> prev;
    return *this;
}

template <class T>
bool UnorderedSet<T>::Iterator::operator!=(const Iterator& other) const {
    return curr != other.curr;
}

template <class T>
bool UnorderedSet<T>::Iterator::operator==(const Iterator& other) const {
    return curr != other.curr;
}

template <class T>
UnorderedSet<T>::Iterator::Iterator(Node* _curr, Node* _start, Node* _end) : curr{_curr}, start{_start}, end{_end} {}

template <class T>
typename UnorderedSet<T>::Iterator UnorderedSet<T>::begin() const {
    return UnorderedSet<T>::Iterator(m_start, m_start, m_end);
}

template <class T>
typename UnorderedSet<T>::Iterator UnorderedSet<T>::end() const {
    return UnorderedSet<T>::Iterator(m_end -> next, m_start, m_end);
}

template <class T>
void UnorderedSet<T>::push_back(const T& new_data) {
	if(!is_unique(new_data)) {
		return;
	}

    m_length++;
    m_end = new (std::nothrow) Node{new_data, nullptr, m_end};

    if(!m_end -> prev) {
        m_start = m_end;
    } else {
        m_end -> prev -> next = m_end;
    }
}

template <class T>
bool UnorderedSet<T>::empty() const {
	return m_length == 0;
}

template <class T>
const size_t UnorderedSet<T>::length() const {
	return m_length;
}

template <class T>
UnorderedSet<T>& UnorderedSet<T>::operator=(const UnorderedSet<T>& other) {
	UnorderedSet<T> temp{other};
	swap(temp);
	return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const UnorderedSet<T>& set) {
	typename UnorderedSet<T>::Node* curr{set.m_start};
	out << "$ ";

    while(curr) {
        out << "[" << *curr -> data << "]";

        if(curr -> next) {
            out << " <-> ";
        }

        curr = curr -> next;
    }

    out << "\n";
    return out;
}

#endif
