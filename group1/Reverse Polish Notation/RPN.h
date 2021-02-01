#ifndef RPN_H
#define RPN_H
#include <string>

class RPN
{
private:
    std::string input{};
    std::string output{};

    bool isDigit(const int& x) const;
    bool isOperator(const char& c) const;
    int preority(const char& c) const;
    int operate(const int& a, const int& b, const char& c) const;
    int toInt(const char& c) const;

public:
    RPN(const std::string& _input);

    void convert();
    int calculate() const;
};


#endif
