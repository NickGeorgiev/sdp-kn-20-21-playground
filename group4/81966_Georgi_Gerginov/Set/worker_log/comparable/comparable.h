#ifndef COMPARABLE_H
#define COMPARABLE_H
#include <string>

class Comparable {
public:
    virtual ~Comparable() = default;

    virtual const short int compareTo(Comparable*) const = 0;
	virtual const std::string get_date() const = 0;
};
#endif
