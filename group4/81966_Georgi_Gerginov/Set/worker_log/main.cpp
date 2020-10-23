#include "set/set.h"
#include "list/list.h"

int main() {
	size_t num_of_logs;
	std::cout << "enter num of logs: ";
	std::cin >> num_of_logs;
	std::cin.ignore();

    List worklog{num_of_logs};
	worklog.print_menu();

	Set worklog_set{worklog.set_from_list()};
	std::cout << worklog_set;
	
    return 0;
}
