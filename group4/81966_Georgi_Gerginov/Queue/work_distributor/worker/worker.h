#ifndef WORKER_H
#define WORKER_H
#include <string>

class Worker {

	std::string m_name;

public:
	Worker(const std::string&);

	friend std::ostream& operator<<(std::ostream&, const Worker&);
};

std::ostream& operator<<(std::ostream&, const Worker&);

#endif
