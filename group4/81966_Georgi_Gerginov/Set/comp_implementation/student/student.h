#ifndef STUDENT_H
#define STUDENT_H
#include "../comparable/comparable.h"

class Student : public Comparable {

    unsigned int m_facnum;

public:
    Student(const unsigned int&);

    const short int compareTo(Comparable*) const override;
    const unsigned int get_data() const override;
};
#endif