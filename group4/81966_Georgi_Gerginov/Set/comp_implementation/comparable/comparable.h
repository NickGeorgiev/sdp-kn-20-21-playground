#ifndef COMPARABLE_H
#define COMPARABLE_H

class Comparable {
public:
    virtual ~Comparable() = default;

    virtual const short int compareTo(Comparable*) const = 0;
    virtual const unsigned int get_data() const = 0;
};
#endif
