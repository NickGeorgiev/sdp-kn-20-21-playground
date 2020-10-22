#ifndef _SLIST
#define _SLIST
#include <iostream>
using comparator = bool (*)(const int &, const int &);
// bool isTrue = [](const int &d1, const int &d2) = >
// {
//     return d1 < d2;
// }

class slist
{
private:
    struct skipBox
    {
        int data;
        skipBox *next;
        skipBox *skip;

        skipBox(const int &data, skipBox *next, skipBox *skip);
    };
    skipBox * first;
    int count;
    comparator c;
    skipBox *locate(const int &) const;
    void clear();
    void copy(const slist&);

public:
    slist(comparator);
    slist(const slist&);
    ~slist();
    bool member(const int &) const;
    size_t size() const;
    void optimise();
    void pushSorted(const int&);
    slist& operator=(const slist&);
    slist& operator+=(const int&);
    friend std::ostream& operator<<(std::ostream&, const slist&);
};

#endif