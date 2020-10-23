#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>

class Engine {

	unsigned int m_serialnum;

public:
	Engine(const unsigned int&);

	const unsigned int get_data() const;
	bool operator<(const Engine&) const;
	bool operator==(const Engine&) const;

	friend std::ostream& operator<<(std::ostream&, const Engine&);
};


std::ostream& operator<<(std::ostream&, const Engine&);

#endif
