#ifndef QUEUE_CPP
#define QUEUE_CPP
#include <stack>
#include <iostream>

template <class T>
class Queue {
 
	std::stack<T> m_forward;
	std::stack<T> m_reverse;

	const std::stack<T>* reverse(const std::stack<T>&) const;
	void update_stack(const std::stack<T>*, std::stack<T>&);

public:
	Queue() = default;
	Queue(const std::initializer_list<const T>&);
	~Queue() = default;

	const T& front() const;
	const T& tail() const;
	void push(const T&);
	void pop();

	template <class U>
	friend std::ostream& operator<<(std::ostream&, const Queue<U>&);
};

template <class T>
const std::stack<T>* Queue<T>::reverse(const std::stack<T>& _from) const {
	std::stack<T>* reverse{new std::stack<T>};
	std::stack<T> _from_copy{_from};

	while(!_from_copy.empty()) {
		reverse -> push(_from_copy.top());
		_from_copy.pop();
	}

	return reverse;
}

template <class T>
void Queue<T>::update_stack(const std::stack<T>* _from, std::stack<T>& _to) {
	_to = *_from;
	delete _from;
}

template <class T>
Queue<T>::Queue(const std::initializer_list<const T>& init_list) : Queue{} {
	for(const T& curr : init_list) {
		m_forward.push(curr);
	}
	update_stack(reverse(m_forward), m_reverse);
}

template <class T>
const T& Queue<T>::front() const {
	return m_reverse.top();
}

template <class T>
const T& Queue<T>::tail() const {
	return m_forward.top();
}

template <class T>
void Queue<T>::push(const T& new_element) {
	m_forward.push(new_element);
	update_stack(reverse(m_forward), m_reverse);
}

template <class T>
void Queue<T>::pop() {
	m_reverse.pop();
	update_stack(reverse(m_reverse), m_forward);
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& _queue) {
	std::stack<T> reverse_copy{_queue.m_reverse};
	out << "$ ";

	while(!reverse_copy.empty()) {
		out << "[" << reverse_copy.top() << "]";

		if(reverse_copy.size() != 1) {
			out << " <-> ";
		}

		reverse_copy.pop();
	}

    out << "\n";
    return out;
}

#endif
