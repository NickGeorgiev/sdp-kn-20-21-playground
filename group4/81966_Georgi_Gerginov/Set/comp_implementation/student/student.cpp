#include "student.h"

Student::Student(const unsigned int& facnum) : m_facnum{facnum} {}

const short int Student::compareTo(Comparable* other) const {
    Student* pt_to_stu{dynamic_cast<Student*>(other)};

    if(m_facnum < pt_to_stu -> m_facnum) {
        return -1;
    } else if(m_facnum == pt_to_stu -> m_facnum) {
        return 0;
    }

    return 1;
}

const unsigned int Student::get_data() const {
    return m_facnum;
}