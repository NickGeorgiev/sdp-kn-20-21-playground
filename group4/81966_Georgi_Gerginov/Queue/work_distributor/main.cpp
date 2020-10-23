#include "../temp_implementation/queue/queue.cpp"
#include "task/task.h"
#include "worker/worker.h"
#include <vector>

int main() {
	Queue<const Task> task_sheet{{"build a wall"}, {"clean the rubble"}, {"mix cement"}, {"dig a hole"}};
	std::vector<Worker> worker_list{{"Vanio"}, {"Gosho"}, {"Kosta"}, {"Pesho"}, {"Filip"}};
	size_t counter{0};

	if(worker_list.size() >= task_sheet.get_length()) {
		while(!task_sheet.empty()) {
			std::cout << "$ " << worker_list[counter] << " has to " << task_sheet.first_data() << "\n";
			task_sheet.pop();
			counter++;
		}

		while(counter < worker_list.size()) {
			std::cout << "$ " << worker_list[counter] << " has no job\n";
			counter++;
		}
	} else {
		while(counter < worker_list.size()) {
			std::cout << "$ " << worker_list[counter] << " has to " << task_sheet.first_data() << "\n";
			task_sheet.pop();
			counter++;
		}

		std::cout << "\n$ Remaining tasks:\n" << task_sheet;
	}
}