#include "skipList.h"
#include <cmath>

SkipList::Node::Node(const int& _value, Node* _next = nullptr, Node* _skip = nullptr) : value{_value}, next{_next}, skip{_skip} {}

void SkipList::del() {
	while(m_start) {
		Node* curr{m_start};
		m_start = m_start -> next;
		delete curr;
	}
}

void SkipList::optimize() const {
	if(m_length > 1) {
		Node* curr{m_start};
		Node* node_to_optimize{m_start};

		size_t curr_pos{0};
		size_t pos_to_skip_to{(size_t)sqrt(m_length)};
	
		while(curr) {
			if(curr_pos % pos_to_skip_to == 0 || curr == m_end) {
				if(curr == m_end && curr -> skip) {
					curr -> skip = nullptr;
				}

				node_to_optimize -> skip = curr;
				node_to_optimize = curr;
			}

			curr = curr -> next;
			curr_pos++;
		}
	}
}

SkipList::Node* SkipList::locate(const int& _value) const {
	Node* curr{m_start};

    while(curr && curr -> skip && curr -> skip -> value < _value) {
        curr = curr -> skip;
    }

    while(curr && curr -> next && curr -> next -> value < _value) {
        curr = curr -> next;
    }

	return curr;
}

SkipList::SkipList() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

SkipList::SkipList(const std::initializer_list<const int>& _init_list) : SkipList{} {
	for(const int& curr : _init_list) {
		push_back(curr);
	}

	optimize();
}

SkipList::~SkipList() {
	del();
}

void SkipList::push(const int& _new_elem) {
	if(m_start) {
		Node* prev = locate(_new_elem);

		if(prev == m_start && _new_elem < prev -> value) {
			push_front(_new_elem);
		} else if(prev == m_end) {
			push_back(_new_elem);
		} else {
			Node* pt_to_prev{prev};

			m_length++;
			prev = new (std::nothrow) Node{_new_elem, prev -> next};
			pt_to_prev -> next = prev;

			optimize();
		} 
	} else {
		push_back(_new_elem);
	}
}

void SkipList::push_back(const int& _new_elem) {
	Node* pt_to_end{m_end};

	m_length++;
	m_end = new (std::nothrow) Node{_new_elem};

	if(!m_start) {
		m_start = m_end;
	} else {
		pt_to_end -> next = m_end;
	}

	optimize();
}

void SkipList::pop_back() {
	if(m_end) {
		m_length--;

		if(m_end == m_start) {
			delete m_end;
			m_start = nullptr;
			m_end = nullptr;
		} else {
			Node* curr{m_start};

			while(curr -> next != m_end) {
				curr = curr -> next;
			}

			m_end = curr;
			delete m_end -> next;
			m_end -> next = nullptr;

			optimize();
		}
	}
}

void SkipList::push_front(const int& _new_elem) {
	m_length++;
	m_start = new (std::nothrow) Node{_new_elem, m_start};

	if(!m_start -> next) {
        m_end = m_start;
    }

	optimize();
}

void SkipList::pop_front() {
	if(m_start) {
		Node* pt_to_start{m_start};
        m_length--;

        if(m_start == m_end) {
            delete m_start;
			m_start = nullptr;
			m_end = nullptr;
        } else {
			m_start = m_start -> next;
            delete pt_to_start;
			pt_to_start = nullptr;
			
			optimize();
        }
    }
}

const size_t SkipList::length() const {
	return m_length;
}

const SkipList::Node* SkipList::start() const {
	return m_start;
}

const SkipList::Node* SkipList::end() const {
	return m_end;
}

void SkipList::print() const {
	Node* curr{m_start};
	std::cout << "$ ";

	while(curr) {
		std::cout << "[ " << curr -> value << " ]";

		if(curr -> next) {
			std::cout << " -> ";
		}

		curr = curr -> next;
	}

	std::cout << "\n";
}

void SkipList::print_skip() const {
	Node* curr{m_start};
	std::cout << "$ ";

	while(curr) {
		std::cout << "[ " << curr -> value << " ]";

		if(curr -> skip) {
			std::cout << " -> ";
		}

		curr = curr -> skip;
	}

	std::cout << "\n";
}
