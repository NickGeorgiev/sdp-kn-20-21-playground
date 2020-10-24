#include "list.h"

List::Node::Node(Log* _data, Node* _next = nullptr, Node* _prev = nullptr) : data{_data}, next{_next}, prev{_prev} {}

void List::del() {
    while(m_start -> next) {
        m_start = m_start -> next;
        delete m_start -> prev;
    }

    delete m_start;
}

void List::print_forward() const {
	Node* curr{m_start};

	while(curr) {
		std::cout << "$ [" << *(curr -> data) << "]";

        if(curr -> next) {
            std::cout << "\n";
        }

        curr = curr -> next;
    }

    std::cout << "\n";
}

void List::print_backward() const {
	Node* curr{m_end};

	while(curr) {
		std::cout << "$ [" << *(curr -> data) << "]";

        if(curr -> prev) {
            std::cout << "\n";
        }

        curr = curr -> prev;
	}

	std::cout << "\n";
}

List::List() : m_length{0}, m_start{nullptr}, m_end{nullptr} {}

List::List(const size_t& num_of_logs) : m_length{num_of_logs}, m_start{nullptr}, m_end{nullptr} {
	size_t log_counter{0};
	
	do {
		std::string date, time, description;

		std::cout << "\ndate " << log_counter << ": ";
		std::getline(std::cin, date);

		std::cout << "time " << log_counter << ": ";
		std::getline(std::cin, time);

		std::cout << "description " << log_counter << ": ";
		std::getline(std::cin, description);

		push_back(new Log{date, time, description});
		log_counter++;
	} while(log_counter < num_of_logs);
}

List::List(const std::initializer_list<Log*>& init_list) : List{} {
	for(Log* curr : init_list) {
		push_back(curr);
	}
}

List::~List() {
    del();
}

void List::push_back(Log* new_data) {
    m_length++;
    m_end = new (std::nothrow) Node{new_data, nullptr, m_end};

    if(!m_end -> prev) {
        m_start = m_end;
    } else {
        m_end -> prev -> next = m_end;
    }
}

void List::pop_back() {
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

Set List::set_from_list() const {
	Set from_list;
	Node* curr{m_start};

	while(curr) {
		from_list.push(curr -> data);
		curr = curr -> next;
	}

	return from_list;
}

void List::print_menu() const {
	char option;

	std::cout << "\n$ enter desired option:\n"
			  << "$  [1] - forward print\n"
			  << "$  [2] - backward print\n"
			  << "$  [q] - quit\n\n"
			  << ">> ";
	
	std::cin.get(option);
	std::cin.ignore();
	std::cout << "\n";

	switch(option) {
		case '1':
			print_forward();
			print_menu();
			return;
		case '2':
			print_backward();
			print_menu();
			return;
		case 'q':
			return;
		default:
			std::cout << "\n$ error: invalid input\n\n";
			print_menu();
	}
}

std::ostream& operator<<(std::ostream& out, const List& _list) {
	List::Node* curr{_list.m_start};

    while(curr) {
        out << "$ [" << *(curr -> data) << "]";

        if(curr -> next) {
            out << "\n";
        }

        curr = curr -> next;
    }

    out << "\n";
    return out;
}
