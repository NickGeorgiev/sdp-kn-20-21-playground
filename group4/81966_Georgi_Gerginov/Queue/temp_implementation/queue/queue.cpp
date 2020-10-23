#ifndef QUEUE_CPP
#define QUEUE_CPP
#include <iostream>
#include <memory>

template <class T>
class Queue {

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
	Queue();
	Queue(const std::initializer_list<const T>&);
	~Queue();

	void push(const T&);
	void pop();

	const size_t get_length() const;
	const T& first_data() const;
	bool empty() const;

	template <class U>
	friend std::ostream& operator<<(std::ostream&, const Queue<U>&);
};

template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

//<------------------------------------------------------------------------------>

template <class T>
Queue<T>::Node::Node(const T& _data, Node* _next, Node* _prev) : data{_data}, next{_next}, prev{_prev} {}

template <class T>
void Queue<T>::del() {
	while(m_start -> next) {
		m_start = m_start -> next;
		delete m_start -> prev;
	}

	delete m_start;
}

template <class T>
Queue<T>::Queue() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

template <class T>
Queue<T>::Queue(const std::initializer_list<const T>& init_list) : Queue{} {
	for(const T& curr : init_list) {
		push(curr);
	}
}

template <class T>
Queue<T>::~Queue() {
	del();
}

template <class T>
void Queue<T>::push(const T& new_data) {
	m_length++;
	m_end = new (std::nothrow) Node{new_data, nullptr, m_end};

	if(!m_end -> prev) {
        m_start = m_end;
    } else {
        m_end -> prev -> next = m_end;
    }
}

template <class T>
void Queue<T>::pop() {
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
		std::cout << "$ error: queue is empty";
	}
}

template <class T>
const size_t Queue<T>::get_length() const {
	return m_length;
}

template <class T>
bool Queue<T>::empty() const {
	return m_length == 0;
}

template <class T>
const T& Queue<T>::first_data() const {
	return m_start -> data;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& queue) {
	typename Queue<T>::Node* curr{queue.m_start};
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
