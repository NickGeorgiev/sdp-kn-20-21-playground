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

SkipList::Node* SkipList::locate(const int& _value) const {
	Node* curr{m_start};

    while(curr && curr -> skip && curr -> skip -> value < _value) {
        curr = curr -> skip;
    }

    while(curr && curr -> value < _value) {
        curr = curr -> next;
    }

	return curr;
}

SkipList::SkipList(const std::initializer_list<const int>& _init_list) : m_length{0}, m_start{nullptr} {
	for(const int& curr : _init_list) {
		push_back(curr);
	}

	optimize();
}

SkipList::~SkipList() {
	del();
}

void SkipList::push(const int& _new_elem) {
	Node* curr{m_start};
	Node* after = locate(_new_elem);

	while(curr -> next && curr -> next != after) {
		curr = curr -> next;
	}

	if(after == m_start) {
		push_front(_new_elem);
	} else if(curr == m_end) {
		push_back(_new_elem);
	} else {
		m_length++;
		after = new (std::nothrow) Node{_new_elem, after};
		curr -> next = after;

		optimize();
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

        if(m_start -> next) {
            m_start = m_start -> next;
            delete pt_to_start;
			
			optimize();
        } else {
            delete m_start;
        }
    }
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