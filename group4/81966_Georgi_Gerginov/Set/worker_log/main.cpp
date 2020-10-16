#include "log/log.h"
#include "set/set.h"

int main() {
	size_t num_of_logs;
	std::cout << "enter num of logs: ";
	std::cin >> num_of_logs;
	std::cin.ignore();

    Set worklog{num_of_logs};
	worklog.print_menu();

    return 0;
}