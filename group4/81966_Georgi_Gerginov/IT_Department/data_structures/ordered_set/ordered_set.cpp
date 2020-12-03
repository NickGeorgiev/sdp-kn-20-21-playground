#ifndef ORDERED_SET_CPP
#define ORDERED_SET_CPP
#include <iostream>

template <class T>
class OrderedSet {

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
	void copy(const OrderedSet<T>&);
	void swap(OrderedSet<T>&);

	bool is_unique(const T&) const;

	void push_front(const T&);
	void push_back(const T&);

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
	OrderedSet();
	OrderedSet(const OrderedSet<T>&);
	OrderedSet(const std::initializer_list<const T>&);
	~OrderedSet();

	void push(const T&);
	bool empty() const;
	const size_t length() const;

	OrderedSet<T>& operator=(const OrderedSet<T>&);

	template <class U>
	friend std::ostream& operator<<(std::ostream&, const OrderedSet<U>&);
};

template <class T>
OrderedSet<T>::Node::Node(const T& _data, Node* _next, Node* _prev) : data{_data}, next{_next}, prev{_prev} {}

template <class T>
void OrderedSet<T>::del() {
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
void OrderedSet<T>::copy(const OrderedSet<T>& other) {
	m_length = 0;
	m_start = m_end = nullptr;

	Node* curr{other.m_start};
	while(curr) {
		push_back(curr -> data);
		curr = curr -> next;
	}
}

template <class T>
void OrderedSet<T>::swap(OrderedSet<T>& other) {
	std::swap(m_length, other.m_length);
	std::swap(m_start, other.m_start);
	std::swap(m_end, other.m_end);
}

template <class T>
bool OrderedSet<T>::is_unique(const T& new_data) const {
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
void OrderedSet<T>::push_front(const T& new_data) {
	if(!is_unique(new_data)) {
		return;
	}

    m_length++;
    m_start = new (std::nothrow) Node{new_data, m_start};

    if(!m_start -> next) {
        m_end = m_start;
    } else {
        m_start -> next -> prev = m_start;
    }
}

template <class T>
void OrderedSet<T>::push_back(const T& new_data) {
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
OrderedSet<T>::OrderedSet() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

template <class T>
OrderedSet<T>::OrderedSet(const OrderedSet<T>& other) {
	copy(other);
}

template <class T>
OrderedSet<T>::OrderedSet(const std::initializer_list<const T>& list) : OrderedSet{} {
	for(const T& curr : list) {
		push(curr);
	}
}

template <class T>
OrderedSet<T>::~OrderedSet() {
	del();
}

template <class T>
T& OrderedSet<T>::Iterator::operator*() const {
    if (curr == start -> prev || curr == end -> next) {
    	throw std::out_of_range("Out of range");
    }

    return curr -> data;
}

template <class T>
typename OrderedSet<T>::Iterator& OrderedSet<T>::Iterator::operator++() {
    if (curr == start -> prev || curr == end -> next) {
    	throw std::out_of_range("Out of range");
    }

    curr = curr -> next;
    return *this;
}

template <class T>
typename OrderedSet<T>::Iterator& OrderedSet<T>::Iterator::operator--() {
    if (curr == start -> prev || curr == end -> next) {
    	throw std::out_of_range("Out of range");
    }

    curr = curr -> prev;
    return *this;
}

template <class T>
bool OrderedSet<T>::Iterator::operator!=(const Iterator& other) const {
    return curr != other.curr;
}

template <class T>
bool OrderedSet<T>::Iterator::operator==(const Iterator& other) const {
    return curr != other.curr;
}

template <class T>
OrderedSet<T>::Iterator::Iterator(Node* _curr, Node* _start, Node* _end) : curr{_curr}, start{_start}, end{_end} {}

template <class T>
typename OrderedSet<T>::Iterator OrderedSet<T>::begin() const {
    return OrderedSet<T>::Iterator(m_start, m_start, m_end);
}

template <class T>
typename OrderedSet<T>::Iterator OrderedSet<T>::end() const {
    return OrderedSet<T>::Iterator(m_end -> next, m_start, m_end);
}

template <class T>
void OrderedSet<T>::push(const T& new_data) {
	if(!m_start) {
		push_back(new_data);
		return;
	}

	Node* curr{m_start};

    while(curr && curr -> next && curr -> data <= new_data) {
        curr = curr -> next;
    }

	if(curr == m_start && new_data < curr -> data) {
		push_front(new_data);
	} else if(curr == m_end && new_data > curr -> data) {
		push_back(new_data);
	} else {
		curr = new (std::nothrow) Node{new_data, curr, curr -> prev};
		curr -> next -> prev = curr;
		curr -> prev -> next = curr;
		m_length++;
	} 
}

template <class T>
bool OrderedSet<T>::empty() const {
	return m_length == 0;
}

template <class T>
const size_t OrderedSet<T>::length() const {
	return m_length;
}

template <class T>
OrderedSet<T>& OrderedSet<T>::operator=(const OrderedSet<T>& other) {
	OrderedSet<T> temp{other};
	swap(temp);
	return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const OrderedSet<T>& set) {
	typename OrderedSet<T>::Node* curr{set.m_start};
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
