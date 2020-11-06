#include "deque.h"

Deque::Node::Node(const Patient& _patient, Node* _next = nullptr, Node* _prev = nullptr) : patient{_patient}, next{_next}, prev{_prev} {}

void Deque::del() {
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

void Deque::update_last_crit() {
	Node* curr{m_start};

	while(curr -> next && curr -> next -> patient.is_in_critical_condition()) {
		curr = curr -> next;
	}

	m_last_critical_patient = curr;
}

Deque::Deque() : m_length{0}, m_start{nullptr}, m_end{nullptr}, m_last_critical_patient{nullptr} {}

Deque::Deque(const std::initializer_list<const Patient>& init_list) : Deque{} {
	for(const Patient& curr : init_list) {
		push_back(curr);
	}

	update_last_crit();
}

Deque::~Deque() {
	del();
}

void Deque::push_front(const Patient& new_data) {
	m_start = new (std::nothrow) Node{new_data, m_start};
	m_length++;

	if(!m_start -> next) {
		m_end = m_start;
	} else {
		m_start -> next -> prev = m_start;
	}

	update_last_crit();
}

void Deque::pop_front() {
	if(!m_start) {
		return;
	}

	if(m_start != m_end) {
		m_start = m_start -> next;
		delete m_start -> prev;
		m_start -> prev = nullptr;

		update_last_crit();
	} else {
		delete m_start;
		m_start = m_end = nullptr;
	}

	m_length--;
}

void Deque::push_back(const Patient& new_data) {
	m_end = new (std::nothrow) Node{new_data, nullptr, m_end};
	m_length++;

	if(!m_end -> prev) {
		m_start = m_end;
	} else {
		m_end -> prev -> next = m_end;
	}
}

void Deque::pop_back() {
	if(!m_end) {
		return;
	}

	if(m_start != m_end) {
		m_end = m_end -> prev;
		delete m_end -> next;
		m_end -> next = nullptr;

		update_last_crit();
	} else {
		delete m_end;
		m_end = m_start = nullptr;
	}

	m_length--;
}

void Deque::push_emergency(const Patient& new_data) {
	if(!m_start || !m_last_critical_patient) {
		push_front(new_data);
	} else if (m_start) {
		m_last_critical_patient = new (std::nothrow) Node{new_data, m_last_critical_patient -> next, m_last_critical_patient};
		m_last_critical_patient -> prev -> next = m_last_critical_patient;
		m_last_critical_patient -> next -> prev = m_last_critical_patient;
		m_length++;

		if(m_last_critical_patient -> prev == m_end) {
			m_end = m_last_critical_patient;
		}

		if(m_last_critical_patient -> next == m_start) {
			m_start = m_last_critical_patient;
		}

		update_last_crit();
	}
}

const size_t Deque::length() const {
	return m_length;
}

bool Deque::empty() const {
	return m_length == 0;
}

const Patient& Deque::front() const {
	return m_start -> patient;
}

const Patient& Deque::back() const {
	return m_end -> patient;
}

std::ostream& operator<<(std::ostream& out, const Deque& _deque) {
	Deque::Node* curr{_deque.m_start};
	out << "$ ";

    while(curr) {
        out << "[" << curr -> patient << "]";

        if(curr -> next) {
            out << " <-> ";
        }

        curr = curr -> next;
    }

    out << "\n";
    return out;
}
