#ifndef MATH_EXPRESSION_H
#define MATH_EXPRESSION_H
#include <iostream>
#include <string>
#include <vector>
#include <stack>

class MathExpr
{
private:
    std::vector<char> result{};
    std::stack<char> symbols{};

    bool is_operator(const char& c) const;

public:
    void parse(const std::string&);
    //double solve();

    std::vector<char> get_result () const;
};


#endif
