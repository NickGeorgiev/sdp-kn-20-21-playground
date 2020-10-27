#ifndef ENGINE_H
#define ENGINE_H
#include "../comparable/comparable.h"

class Engine : public Comparable {

	unsigned int m_serialnum;

public:
	Engine(const unsigned int&);

	const short int compareTo(Comparable*) const override;
	const unsigned int get_data() const override;
};
#endif
