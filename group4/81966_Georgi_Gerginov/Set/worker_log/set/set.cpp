#include "set.h"

Set::Node::Node(const Log& _data, Node* _next = nullptr, Node* _prev = nullptr) : data{_data}, next{_next}, prev{_prev} {}

void Set::del() {
    while(m_start -> next) {
        m_start = m_start -> next;
        delete m_start -> prev;
    }

    delete m_start;
}

bool Set::is_unique(const Log& _data) const {
    Node* curr{m_start};

    while(curr) {
        if(curr -> data == _data) { 
            return false;
        }
        curr = curr -> next;
    }

    return true;
}

void Set::print_forward() const {
	Node* curr{m_start};

	while(curr) {
		std::cout << "$ [" << curr -> data << "]";

        if(curr -> next) {
            std::cout << "\n";
        }

        curr = curr -> next;
    }

    std::cout << "\n";
}

void Set::print_backward() const {
	Node* curr{m_end};

	while(curr) {
		std::cout << "$ [" << curr -> data << "]";

        if(curr -> prev) {
            std::cout << "\n";
        }

        curr = curr -> prev;
	}

	std::cout << "\n";
}

void Set::print_dates() const {
	Node* curr{m_start};

	while(curr) {
		std::cout << "$ [" << curr -> data.get_date() << "]";

        if(curr -> next) {
            std::cout << "\n";
        }

        curr = curr -> next;
    }

    std::cout << "\n";
}

Set::Set() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

Set::Set(const size_t& num_of_logs) : m_length{num_of_logs}, m_start{nullptr}, m_end{nullptr} {
	size_t log_counter{0};
	
	do {
		std::string date, time, description;

		std::cout << "\ndate " << log_counter << ": ";
		std::getline(std::cin, date);

		std::cout << "time " << log_counter << ": ";
		std::getline(std::cin, time);

		std::cout << "description " << log_counter << ": ";
		std::getline(std::cin, description);

		Log curr{date, time, description};
		if(is_unique(curr)) {
			push_back(curr);
			log_counter++;
		} else {
			std::cout << "\n$ error: element is not unique\n\n";
		}

	} while(log_counter < num_of_logs);
}

Set::Set(const std::initializer_list<const Log>& init_list) : Set{} {
	for(const Log& curr : init_list) {
		push_back(curr);
	}
}

Set::~Set() {
    del();
}

void Set::push_back(const Log& new_data) {
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

void Set::print_menu() const {
	char option;

	std::cout << "\n$ enter desired option:\n"
			  << "$  [1] - forward print\n"
			  << "$  [2] - backward print\n"
			  << "$  [3] - date print\n"
			  << "$  [q] - quit\n\n"
			  << ">> ";
	
	std::cin.get(option);
	std::cin.ignore();
	std::cout << "\n";

	switch(option) {
		case '1':
			print_forward();
			return;
		case '2':
			print_backward();
			return;
		case '3':
			print_dates();
			return;
		case 'q':
			return;
		default:
			std::cout << "\n$ error: invalid input\n\n";
			print_menu();
	}
}

std::ostream& operator<<(std::ostream& out, const Set& _set) {
	Set::Node* curr{_set.m_start};

    while(curr) {
        out << "$ [" << curr -> data << "]";

        if(curr -> next) {
            out << "\n";
        }

        curr = curr -> next;
    }

    out << "\n";
    return out;
}